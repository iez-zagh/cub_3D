/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/30 08:44:02 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data, float dis)
{
	float	wall_height;
	float	dis_projection_plane;
	float	start;
	float	end;
	float	i;
	int	color;

	float corr_dis = dis * cos(data->cast_angle - data->player->angle);
	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / corr_dis) * dis_projection_plane;
	start = (HEIGHT / 2) - (wall_height / 2);
	if (start < 0)
		start = 0;	
	end = start + wall_height;
	if (end >= HEIGHT)
		end = HEIGHT;
	i = start;
	while (i < end)
	{
		mlx_put_pixel(data->player_img, data->strip_n, i, RED);
		i++;
	}
}
