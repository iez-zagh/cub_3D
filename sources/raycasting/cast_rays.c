/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/24 16:14:53 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sky_floor(t_data *data)//optimi
{
	int	i;
	int	j;
	
	i = 0;
	while (i < 350)
	{
		j = 0;
		while (j < 1200)
		{
			mlx_put_pixel(data->player_img, j, i, BLUE);
			j++;
		}
		i++;
	}
	i = 350;
	while (i < 700)
	{
		j = 0;
		while (j < 1200)
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
	float		dis = 0.0;
	float	an = 0;
	float	incr_angle = FOV_ANGLE / WIDTH;

	i = 0;
	sky_floor(data);
	data->cast_angle = data->player->angle;
	data->cast_angle -= FOV_ANGLE / 2;
	data->strip_n = 0;
	while(i < WIDTH)
	{
		dis = cast_lines(data, data->player->sqaure_x, data->player->sqaure_y);
		player_view(data, dis);
		data->cast_angle += incr_angle;
		data->strip_n++;
		i++;
	}
	data->cast_angle = data->player->angle;
}
