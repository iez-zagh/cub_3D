/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:41:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data)
{
	float		dis_projection_plane;
	float		start;
	float		end;

	data->wall_dis = data->wall_dis
		* cos(data->cast_angle - data->player->angle);
	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	data->wall_height = (TILE / data->wall_dis) * dis_projection_plane;
	start = (HEIGHT / 2) - (data->wall_height / 2);
	if (start < 0)
		start = 0;
	end = start + data->wall_height;
	if (end >= HEIGHT)
		end = HEIGHT;
	set_texture(data, start, end);
}

void	vert_traverse(t_data *data, float ystep, float xstep)
{
	float	x;

	if (data->facing_left)
		xstep *= -1;
	if (data->facing_up)
		ystep *= -1;
	while (data->nexttouchx >= 0 && data->nexttouchx < data->clmn_n * TILE
		&& data->nexttouchy >= 0 && data->nexttouchy < data->rows_n * TILE)
	{
		x = data->nexttouchx;
		if (data->facing_left)
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

void	cast_rays(t_data *data)
{
	int		i;

	sky(data);
	data->cast_angle = data->player->angle - FOV_ANGLE / 2;
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
