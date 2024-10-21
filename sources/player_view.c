/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/21 12:13:18 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data, float dis)
{
	float	wall_height;
	float	dis_projection_plane;
	float	start;
	float	end;
	int		i;

	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / dis) * dis_projection_plane;
	start = (HEIGHT / 2) - (wall_height / 2);
	if (start < 0) // need to develop this
		start = 0;
	end = start + wall_height;
	if (end >= HEIGHT) //either this
		end = HEIGHT;
	i = start;
	while (i < end)
	{
		mlx_put_pixel(data->player_img, (int)data->strip_n, i, RED);
		i++;
	}
}
