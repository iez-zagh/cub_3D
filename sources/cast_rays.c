/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/06 21:25:43 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_data *data)
{
	// return ;
	int	i;

	i = 0;
	data->cast_angle = data->player->angle;
	data->cast_angle -= 250 * (M_PI / 2000);
	while(i < 500)
	{
		data->cast_angle += M_PI / 2000;
		cast_lines(data, data->player->sqaure_x, data->player->sqaure_y);
		i++;
	}
	data->cast_angle = data->player->angle;
}

void	remove_rays(t_data *data)
{
	// return ;
	int	i;

	i = 0;
	data->cast_angle -= 250 * (M_PI / 2000);
	while(i < 500)
	{
		data->cast_angle += M_PI / 2000;
		remove_direction3(data, data->player->sqaure_x, data->player->sqaure_y);
		i++;
	}
}
