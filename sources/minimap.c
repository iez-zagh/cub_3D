/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/23 09:21:19 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE)][(int)(x / TILE)]
	|| (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == '1')
	)
		return (1);
	if (		
		(data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1'

		&&

		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0'
		)
		||
		(
		data->map.map[(int)((y + 1) / TILE)] //this here
		[(int)((x) / TILE)] == '1' 
		&&
		data->map.map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == '1'

		// &&
		// data->map.map[(int)((y + 1) / TILE)]
		// [(int)((x - 1) / TILE)] == '0'

		//
		&&
		data->map.map[(int)((y + 1) / TILE)] //this for the left corner
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

	x /= TILE;
	y /= TILE;
	x *= TILE_SCALED;
	y *= TILE_SCALED;
	dir_x = cos(data->player->angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->player->angle);
	i = 0;
	while (i < 26)
	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i++;
	}
}

float cast_lines(t_data *data, float x, float y)
{
    float dir_x;
    float dir_y;
    float	 i;

    dir_x = cos(data->cast_angle);
    dir_y = sin(data->cast_angle);

 	// Horizontal raycasting
 	i = 0.0;
 	while (i < 2000)
 	{
		if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
		{
			return i;
			// return fabsf(data->player->sqaure_x - x + (dir_x * i));
		}
		i++;
	}
	return (0);
}

void draw_minimap2(t_data *data, mlx_image_t *image)
{
	float	x1;
	float	y1;
	int		color;
	float	k;

	float	x2 = data->player->sqaure_x - 3 * TILE;
	float	y2 = data->player->sqaure_y - 3 * TILE;
	for (float y = 0; y < 6; y++)
	{
		for (float x = 0; x < 6; x++)
		{
			int color = WHITE;
			if (data->map.map[(int)data->player->sqaure_y / TILE][(int)data->player->sqaure_x / TILE] == '1')
				color = BLACK;
				//check map with the sqaure
			for (float y1 = 0;y1 < TILE;y1++)
			{
				for (float x1 = 0;x1 < TILE;x1++)
				{
					puts("hello");
					// mlx_put_pixel(image, x1 + );
				}
			}
		}
		
	}
}
