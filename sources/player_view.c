/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/15 16:57:24 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data)
{
    float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->cast_angle); //cos(0) = 1 | sin(0) = 0
	dir_y = sin(data->cast_angle);
	i = 0;
	while (i < 300)
	{
		if (checking_collision2(data, data->player->sqaure_x + (dir_x * i), data->player->sqaure_y + (dir_y * i)))
			return ;
		mlx_put_pixel(data->player_img, data->player->sqaure_x + (dir_x * i),data->player->sqaure_y + (dir_y * i), RED);
		i++;
	}
}