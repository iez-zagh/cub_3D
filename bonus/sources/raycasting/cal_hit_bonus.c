/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/19 00:45:05 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	vert_interception(t_data *data)
{
	float	xstep;
	float	ystep;

	data->foundverticalhit = false;
	data->xintercept = floor(data->player->sqaure_x / TILE) * TILE;
	if (data->facing_right)
		data->xintercept += TILE;
	data->yintercept = data->player->sqaure_y
		+ ((data->xintercept - data->player->sqaure_x) * tan(data->cast_angle));
	xstep = TILE;
	data->nexttouchx = data->xintercept;
	data->nexttouchy = data->yintercept;
	ystep = fabs(TILE * tan(data->cast_angle));
	vert_traverse(data, ystep, xstep);
}

void	horz_traverse(t_data *data, float ystep, float xstep)
{
	float	y;

	if (data->facing_up)
		ystep *= -1;
	if (data->facing_left)
		xstep *= -1;
	while (data->nexttouchx >= 0 && data->nexttouchx < data->clmn_n * TILE
		&& data->nexttouchy >= 0 && data->nexttouchy < data->rows_n * TILE)
	{
		y = data->nexttouchy;
		if (data->facing_up)
			y--;
		if (checking_collision3(data, data->nexttouchx, y)
			|| checking_collision_door3(data, data->nexttouchx, y))
		{
			data->found_horz_hit = true;
			data->hor_hit_x = data->nexttouchx;
			data->hor_hit_y = data->nexttouchy;
			break ;
		}
		data->nexttouchx += xstep;
		data->nexttouchy += ystep;
	}
}

void	get_closest_hit(t_data *data)
{
	float	horzdis;
	float	verdis;

	if (data->found_horz_hit)
		horzdis = distance_calcul(data->player->sqaure_x,
				data->player->sqaure_y, data->hor_hit_x, data->hor_hit_y);
	else
		horzdis = INT_MAX;
	if (data->foundverticalhit)
		verdis = distance_calcul(data->player->sqaure_x,
				data->player->sqaure_y, data->ver_hit_x, data->ver_hit_y);
	else
		verdis = INT_MAX;
	if (horzdis > verdis)
	{
		data->wall_dis = verdis;
		data->found_horz_hit = false;
	}
	else
	{
		data->wall_dis = horzdis;
		data->foundverticalhit = false;
	}
}

void	init_direction(t_data *data)
{
	data->facing_down = false;
	data->facing_up = false;
	data->facing_left = false;
	data->facing_right = false;
	if (data->cast_angle > 0 && data->cast_angle < M_PI)
		data->facing_down = true;
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
		data->facing_up = true;
	if (data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI)
		data->facing_right = true;
	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		data->facing_left = true;
}

void	cast_ray(t_data *data)
{
	float	xstep;
	float	ystep;

	init_direction(data);
	data->found_horz_hit = false;
	data->yintercept = floor(data->player->sqaure_y / TILE) * TILE;
	if (data->cast_angle > 0 && data->cast_angle <= M_PI)
		data->yintercept += TILE;
	data->xintercept = data->player->sqaure_x
		+ ((data->yintercept - data->player->sqaure_y) / tan(data->cast_angle));
	ystep = TILE;
	xstep = fabs(TILE / tan(data->cast_angle));
	data->nexttouchx = data->xintercept;
	data->nexttouchy = data->yintercept;
	horz_traverse(data, ystep, xstep);
	vert_interception(data);
	get_closest_hit(data);
}
