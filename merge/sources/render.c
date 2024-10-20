/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/18 05:19:16 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player(t_data *data, float draw_x, float draw_y, int color)
{
	float	x;
	float	y;

	data->player->sqaure_x = draw_x + 16;
	data->player->sqaure_y = draw_y + 16;
	y = -RADIUS;
	while (y < RADIUS)
	{
		x = -RADIUS;
		while (x < RADIUS)
		{
			if (pow(x, 2) + pow(y, 2) < pow(RADIUS, 2))
				mlx_put_pixel(data->img, draw_x + x + 16 , 16 + draw_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player2(t_data *data, float draw_x, float draw_y, int color)
{
	float	r;
	float	x;
	float	y;

	r = 4;
	y = -r;
	while (y < r)
	{
		x = -r;
		while (x < r)
		{
			if (pow(x, 2) + pow(y, 2) < pow(r, 2))
				mlx_put_pixel(data->img, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}

void draw_minimap(t_data *data)
{
	float	x;
	float	y;
	int		color;

	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 30; x++)
		{
			if (data->map[(int)y][(int)x] == '1')
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
		}
	}
}

void	start_render(t_data *data)
{
	data->mlx = mlx_init(960, 480, "cub3d", 1);
	data->img = mlx_new_image(data->mlx, 1920, 960);
	draw_minimap(data);
	draw_player(data, data->player->sqaure_x, data->player->sqaure_y, RED);
	data->player->angle = 0;
	data->cast_angle = data->player->angle;
	remove_rays(data);
	cast_rays(data);
	draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_loop_hook(data->mlx, &my_key_hook, data);
	mlx_loop(data->mlx);
}
