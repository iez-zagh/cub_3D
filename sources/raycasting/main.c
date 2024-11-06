/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/06 00:54:00 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_color(t_data *data, int x, int y)
{
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '1')
		return (BLACK);
	if ((data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '0')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'W')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'S')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'N')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'E'))
		return (WHITE);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '2')
		return (GRAY);
	return (WHITE);
}

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

void	f(void)
{
	system("leaks cub3d");
}
int	main(int ac, char **av)
{
	atexit(f);
	t_data		data;
	int			stat;
	t_player	player;
	char		*map;

	map = NULL;
	if (ac != 2)
		return (how_2_use(), 1);
	data.player = &player;
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (stat);
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;
	start_render(&data);
	return (0);
}
