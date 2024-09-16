/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/16 14:24:42 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)(x / TILE)] == '1')
		return (1);
	if (		
		(data->map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1'

		&&

		data->map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0'
		)
		||
		(
		data->map[(int)((y + 1) / TILE)] //this here
		[(int)((x) / TILE)] == '1' 
		&&
		data->map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == '1'
		// &&
		// data->map[(int)((y) / TILE)]
		// [(int)((x + 1) / TILE)] == '0'

		//
		&&
		data->map[(int)((y + 1) / TILE)] //this for the left corner
		[(int)((x - 1) / TILE)] == '0'
		)
		)
			return (1);
	return (0);
}	

void	draw_direction(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->player->angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->player->angle);
	i = 0;
	while (i < 26)
	{
		if (!checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i++;
	}
}

void	remove_direction(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->player->old_angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->player->old_angle); // i did not devide it by the radius because i want to start from the player positio
	i = RADIUS;
	while (i < 26)
	{
		if (!checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), WHITE);
		i++;
	}
}

void	remove_direction2(t_data *data, float x, float y)
{
	float dir_x, dir_y;

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	for (float i = RADIUS ; i < 26; i++) // Ensure the entire line is cleared
	{
		if (!checking_collision2(data, x + dir_x * i, y + dir_y * i))
			mlx_put_pixel(data->img, x + dir_x * i, y + dir_y * i, WHITE);
	}
}

void	cast_lines(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->cast_angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->cast_angle);
	i = 0;
	while (i < 1000)
	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), RED);
		i++;
	}
}

void	remove_direction3(t_data *data, float x, float y)
{
	float dir_x, dir_y;
	int	i;

	i = RADIUS;
	dir_x = cos(data->cast_angle);
	dir_y = sin(data->cast_angle);
	while (i < 1000)
	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), WHITE);
		i++;
	}
}
