/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/13 11:44:11 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_rays(t_data *data)
{
	int	i;

	i = 0;
	while(i < 200)
	{
		// remove_direction(data, data->player->sqaure_x + i, data->player->sqaure_y + i);
		data->cast_angle += M_PI / 1100;
		draw_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
		i++;
	}
}

void	remove_rays(t_data *data)
{
	int	i;

	i = 0;
	while(i < 200)
	{
		// remove_direction(data, data->player->sqaure_x + i, data->player->sqaure_y + i);
		data->old_cast_angle += M_PI / 1100;
		remove_direction3(data, data->player->sqaure_x, data->player->sqaure_y);
		i++;
	}
}