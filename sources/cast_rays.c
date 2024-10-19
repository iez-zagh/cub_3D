/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/19 19:33:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_data *data)
{
	int	i;
	int	dis;

	i = 0;
	data->cast_angle = data->player->angle;
	data->cast_angle -= 333 * (M_PI / 2000);
	while(i < 666)
	{
		dis = cast_lines(data, data->player->sqaure_x, data->player->sqaure_y);
		player_view(data, dis);
		data->cast_angle += M_PI / 2000;
		i++;
	}
	data->cast_angle = data->player->angle;
}

void	remove_rays(t_data *data)
{
	int	i;

	i = 0;
	data->cast_angle -= 333 * (M_PI / 2000);
	while(i < 666)
	{
		remove_direction3(data, data->player->sqaure_x, data->player->sqaure_y);
		data->cast_angle += M_PI / 2000;
		i++;
	}
}
