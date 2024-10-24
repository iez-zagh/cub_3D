/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/24 13:27:25 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)]
	|| (data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)] == '1')
	)
		return (1);
	if (		
		(data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '1' &&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == '1'

		&&

		data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == '0'
		)
		||
		(
		data->map.map[(int)((y + 1) / TILE_SCALED)] //this here
		[(int)((x) / TILE_SCALED)] == '1' 
		&&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '1'

		// &&
		// data->map.map[(int)((y + 1) / TILE_SCALED)]
		// [(int)((x - 1) / TILE_SCALED)] == '0'

		//
		&&
		data->map.map[(int)((y + 1) / TILE_SCALED)] //this for the left corner
		[(int)((x - 1) / TILE_SCALED)] == '0'
		)
		)
			return (1);
	return (0);
}	
int	checking_collision3(t_data *data, int x, int y)
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

	x = (x / TILE) * TILE_SCALED;
	y = (y / TILE) * TILE_SCALED;
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
	float	dir_x;
	float	dir_y;
	int		xintercept = 0;
	int		yintercept = 0;
	int		xstep = 0;
	int		ystep = 0;
	float	i;
	
	bool	found_horz_hit = false;
	float	hit_x = 0;
	float	hit_y = 0;

	// find the line for the first horizontal in grid intersection
	yintercept = floor(y / TILE) * TILE;

	if (!(data->cast_angle > 0 && data->cast_angle < M_PI)) //this is to check where the player facing
		yintercept += TILE;

	xintercept = x + ((yintercept - y)  / tan(data->cast_angle));

	// calculate the step for x and y

	ystep = TILE;

	if (data->cast_angle > 0 && data->cast_angle < M_PI)
		ystep *= -1;
	
	xstep = TILE / tan(data->cast_angle);
	// printf("%f]]\n%f]]\n", x / TILE, y / TILE);
	// printf("%d]]\n%d]]\n", xintercept, yintercept);

	if (!((data->cast_angle < M_PI / 2 || data->cast_angle > 1.5 * M_PI)) && xstep > 0)
		xstep *= -1;

	if ((data->cast_angle < M_PI / 2 || data->cast_angle > 1.5 * M_PI) && xstep < 0)
		xstep *= -1;

	int	nexthorztouchX = xintercept;
	int	nexthorztouchY = yintercept;

	// printf("%f]]\n%f]]\n", x, y);
	// exit(0);
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
		nexthorztouchY--;


	
	//increment xstep and y step
	while (nexthorztouchX >= 0 && nexthorztouchX <= WIDTH && nexthorztouchY >= 0 && nexthorztouchY <= HEIGHT) //more good to check the limits of the map
	{
		if (checking_collision3(data, nexthorztouchX, nexthorztouchY)) //found a wall hit
		{
			found_horz_hit = true;
			hit_x = nexthorztouchX;
			hit_y = nexthorztouchY;
			break ;
		}
		else
		{
			nexthorztouchX += xstep;
			nexthorztouchY += ystep;
		}
	}

	
	// vertical intersection
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////
	yintercept = floor(y / TILE) * TILE;

	if (!(data->cast_angle > 0 && data->cast_angle < M_PI)) //this is to check where the player facing
		yintercept += TILE;

	xintercept = x + ((yintercept - y)  / tan(data->cast_angle));

	// calculate the step for x and y

	ystep = TILE;

	if (data->cast_angle > 0 && data->cast_angle < M_PI)
		ystep *= -1;
	
	xstep = TILE / tan(data->cast_angle);
	// printf("%f]]\n%f]]\n", x / TILE, y / TILE);
	// printf("%d]]\n%d]]\n", xintercept, yintercept);

	if (!((data->cast_angle < M_PI / 2 || data->cast_angle > 1.5 * M_PI)) && xstep > 0)
		xstep *= -1;

	if ((data->cast_angle < M_PI / 2 || data->cast_angle > 1.5 * M_PI) && xstep < 0)
		xstep *= -1;

	int	nexthorztouchX = xintercept;
	int	nexthorztouchY = yintercept;

	// printf("%f]]\n%f]]\n", x, y);
	// exit(0);
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
		nexthorztouchY--;

	bool	found_horz_hit = false;
	float	hit_x = 0.0;
	float	hit_y = 0.0;

	
	//increment xstep and y step
	while (nexthorztouchX >= 0 && nexthorztouchX <= WIDTH && nexthorztouchY >= 0 && nexthorztouchY <= HEIGHT) //more good to check the limits of the map
	{
		if (checking_collision3(data, nexthorztouchX, nexthorztouchY)) //found a wall hit
		{
			found_horz_hit = true;
			hit_x = nexthorztouchX;
			hit_y = nexthorztouchY;
			break ;
		}
		else
		{
			nexthorztouchX += xstep;
			nexthorztouchY += ystep;
		}
	}
		
	dir_x = cos(data->cast_angle);
	dir_y = sin(data->cast_angle);

 	i = 0.0;
 	while (i < 2000)
 	{
		if (checking_collision3(data, x + (dir_x * i), y + (dir_y * i)))
		{
			return i;
			// return fabsf(data->player->sqaure_x - x + (dir_x * i));
		}
		i++;
	}
	return (0);
}

float cast_ray(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;
	
	dir_x = cos(data->cast_angle);
	dir_y = sin(data->cast_angle);

 	i = 0.0;
 	while (i < 2000)
 	{
		if (checking_collision3(data, x + (dir_x * i), y + (dir_y * i)))
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
