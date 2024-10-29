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

	y1 = data->player->y - 3;
	k = data->player->x - 4;
	printf("%f]]\n%f]]\n", y1, k);
	if (data->player->x + 4 > 30)
	{
		puts("hello");
		k = data->player->x - 4 - (30 - data->player->x);
	}
	if (data->player->y + 3 > 15)
	{
		puts("here");
		y1 = data->player->y - 3 - (15 - data->player->y) + 1;
	}
	printf("%f]]\n%f]]\n", y1, k);
	for (float y = 0; y < 6; y++)
	{
		int x1 = k;
		for (float x = 0; x < 8; x++)
		{
			// printf("%c", data->map[(int)y1][(int)x1]);
			if (data->map.map[(int)y1][(int)x1] == '1')
				color = BLACK;
			else
				color = WHITE;
			float draw_x = x * TILE;
			float draw_y = y * TILE;
			for (int dy = 0; dy < TILE; dy++)
			{
				for (int dx = 0; dx < TILE; dx++)
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
			}
			x1++;
		}
		puts("");
		y1++;
	}
	// exit (0);
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
	start_render(&data);
	return (0);
}
