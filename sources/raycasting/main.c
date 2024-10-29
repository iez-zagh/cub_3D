	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/21 11:09:24 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_minimap(t_data *data)
{
	float	x1;
	float	y1;
	int		color;
	int		x;
	int		y;
	int	h_x;
	int	h_y;
	int new_x;
	int new_y;

	new_x = 6 * TILE_SCALED;
	new_y = 4 * TILE_SCALED;
	h_x = 6 * TILE_SCALED;
	h_y = 4 * TILE_SCALED;
	x1 = (data->player->sqaure_x / TILE) * TILE_SCALED;
	y1 = (data->player->sqaure_y / TILE) * TILE_SCALED;
	int i = y1 - h_y;
	int u = x1 - h_x;
	y = 0;
	if (i < 0)
	{
		h_y += (i * -1);
		i = 0;
		new_y += (y1 - (new_y));
	}
	if (u < 0)
	{
		h_x += u * -1;
		u = 0;
		new_x += (x1 - new_x);
	}
	while (i <= y1 + h_y)
	{
		int j = u;
		x = 0;
		while (j <= x1 + h_x)
		{
			if (data->map.map[i / TILE_SCALED][j / TILE_SCALED] == '1')
				color = BLACK;
			else if (data->map.map[i / TILE_SCALED][j / TILE_SCALED] == '0')
				color = WHITE;
			// else
			// 	color = GRAY;
			mlx_put_pixel(data->img, x, y, color);
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
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (stat);
	for (float i = 0;i < 15;i++)
	{
		for (float j = 0;j < 30;j++)
		{
			if (data.map.map[(int)i][(int)j] == 'W')
			{
				player.x = j;
				player.y = i;
				break ;
			}	
		}
	}
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;
	data.player = &player;
	start_render(&data);
	return (0);
}
