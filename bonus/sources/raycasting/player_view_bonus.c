/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/04 14:11:56 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_key_hook5(t_data *data)
{
	if (data->add_key)
	{
		if (data->mouse_sensive > 10)
			return ;
		data->mouse_sensive += 0.2;
	}
	if (data->sub_key)
	{
		if (data->mouse_sensive < 1)
			return ;
		data->mouse_sensive -= 0.2;
	}
	if (data->open_door)
	{
		puts("here open");
	}
}

void	draw_direction(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	i = 0.0 ;
	while (i < 20)
	{
		if (checking_collision2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i))
			|| checking_collision_door2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i++;
	}
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

void	player_view(t_data *data)
{
	float	dis_projection_plane;
	float	start;
	float	end;
	float	i;

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
	i = start;
	while (i < end)
	{
		mlx_put_pixel(data->player_img, data->strip_n, i, RED);
		i++;
	}
}
