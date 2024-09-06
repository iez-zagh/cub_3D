/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:30:26 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/06 17:59:30 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision2(t_data *data, float x, float y)
{
	if (data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1' ||
		data->map[(int)(y / TILE)][(int)(x / TILE)] == '1') 
		return (1);
	return (0);
}

void	draw_direction(t_data *data, float x, float y)
{
	for (int i = 4;i < 25;i++)
	{
		if (!checking_collision2(data, x, y - i))
			mlx_put_pixel(data->img, x, y - i, RED);
	}
}

void	remove_direction(t_data *data, float x, float y)
{
	for (int i = 4;i < 25;i++)
	{
		if (!checking_collision2(data, x, y - i))
			mlx_put_pixel(data->img, x, y - i, WHITE);
	}
}
