	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/06 12:05:26 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	draw_player(t_data *data, float draw_x, float draw_y, int color)
{
	float	x;
	float	y;

	y = -RADIUS;
	while (y < RADIUS)
	{
		x = -RADIUS;  
		while (x < RADIUS)
		{
			if (pow(x, 2) + pow(y, 2) < pow(RADIUS, 2))
				mlx_put_pixel(data->img, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_player2(t_data *data, float draw_x, float draw_y, int color)
{
	float	x;
	float	y;
	draw_x = (data->player->sqaure_x / TILE) * TILE_SCALED;
	draw_y = (data->player->sqaure_y / TILE) * TILE_SCALED;

	y = -RADIUS;
	while (y < RADIUS)
	{
		x = -RADIUS;
		while (x < RADIUS)
		{
			if (pow(x, 2) + pow(y, 2) < pow(RADIUS, 2))
				mlx_put_pixel(data->img, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}


void	start_render(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	data->img = mlx_new_image(data->mlx, 336, 224);
	data->player_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player->sqaure_x = data->player->x * TILE;
	data->player->sqaure_y = data->player->y * TILE;
	data->player->sqaure_x += TILE / 2;
	data->player->sqaure_y += TILE / 2;
	draw_minimap(data);
	cast_rays(data);
	mlx_image_to_window(data->mlx, data->player_img, 0, 0);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	data->a_key = false;
	data->w_key = false;
	data->s_key = false;
	data->d_key = false;
	mlx_key_hook(data->mlx, check_keys, data);
	mlx_loop_hook(data->mlx, my_key_hook, data);
	mlx_loop(data->mlx);
}
	
void	w_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->w_key = 1;
	if (key.action == MLX_RELEASE)
		data->w_key = 0;
}

void	a_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->a_key = 1;
	else if (key.action == MLX_RELEASE)
		data->a_key = 0;
}

void	d_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->d_key = 1;
	else if (key.action == MLX_RELEASE)
		data->d_key = 0;
}

void	s_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->s_key = 1;
	else if (key.action == MLX_RELEASE)
		data->s_key = 0;
}

void	check_keys(mlx_key_data_t key, void *data)
{
	data = (t_data *)data;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		w_key(key, data);
	if (key.key == MLX_KEY_A)
		a_key(key, data);
	if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		s_key(key, data);
	if (key.key == MLX_KEY_D)
		d_key(key, data);
	if (key.key == MLX_KEY_ESCAPE)
	{
		//needs to release resources
		write(1, "WINDOW CLOSED\n", 14);
		exit(0);
	}
}
