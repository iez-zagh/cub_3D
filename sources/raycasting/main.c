/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/31 15:20:36 by iez-zagh         ###   ########.fr       */
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

void draw_minimap(t_data *data)
{
	float	x1;
	float	y1;
	int		color;
	int		x;
	int		y;
	int		h_x;
	int		h_y;
	int 	new_x;
	int 	new_y;

	new_x = 6 * TILE_SCALED;
	new_y = 4 * TILE_SCALED;
	h_x = 6 * TILE_SCALED;
	h_y = 4 * TILE_SCALED;
	x1 = (data->player->sqaure_x / TILE) * TILE_SCALED;
	y1 = (data->player->sqaure_y / TILE) * TILE_SCALED;
	int i = y1 - h_y;
	int u = x1 - h_x;
	y = 0;
	// if (i < 0)
	// {
	// 	h_y += (i * -1);
	// 	i = 0;
	// 	new_y += (y1 - (new_y));
	// }
	// if (u < 0)
	// {
	// 	h_x += u * -1;
	// 	u = 0;
	// 	new_x += (x1 - new_x);
	// }
	while (i <= y1 + h_y)
	{
		int j = u;
		x = 0;
		while (j <= x1 + h_x)
		{
			if (!(x / TILE_SCALED > data->clmn_n || x /TILE_SCALED < 0 || y / TILE_SCALED > data->rows_n || y / TILE_SCALED < 0))
			{
				color = get_color(data, j, i);
				mlx_put_pixel(data->img, x, y, color);
			}
			j++;
			x++;
		}
		y++;
		i++;
	}
	draw_player(data, new_x, new_y, RED);
	draw_direction(data, new_x, new_y);
}

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

int	main(int ac, char **av)
{
	t_data	data;
	int		stat;
	t_player player;

	char	*map = NULL;
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
