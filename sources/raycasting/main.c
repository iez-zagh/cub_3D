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

void draw_minimap2(t_data *data)
{
	float	x1;
	float	y1;
	int		color;
	float	k;

	x1 = (data->player->sqaure_x / TILE);
	y1 = (data->player->sqaure_y / TILE);

	int y2=0;
	for (float y = y1 - 4; y < y1 + 4; y++)
	{
		int x2= 0;
		for (float x = x1 - 6; x < x1 + 6; x++)
		{
			if (data->map.map[(int)y][(int)x] == '1')
				color = BLACK;
			else
				color = WHITE;
			float draw_x = x2 * TILE_SCALED;
			float draw_y = y2 * TILE_SCALED;
			for (int dy = 0; dy < TILE_SCALED; dy++)
			{
				for (int dx = 0; dx < TILE_SCALED; dx++)
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
			}
			x2++;
		}
		y2++;
	}
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
		for (float j=0;j<30;j++)
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
