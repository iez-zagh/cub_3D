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

#include "cub3d.h"

void	draw_player(t_data *data, float draw_x, float draw_y, int color)
{
	return ;
	float	x;
	float	y;

	y = -RADIUS;
	draw_x /= TILE;
	draw_y /= TILE;
	draw_x *= TILE_SCALED;
	draw_y *= TILE_SCALED;
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

void	draw_player2(t_data *data, float draw_x, float draw_y, int color, mlx_image_t *img)
{
	float	r;
	float	x;
	float	y;

	r = RADIUS;
	y = -r;
	while (y < r)
	{
		x = -r;
		while (x < r)
		{
			if (pow(x, 2) + pow(y, 2) < pow(r, 2))
				mlx_put_pixel(img, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}

void draw_minimap(t_data *data)
{
	return ;
	float	x;
	float	y;
	int		color;

	for (y = 0; y < data->rows_n; y++)
	{
		for (x = 0; x < data->clmn_n; x++)
		{
			if (data->map.map[(int)y][(int)x] == '1')
				color = BLACK;
			else
				color = WHITE;
			float draw_x = x * TILE_SCALED;
			float draw_y = y * TILE_SCALED;
			for (int dy = 0; dy < TILE_SCALED; dy++)
			{
				for (int dx = 0; dx < TILE_SCALED; dx++)
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
			}
		}
	}
}

void	start_render(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 1);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);

	data->player->sqaure_x = data->player->x * TILE;
	data->player->sqaure_y = data->player->y * TILE;
	draw_minimap(data);
	data->player->angle = 180 * (M_PI / 180);
	data->player->sqaure_x += 16.0;
	data->player->sqaure_y += 16.0;
	draw_player(data, data->player->sqaure_x, data->player->sqaure_y, RED);
	cast_rays(data);
	draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);

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
	if (key.key == MLX_KEY_W)
		w_key(key, data);
	if (key.key == MLX_KEY_A)
		a_key(key, data);
	if (key.key == MLX_KEY_S)
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



// for (float y = 0; y < 6; y++)
// {
// 	{
// 		int x1 = k;
// 		for (float x = 0; x < 6; x++)
// 		{
// 			if (data->map.map[(int)y1][(int)x1] == '1')
// 				color = BLACK;
// 			else
// 				color = WHITE;
// 			float draw_x = x * TILE;
// 			float draw_y = y * TILE;
// 			for (int dy = 0; dy < TILE; dy++)
// 			{
// 				for (int dx = 0; dx < TILE; dx++)
// 					mlx_put_pixel(image, draw_x + dx, draw_y + dy, color);
// 			}
// 			x1++;
// 		}
// 		y1++;
// 	}
// }