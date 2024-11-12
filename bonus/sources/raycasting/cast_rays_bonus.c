/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/11 21:43:51 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	open_door(t_data *data)
{
	int	i;
	int	j;

	data->player->x = data->player->sqaure_x / TILE;
	data->player->y = data->player->sqaure_y / TILE;
	i = data->player->x -3;
	while (i < data->player->x +3)
	{
		j = data->player->y -3;
		while (j < data->player->y +3)
		{
			if (data->map.map[j][i] == 'D')
			{
				data->map.map[j][i] = 'C';
				return ;
			}
			j++;
		}
		i++;
	}
}

void	close_door(t_data *data)
{
	int	i;
	int	j;

	data->player->x = data->player->sqaure_x / TILE;
	data->player->y = data->player->sqaure_y / TILE;
	i = data->player->x -3;
	while (i < data->player->x +3)
	{
		j = data->player->y -3;
		while (j < data->player->y +3)
		{
			if (data->map.map[j][i] == 'C' && data->map.map[(int)data->player->sqaure_y / TILE][(int)data->player->sqaure_x / TILE] != data->map.map[j][i])
			{
				data->map.map[j][i] = 'D';
				return ;
			}
			j++;
		}
		i++;
	}
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
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->player_img, j, i, BLUE);
			j++;
		}
		i++;
	}
	i = 350;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
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
