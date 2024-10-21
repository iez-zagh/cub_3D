/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/21 12:17:46 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sky_floor(t_data *data)
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
	float	dis;
	float	an = 0;

	i = 0;
	data->cast_angle = data->player->angle;
	data->cast_angle -= 30 * (M_PI / 180);
	data->strip_n = 0;
	sky_floor(data);
	while(i < WIDTH)
	{
		dis = cast_lines(data, data->player->sqaure_x, data->player->sqaure_y);
		player_view(data, dis);
		data->cast_angle += 0.05 * (M_PI / 180);
		data->strip_n++;
		i++;
	}
	data->cast_angle = data->player->angle;
}

void	remove_rays(t_data *data) //no need for this
{
	return ;
	int	i;

	i = 0;
	data->cast_angle -= 600 * (M_PI / 2000);
	while(i < 1200)
	{
		remove_direction3(data, data->player->sqaure_x, data->player->sqaure_y);
		data->cast_angle += M_PI / 2000;
		i++;
	}
}
