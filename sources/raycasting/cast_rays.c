/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/16 20:42:33 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision3(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE)][(int)(x / TILE)]
	|| (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == '1')
	)
		return (1);
	if ((data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1' &&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0')
		|| (data->map.map[(int)((y + 1) / TILE)]
		[(int)((x) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '0'
		))
		return (1);
	return (0);
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

void	sky_floor(t_data *data)//optimi
{
	float	i;
	float	j;

	i = 0;
	while (i < 350)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->player_img, j, i, 0x0B0033FF);
			j++;
		}
		i++;
	}
	while (i < 700)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->player_img, j, i, 0x1A1A1AFF);
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
