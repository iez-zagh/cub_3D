/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/10 19:19:38 by iez-zagh         ###   ########.fr       */
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

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	for (float i = 0; i < 24; i++)
	{
		// for (float j=0;i < 2;j++) //remember this in morning
		// {
			
		if (!checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		// }
	}
}

void	remove_direction(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	// Calculate the direction vector based on the angle
	dir_x = cos(data->player->old_angle);
	dir_y = sin(data->player->old_angle);

	for (float i = 4; i < 24; i++) // Ensure the entire line is cleared
	{
		if (!checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), WHITE);
	}
}
 
void	remove_direction2(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	// Calculate the direction vector based on the angle
	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);

	for (float i = RADIUS ; i < 24; i++) // Ensure the entire line is cleared
	{
		if (!checking_collision2(data, x + dir_x * i, y + dir_y * i))
			mlx_put_pixel(data->img, x + dir_x * i, y + dir_y * i, WHITE);
	}
}
