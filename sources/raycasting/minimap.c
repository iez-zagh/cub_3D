/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/24 17:47:32 by iez-zagh         ###   ########.fr       */
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

float	distance_calcul(float x, float y, float x1, float y1)
{
	return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
}

float cast_lines(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float		xintercept = 0;
	float		yintercept = 0;
	float		xstep = 0;
	float		ystep = 0;
	float	i;
	
	bool	found_horz_hit = false;
	float	hor_hit_x = 0;
	float	hor_hit_y = 0;

	// find the line for the first horizontal in grid intersection
	yintercept = floor(y / TILE) * TILE;

	if (data->cast_angle > 0 && data->cast_angle <= M_PI) //this is to check where the player facing down
		yintercept += TILE;

	xintercept = x + ((yintercept - y)  / tan(data->cast_angle));

	// calculate the step for x and y

	ystep = TILE;

	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
		ystep *= -1;
	
	xstep = TILE / tan(data->cast_angle);
	// printf("%f]]\n%f]]\n", x / TILE, y / TILE);
	// printf("%d]]\n%d]]\n", xintercept, yintercept);

	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI) && xstep > 0)
		xstep *= -1;

	if ((data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI) && xstep < 0)
		xstep *= -1;

	float	nexthorztouchX = xintercept;
	float	nexthorztouchY = yintercept;

	// printf("%f]]\n%f]]\n", x, y);
	// exit(0);
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
		nexthorztouchY--;


	
	//increment xstep and y step
	while (nexthorztouchX >= 0 && nexthorztouchX < data->clmn_n * TILE && nexthorztouchY >= 0 && nexthorztouchY < data->rows_n * TILE) //more good to check the limits of the map
	{
		if (checking_collision3(data, nexthorztouchX, nexthorztouchY)) //found a wall hit
		{
			found_horz_hit = true;
			hor_hit_x = nexthorztouchX;
			hor_hit_y = nexthorztouchY;
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
	
	float	ver_hit_x = 0.0;
	float	ver_hit_y = 0.0;
	bool	foundverticalhit = false;

	xintercept = floor(x / TILE) * TILE;
	// looking for x the closest vertical intersection
	if ((data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI)) //  the player facing up
		xintercept += TILE;

	// looking for y the closest vertical intersection
	yintercept = y + ((xintercept - x)  * tan(data->cast_angle));

	// calculate the step for x and y

	xstep = TILE;

	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		xstep *= -1;
	
	ystep = TILE * tan(data->cast_angle);

	if (!(data->cast_angle > 0 && data->cast_angle < M_PI) && ystep > 0)
		ystep *= -1;
	if ((data->cast_angle > 0 && data->cast_angle < M_PI) && xstep < 0)
		ystep *= -1;

	float	nextvertouchX = xintercept;
	float	nextvertouchY = yintercept;
	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		nextvertouchX--;
	//increment xstep and y step
	while (nextvertouchX >= 0 && nextvertouchX < data->clmn_n * TILE && nextvertouchY >= 0 && nextvertouchY < data->rows_n * TILE) //more good to check the limits of the map
	{
		if (checking_collision3(data, nextvertouchX, nextvertouchY)) //found a wall hit
		{
			foundverticalhit = true;
			ver_hit_x = nextvertouchX;
			ver_hit_y = nextvertouchY;
			break ;
		}
		else
		{
			nextvertouchX += xstep;
			nextvertouchY += ystep;
		}
	}
	//////////////////////////////////////////////////////////////
	////////////////////calculate the closeset distance///////////
	//////////////////////////////////////////////////////////////
	float horzdis = 0;
	if (found_horz_hit)
	{
		horzdis = distance_calcul(x, y, hor_hit_x, hor_hit_y);
	}
	float verdis = 0;
	if (foundverticalhit)
	{
		verdis = distance_calcul(x, y, ver_hit_x, ver_hit_y);
	}
	if (horzdis > verdis)
	 {
		// puts("here");
		// printf ("%f]]]\n", distance_calcul(x, y, ver_hit_x, ver_hit_y));
		return (distance_calcul(x, y, ver_hit_x, ver_hit_y));
	}
	else
		// printf ("%f]]\n", distance_calcul(x, y, hor_hit_x, hor_hit_y));
		return (distance_calcul(x, y, hor_hit_x, hor_hit_y));
	// dir_x = cos(data->cast_angle);
	// dir_y = sin(data->cast_angle);

 	// i = 0.0;
 	// while (i < 2000)
 	// {
	// 	if (checking_collision3(data, x + (dir_x * i), y + (dir_y * i)))
	// 	{
	// 		printf("%f]\n", i);exit (0);
	// 		return i;
	// 		// return fabsf(data->player->sqaure_x - x + (dir_x * i));
	// 	}
	// 	i++;
	// }
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
