/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/16 20:48:10 by zmaghdao         ###   ########.fr       */
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
	if (data->map.map[(int)((y) / TILE)]
		[(int)((x) / TILE)] &&
		(data->map.map[(int)((y) / TILE)]
		[(int)((x) / TILE)] == 'D' ||
		data->map.map[(int)((y + RADIUS2) / TILE)]
		[(int)((x) / TILE)] == 'D' ||
		data->map.map[(int)((y) / TILE)]
		[(int)((x) / TILE)] == 'D' ||
		data->map.map[(int)((y) / TILE)]
		[(int)((x) / TILE)] == 'D'))
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

void	handle_angle(t_data *data)
{
	data->cast_angle = remainder(data->cast_angle, 2 * M_PI);
	if (data->cast_angle < 0)
		data->cast_angle = 2 * M_PI + data->cast_angle;
}

void	cast_rays(t_data *data)
{
	int		i;
	// float	dis;

	sky_floor(data);
	data->cast_angle = data->player->angle;
	data->cast_angle -= FOV_ANGLE / 2;
	data->strip_n = 0;
	i = 0;
	while (i < WIDTH)
	{
		handle_angle(data);
		cast_ray(data);
		player_view(data);
		data->cast_angle += FOV_ANGLE / WIDTH;
		data->strip_n++;
		i++;
	}
	data->cast_angle = data->player->angle;
}
