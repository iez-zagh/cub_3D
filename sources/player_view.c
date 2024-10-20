/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/20 12:17:49 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_view(t_data *data, float	dis)
{
	// printf("%f]]\n", dis);
	float	wall_height;
	float	dis_projection_plane;

	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_height = (TILE / dis) * dis_projection_plane;
	float i = wall_height + (HEIGHT / 2) - (wall_height / 2);
    printf("%f]\n", i);
    printf("%f]\n", (HEIGHT / 2) - (wall_height / 2));
	float j = 0;
	while (i > 0)
	{
		mlx_put_pixel(data->img, data->strip_n, i, WHITE);
		// j++;
		i--;
	}
	// printf("%f]\n", dis_projection_plane);
	// printf("%f]\n", wall_height);
}
