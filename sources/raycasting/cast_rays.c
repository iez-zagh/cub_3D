/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/03 16:40:53 by iez-zagh         ###   ########.fr       */
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
		) || (
		data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x) / TILE_SCALED)] == '1'
		&&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE_SCALED)]
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
	if ((data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0'
		)
		||
		(
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x) / TILE)] == '1'
		&&
		data->map.map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '0'
		))
		return (1);
	return (0);
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

void	sky_floor(t_data *data)//optimi
{
	float	i;
	float	j;

	i = 0;
	while (i < 350)
	{
		j = 0;
		while (j < 1200)
		{
			mlx_put_pixel(data->player_img, j, i, BLUE);
			j++;
		}
		i++;
	}
	i = 350;
	while (i < 700)
	{
		j = 0;
		while (j < 1200)
		{
			mlx_put_pixel(data->player_img, j, i, BLACK);
			j++;
		}
		i++;
	}
}

void	cast_rays(t_data *data)
{
	int		i;
	float	dis;
	float	incr_angle;

	incr_angle = FOV_ANGLE / WIDTH;
	sky_floor(data);
	data->cast_angle = data->player->angle;
	data->cast_angle -= FOV_ANGLE / 2;
	data->strip_n = 0;
	i = 0;
	while (i < WIDTH)
	{
		cast_ray(data);
		player_view(data);
		data->cast_angle += incr_angle;
		if (data->cast_angle > M_PI * 2)
			data->cast_angle = 0;
		data->strip_n++;
		i++;
	}
	data->cast_angle = data->player->angle;
}
