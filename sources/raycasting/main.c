/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 23:44:33 by zmaghdao         ###   ########.fr       */
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

void	handle_angle(t_data *data)
{
	data->cast_angle = remainder(data->cast_angle, 2 * M_PI);
	if (data->cast_angle < 0)
		data->cast_angle = 2 * M_PI + data->cast_angle;
}

void	free_all(t_data	*data)
{
	ft_free_par(data->map.map);
	if (data->mlx)
		delete_images(data, 4);
}

void	f(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_data		data;
	int			stat;
	t_player	player;
	char		*map;

	atexit(f);
	map = NULL;
	if (ac != 2)
		return (printf("Usage: ./cub3D ./path_to_map\n"), 1);
	data.player = &player;
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (1);
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;
	data.player->sqaure_x += TILE / 2;
	data.player->sqaure_y += TILE / 2;
	start_render(&data);
	free_all(&data);
	return (0);
}
