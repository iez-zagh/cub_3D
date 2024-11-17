/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:05:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/05 18:51:16 by iez-zagh         ###   ########.fr       */
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
	|| (data->map.map[(int)(y / TILE_SCALED)][(int)(x / TILE_SCALED)] == 'D'))
		return (1);
	if ((data->map.map[(int)((y + 1) / TILE_SCALED)]
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
		[(int)((x - 1) / TILE_SCALED)] == '0'))
		return (1);
	return (0);
}

int	checking_collision3(t_data *data, int x, int y)
{
	if (data->map.map[(int)(y / TILE)][(int)(x / TILE)]
	&& (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == '1'))
		return (1);
	// if (
	// 	(data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x - 1) / TILE)] == '1' &&
	// 	data->map.map[(int)((y) / TILE)]
	// 	[(int)((x + 1) / TILE)] == '1'
	// 	&&
	// 	data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x + 1) / TILE)] == '0'
	// 	) || (data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x) / TILE)] == '1'
	// 	&&
	// 	data->map.map[(int)((y) / TILE)]
	// 	[(int)((x - 1) / TILE)] == '1'
	// 	&&
	// 	data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x - 1) / TILE)] == '0'
	// 	))
	// 	return (1);
	return (0);
}

int	checking_collision_door3(t_data *data, int x, int y)
{
	if (data->map.map[(int)((y) / TILE)][(int)(x / TILE)]
	&& (data->map.map[(int)((y) / TILE)][(int)(x / TILE)] == 'D'))
	{
		data->door_hit = true;
		data->door_x = x;
		data->door_y = y;
		return (1);
	}
	if (data->map.map[(int)(y / TILE)]
	[(int)(x / TILE)] == 'C')
	{
		data->door_hit = true;
		data->door_x = x;
		data->door_y = y;
	}
	//think about this
	// if ((data->map.map[(int)((y + 1) / TILE)] 
	// 	[(int)((x - 1) / TILE)] == 'D' &&
	// 	data->map.map[(int)((y) / TILE)]
	// 	[(int)((x + 1) / TILE)] == 'D' &&
	// 	data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x + 1) / TILE)] == '0'
	// 	) || (data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x) / TILE)] == 'D' &&
	// 	data->map.map[(int)((y) / TILE)]
	// 	[(int)((x - 1) / TILE)] == 'D' &&
	// 	data->map.map[(int)((y + 1) / TILE)]
	// 	[(int)((x - 1) / TILE)] == '0'))
	// 	return (1);
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
