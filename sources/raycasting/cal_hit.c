/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/13 18:15:23 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vert_traverse(t_data *data, float ystep, float xstep)
{
	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		xstep *= -1;
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI) && ystep > 0)
		ystep *= -1;
	if ((data->cast_angle > 0 && data->cast_angle < M_PI) && xstep < 0)
		ystep *= -1;
	while (data->nexttouchx >= 0 && data->nexttouchx < data->clmn_n * TILE
		&& data->nexttouchy >= 0 && data->nexttouchy < data->rows_n * TILE)
	{
		float x = data->nexttouchx;
		if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
			x--;
		if (checking_collision3(data, x, data->nexttouchy))
		{
			data->foundverticalhit = true;
			data->ver_hit_x = data->nexttouchx;
			data->ver_hit_y = data->nexttouchy;
			break ;
		}
		data->nexttouchx += xstep;
		data->nexttouchy += ystep;
	}
}

void	vert_interception(t_data *data)
{
	float	xstep;
	float	ystep;

	data->foundverticalhit = false;
	data->xintercept = floor(data->player->sqaure_x / TILE) * TILE;
	if ((data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		data->xintercept += TILE;
	data->yintercept = data->player->sqaure_y +
		((data->xintercept - data->player->sqaure_x) * tan(data->cast_angle));
	xstep = TILE;
	data->nexttouchx = data->xintercept;
	data->nexttouchy = data->yintercept;
	ystep = TILE * tan(data->cast_angle);
	vert_traverse(data, ystep, xstep);
}

void	horz_traverse(t_data *data, float ystep, float xstep)
{
	// if (data->cast_angle > M_PI && data->cast_angle < 2 * M_PI)
	// 	ystep *= -1; 
	// if (data->cast_angle > M_PI && data->cast_angle < 2 * M_PI)
	if (data->cast_angle > M_PI && data->cast_angle < 2 * M_PI)
	{
		ystep *= -1;
		xstep *= -1;
	}
	while (data->nexttouchx >= 0 && data->nexttouchx < data->clmn_n * TILE
		&& data->nexttouchy >= 0 && data->nexttouchy < data->rows_n * TILE)
	{
		float y = data->nexttouchy;
		if (data->cast_angle > M_PI && data->cast_angle <= 2 * M_PI)
			y--;
		if (checking_collision3(data, data->nexttouchx, y))
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
	if (data->cast_angle < )
}
void	cast_ray(t_data *data)
{
	float	xstep;
	float	ystep;

	// init_dirction(data);
	data->found_horz_hit = false;
	data->yintercept = floor(data->player->sqaure_y / TILE) * TILE;
	if (data->cast_angle > 0 && data->cast_angle <= M_PI)
		data->yintercept += TILE;
	data->xintercept = data->player->sqaure_x
		+ ((data->yintercept - data->player->sqaure_y) / tan(data->cast_angle));
	ystep = TILE;
	xstep = TILE / tan(data->cast_angle);
	data->nexttouchx = data->xintercept;
	data->nexttouchy = data->yintercept;
	horz_traverse(data, ystep, xstep);
	vert_interception(data);
	get_closest_hit(data);
}
