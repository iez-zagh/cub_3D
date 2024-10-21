/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/21 09:16:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data, float	dis)
{
	float	wall_height;
	float	dis_projection_plane;

	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / dis) * dis_projection_plane;
	float i = (HEIGHT / 2) - (wall_height / 2);
	float	i0 = i; 
	i = 0;
	while (i < HEIGHT)
	{
		if (i > i0 &&  i < wall_height + i0)
			mlx_put_pixel(data->player_img, (int)data->strip_n, i, RED);
		i++;
	}
}
