/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/05 18:14:25 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 960, 480);
}

void	draw_player(t_data *data, int draw_x, int draw_y, int color)
{
	int	r;
	int	x;
	int	y;

	r = 4;
	y = -r;
	while (y < r)
	{
		x = -r;
		while (x < r)
		{
			if (pow(x, 2) + pow(y, 2) < pow(r, 2))
				mlx_put_pixel(data->img, draw_x + x + 16 , 16 + draw_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player2(t_data *data, int draw_x, int draw_y, int color)
{
	int	r;
	int	x;
	int	y;

	r = 4;
	y = -r;
	while (y < r)
	{
		x = -r;
		while (x < r)
		{
			if (pow(x, 2) + pow(y, 2) < pow(r, 2))
				mlx_put_pixel(data->img, draw_x + x + 16, draw_y + y + 16, color);
			x++;
		}
		y++;
	}
}

void draw_minimap(t_data *data)
{
	int			x;
	int			y;
	int			color;
	t_player	*player;

	player = malloc(sizeof(t_player));
	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 30; x++)
		{
			if (data->map[y][x] == '1')
				color = BLACK;
			else
				color = WHITE;
			int draw_x = x * TILE;
			int draw_y = y * TILE;
			for (int dy = 0; dy < TILE; dy++)
			{
				for (int dx = 0; dx < TILE; dx++)
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
			}
			if (data->map[y][x] == 'W')
			{
				player->player_x = x;
				player->player_y = y;
				player->sqaure_x = draw_x;
				player->sqaure_y = draw_y;
				data->player = player;
				draw_player(data, draw_x, draw_y, RED);
			}
		}
	}
}

void	start_render(t_data *data)
{
	data->mlx = mlx_init(960, 480, "cub3d", 1);
	render(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->img, 0 , 0);
	mlx_key_hook(data->mlx, &my_key_hook, data);
	// mlx_do_key_autorepeaton(data->mlx);
	mlx_loop(data->mlx);
}
