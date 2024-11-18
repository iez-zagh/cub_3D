/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:58:46 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 00:59:01 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	open_door(t_data *data)
{
	if (data->door_hit
		&& data->map.map[(int)data->door_y / TILE]
		[(int)data->door_x / TILE] == 'D'
		&& distance_calcul(data->player->sqaure_x,
			data->player->sqaure_y, data->door_x, data->door_y) < 3 * TILE)
		data->map.map[(int)data->door_y / TILE][(int)data->door_x / TILE] = 'C';
}

int	check_close_door(t_data *data, float x, float y)
{
	x /= TILE;
	y /= TILE;
	x *= TILE_SCALED;
	y *= TILE_SCALED;
	if (data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] &&
		(data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == 'C' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == 'C' ||
		data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == 'C' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == 'C'))
		return (1);
	return (0);
}

void	close_door(t_data *data)
{
	if (data->door_hit && data->map.map[(int)data->door_y / TILE]
		[(int)data->door_x / TILE] == 'C'
		&& !check_close_door(data, data->player->sqaure_x,
			data->player->sqaure_y)
		&& distance_calcul(data->player->sqaure_x, data->player->sqaure_y,
			data->door_x, data->door_y) < 3 * TILE)
		data->map.map[(int)data->door_y / TILE][(int)data->door_x / TILE] = 'D';
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
