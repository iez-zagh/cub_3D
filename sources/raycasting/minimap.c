/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/31 14:57:52 by iez-zagh         ###   ########.fr       */
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


	dir_x = cos(data->player->angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->player->angle);
	i = 0.0 ;
	while (i < 20)
	{
		// if (checking_collision2(data, x + (dir_x * i), y + (dir_y * i)))
		// 	return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i += 0.02;
	}
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
}

float cast_ray(t_data *data, float x, float y)
{
	float	xintercept = 0.0;
	float	yintercept = 0.0;
	float	xstep = 0;
	float	ystep = 0;
	
	bool	found_horz_hit = false;
	float	hor_hit_x = 0;
	float	hor_hit_y = 0;

	// horz
	yintercept = floor(y / TILE) * TILE;
	if (data->cast_angle > 0 && data->cast_angle <= M_PI)
		yintercept += TILE;
	xintercept = x + ((yintercept - y) / tan(data->cast_angle));
	ystep = TILE;
	xstep = TILE / tan(data->cast_angle);
	float	nexthorztouchX = xintercept;
	float	nexthorztouchY = yintercept;
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
	{
		ystep *= -1;
		nexthorztouchY--;
		xstep *= -1;
	}
	while (nexthorztouchX >= 0 && nexthorztouchX < data->clmn_n * TILE && nexthorztouchY >= 0 && nexthorztouchY < data->rows_n * TILE) //more good to check the limits of the map
	{
		if (checking_collision3(data, nexthorztouchX, nexthorztouchY))
		{
			found_horz_hit = true;
			hor_hit_x = nexthorztouchX;
			hor_hit_y = nexthorztouchY;
			break ;
		}
		nexthorztouchX += xstep;
		nexthorztouchY += ystep;
	}
	
	// vertical intersection

	float	ver_hit_x;
	float	ver_hit_y;
	bool	foundverticalhit = false;

	xintercept = floor(x / TILE) * TILE;
	if ((data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		xintercept += TILE;
	yintercept = y + -1 * ((x - xintercept)  * tan(data->cast_angle));
	xstep = TILE;
	
	float	nextvertouchX = xintercept;
	float	nextvertouchY = yintercept;
	ystep = TILE * tan(data->cast_angle);
	// if (data->cast_angle > 0 && data->cast_angle < M_PI)
	// {
	// 	ystep *= -1;
	// 	// nextvertouchX--;
	// 	// xstep *= -1;
	// }


	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		xstep *= -1;
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI) && ystep > 0)
		ystep *= -1;
	if ((data->cast_angle > 0 && data->cast_angle < M_PI) && xstep < 0)
		ystep *= -1;

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
		nextvertouchX += xstep;
		nextvertouchY += ystep;
	}
	//////////////////////////////////////////////////////////////
	////////////////////calculate the closeset distance///////////
	//////////////////////////////////////////////////////////////
	
	float horzdis;
	if (found_horz_hit)
		horzdis = distance_calcul(x, y, hor_hit_x, hor_hit_y);
	else
		horzdis = INT_MAX;
	float verdis;
	if (foundverticalhit)
		verdis = distance_calcul(x, y, ver_hit_x, ver_hit_y);
	else
		verdis = INT_MAX;
	if (horzdis > verdis)
		return (verdis);
	return (horzdis);
}

