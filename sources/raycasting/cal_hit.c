/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/03 15:52:04 by iez-zagh         ###   ########.fr       */
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
	if (!(data->cast_angle < 0.5 * M_PI || data->cast_angle > 1.5 * M_PI))
		data->nexttouchX--;
	while (data->nexttouchX >= 0 && data->nexttouchX < data->clmn_n * TILE
		&& data->nexttouchY >= 0 && data->nexttouchY < data->rows_n * TILE)
	{
		if (checking_collision3(data, data->nexttouchX, data->nexttouchY))
		{
			data->foundverticalhit = true;
			data->ver_hit_x = data->nexttouchX;
			data->ver_hit_y = data->nexttouchY;
			break ;
		}
		data->nexttouchX += xstep;
		data->nexttouchY += ystep;
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
	data->yintercept = data->player->sqaure_y + -1
		* ((data->player->sqaure_x - data->xintercept) * tan(data->cast_angle));
	xstep = TILE;
	data->nexttouchX = data->xintercept;
	data->nexttouchY = data->yintercept;
	ystep = TILE * tan(data->cast_angle);
	vert_traverse(data, ystep, xstep);
}

void	horz_traverse(t_data *data, float ystep, float xstep)
{
	if (!(data->cast_angle > 0 && data->cast_angle < M_PI))
	{
		ystep *= -1;
		data->nexttouchY--;
		xstep *= -1;
	}
	while (data->nexttouchX >= 0 && data->nexttouchX < data->clmn_n * TILE
		&& data->nexttouchY >= 0 && data->nexttouchY < data->rows_n * TILE)
	{
		if (checking_collision3(data, data->nexttouchX, data->nexttouchY))
		{
			data->found_horz_hit = true;
			data->hor_hit_x = data->nexttouchX;
			data->hor_hit_y = data->nexttouchY;
			break ;
		}
		data->nexttouchX += xstep;
		data->nexttouchY += ystep;
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
		data->wall_dis = verdis;
	else
		data->wall_dis = horzdis;
}

void	cast_ray(t_data *data)
{
	float	xstep;
	float	ystep;

	data->found_horz_hit = false;
	data->yintercept = floor(data->player->sqaure_y / TILE) * TILE;
	if (data->cast_angle > 0 && data->cast_angle <= M_PI)
		data->yintercept += TILE;
	data->xintercept = data->player->sqaure_x
		+ ((data->yintercept - data->player->sqaure_y) / tan(data->cast_angle));
	ystep = TILE;
	xstep = TILE / tan(data->cast_angle);
	data->nexttouchX = data->xintercept;
	data->nexttouchY = data->yintercept;
	horz_traverse(data, ystep, xstep);
	vert_interception(data);
	get_closest_hit(data);
}
