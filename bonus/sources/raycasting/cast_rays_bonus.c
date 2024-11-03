/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/04 00:34:06 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	checking_collision2(t_data *data, float x, float y)
{
	if (!data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)]
	|| (data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)] == '1')
	)
		return (1);
	if ((data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '1' &&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == '0')
		|| (data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x) / TILE_SCALED)] == '1'
		&&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == '0'))
		return (1);
	return (0);
}

int	checking_collision_door2(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)]
	|| (data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)] == 'D')
	)
		return (1);
	if (
		(data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == 'D' &&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == 'D'
		&&
		data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x + 1) / TILE_SCALED)] == '0')
		|| (data->map.map[(int)((y + 1) / TILE_SCALED)]
		[(int)((x) / TILE_SCALED)] == 'D'
		&&
		data->map.map[(int)((y) / TILE_SCALED)]
		[(int)((x - 1) / TILE_SCALED)] == 'D'
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
	|| (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == '1'))
		return (1);
	if (
		(data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1'
		&&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0'
		) || (data->map.map[(int)((y + 1) / TILE)]
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

int	checking_collision_door3(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE)][(int)(x / TILE)]
	|| (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == 'D'))
		return (1);
	if (
		(data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == 'D' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == 'D'
		&&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0'
		) || (data->map.map[(int)((y + 1) / TILE)]
		[(int)((x) / TILE)] == 'D'
		&&
		data->map.map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == 'D'
		&&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '0'
		))
		return (1);
	return (0);
}

int	checking_collision(t_data *data, float x, float y)
{
	x /= TILE;
	y /= TILE;
	x *= TILE_SCALED;
	y *= TILE_SCALED;
	if (data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] &&
		(data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == '1'))
		return (1);
	return (0);
}

int	checking_collision_door(t_data *data, float x, float y)
{
	x /= TILE;
	y /= TILE;
	x *= TILE_SCALED;
	y *= TILE_SCALED;
	if (data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] &&
		(data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == 'D' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == 'D' ||
		data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == 'D' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == 'D'))
		return (1);
	return (0);
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
