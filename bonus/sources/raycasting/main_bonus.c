/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/17 02:18:27 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_color(t_data *data, int x, int y)
{
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '1')
		return (BLACK);
	if ((data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '0')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'W')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'S')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'N')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'E'))
		return (GRAY);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '2')
		return (SHAPE);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'D')
		return (RED);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'C')
		return (GREEN);
	return (WHITE);
}

void	draw_minimap2(t_data *data, int i, int u)
{
	int	y;
	int	x;
	int	j;

	y = 0;
	while (i <= (data->player->sqaure_y / TILE) * TILE_SCALED + 4 * TILE_SCALED)
	{
		j = u;
		x = 0;
		while (j <= (data->player->sqaure_x / TILE)
			* TILE_SCALED + 6 * TILE_SCALED)
		{
			if (!(x / TILE_SCALED > data->clmn_n || x / TILE_SCALED < 0
					|| y / TILE_SCALED > data->rows_n || y / TILE_SCALED < 0))
				mlx_put_pixel(data->img, x, y, get_color(data, j, i));
			j++;
			x++;
		}
		y++;
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	draw_minimap2(data, (data->player->sqaure_y / TILE) * TILE_SCALED - 4
		* TILE_SCALED, (data->player->sqaure_x / TILE)
		* TILE_SCALED - 6 * TILE_SCALED);
	draw_player(data, 6 * TILE_SCALED, 4 * TILE_SCALED, YELLOW);
	draw_direction(data, 6 * TILE_SCALED, 4 * TILE_SCALED);
}

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

void	f(void)
{
	system("leaks cub3D_bonus");
}

void	free_All(t_data *data)
{
	free_frames(data, 7, 0);
	free_frames(data, 7, 1);
	ft_free_par(data->map.map);
	free_leaks(&data->map, 4);
	delete_images(data, 5);
}

int	main(int ac, char **av)
{
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
		return (ft_free_par(data.map.map), stat);
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;

	if (frames_loading(&data))
		return (ft_free_par(data.map.map), -1);
	start_render(&data);
	free_All(&data);
	return (0);
}
