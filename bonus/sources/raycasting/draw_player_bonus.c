/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:38:05 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:32:26 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	convert_textures(t_data *data)
{
	data->tex.i_north = mlx_texture_to_image(data->mlx, data->tex.north);
	if (!data->tex.i_north)
		return (-18);
	data->tex.i_south = mlx_texture_to_image(data->mlx, data->tex.south);
	if (!data->tex.i_south)
		return (delete_images(data, 0), delete_texture(data, 4), -18);
	data->tex.i_west = mlx_texture_to_image(data->mlx, data->tex.west);
	if (!data->tex.i_west)
		return (delete_images(data, 1), delete_texture(data, 4), -18);
	data->tex.i_east = mlx_texture_to_image(data->mlx, data->tex.east);
	if (!data->tex.i_east)
		return (delete_images(data, 2), delete_texture(data, 4), -18);
	data->tex.i_door = mlx_texture_to_image(data->mlx, data->tex.door);
	if (!data->tex.i_door)
		return (delete_images(data, 3), delete_texture(data, 4), -18);
	return (delete_texture(data, 4), 0);
}

void	sub_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->sub_key = 1;
	else if (key.action == MLX_RELEASE)
		data->sub_key = 0;
}

void	add_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->add_key = 1;
	else if (key.action == MLX_RELEASE)
		data->add_key = 0;
}

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
			if (x * x + y * y < RADIUS * RADIUS)
				mlx_put_pixel(data->img, draw_x + x, draw_y + y, color);
			x++;
		}
		y++;
	}
}
