/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/07 12:15:21 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1')
		return (1);
	return (0);
}

void	draw_direction(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	// Calculate the direction vector based on the angle
	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);

	for (int i = RADIUS; i < 24; i++)
	{
		float draw_x = x + dir_x * i;
		float draw_y = y + dir_y * i;
		if (!checking_collision2(data, draw_x, draw_y))
			mlx_put_pixel(data->img, draw_x, draw_y, RED);
	}
}

void	remove_direction(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	// Calculate the direction vector based on the angle
	dir_x = cos(data->player->old_angle);
	dir_y = sin(data->player->old_angle);

	for (int i = RADIUS + 1; i < 24; i++) // Ensure the entire line is cleared
	{
		float draw_x = x + dir_x * i;
		float draw_y = y + dir_y * i;
		
		if (!checking_collision2(data, draw_x, draw_y))
			mlx_put_pixel(data->img, draw_x, draw_y, WHITE);
	}
}

void	remove_direction2(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	// Calculate the direction vector based on the angle
	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);

	for (int i = 3; i < 24; i++) // Ensure the entire line is cleared
	{
		float draw_x = x + dir_x * i;
		float draw_y = y + dir_y * i;
		
		if (!checking_collision2(data, draw_x, draw_y))
		mlx_put_pixel(data->img, draw_x, draw_y, WHITE);
	}
}
