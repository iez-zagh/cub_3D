/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/22 12:26:46 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' 
	// || (x / TILE >= 12 || y / TILE >= 5)
	)
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
		// data->map[(int)((y + 1) / TILE)]
		// [(int)((x - 1) / TILE)] == '0'

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
	// return ;
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
	return ;
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
	// return ;
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
	// return ;
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->cast_angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->cast_angle);
	i = 0;
	while (i < 300)
	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), RED);
		i++;
	}
}

void	remove_direction3(t_data *data, float x, float y)
{
	// return ;
	float dir_x, dir_y;
	int	i;

	i = RADIUS;
	dir_x = cos(data->cast_angle);
	dir_y = sin(data->cast_angle);
	while (i < 300)
	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), WHITE);
		i++;
	}
}

void draw_minimap2(t_data *data, mlx_image_t *image)
{
	float	x1;
	float	y1;
	int		color;
	float	k;

	y1 = (data->player->sqaure_y / TILE) - 3;
	k = (data->player->sqaure_x / TILE) - 3;
	// printf("%f]]\n",data->player->sqaure_y / TILE);
	// y1 = data->player->y - 3;
	// k = data->player->x - 3;
	if (data->player->sqaure_x / TILE + 3 > 30)
	{			
		data->player->map_x += TILE;
		k = data->player->sqaure_x / TILE - 3 - (30 - data->player->x) + 1;
	}
	if (data->player->sqaure_y / TILE + 3 > 15)
	{
		data->player->map_y += TILE;
		y1 = data->player->sqaure_y / TILE - 3 - (15 - data->player->sqaure_y / TILE) + 1;
	}

	if (data->player->sqaure_y / TILE - 3 < 0)
	{
		data->player->map_y += (data->player->sqaure_y / TILE - 3) * TILE;
		y1 = 0;
	}

	if (data->player->x - 3 < 0)
	{
		data->player->map_x += (data->player->x - 3) * TILE;
		k = 0;
	}
	for (float y = 0; y < 6; y++)
	{
		int x1 = k;
		for (float x = 0; x < 6; x++)
		{
			if (data->map[(int)y1][(int)x1] == '1')
				color = BLACK;
			else
				color = WHITE;
			float draw_x = x * TILE;
			float draw_y = y * TILE;
			for (int dy = 0; dy < TILE; dy++)
			{
				for (int dx = 0; dx < TILE; dx++)
					mlx_put_pixel(image, draw_x + dx, draw_y + dy, color);
			}
			x1++;
		}
		y1++;
	}
}
