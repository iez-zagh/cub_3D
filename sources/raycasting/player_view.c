/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/25 15:48:12 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <math.h>

int get_color(int base_color, float distance, float max_distance)
{
    // Calculate the factor for darkness (0.0 = fully bright, 1.0 = fully dark)
    float factor = distance / max_distance;
    if (factor > 1.0)
        factor = 1.0;  // Clamp the factor to 1.0, no darker than completely black

    // Extract the RGB components from the base color
    int red = (base_color >> 16) & 0xFF;
    int green = (base_color >> 8) & 0xFF;
    int blue = base_color & 0xFF;

    // Apply the darkening factor to each RGB component
    red = red * (1 - factor);
    green = green * (1 - factor);
    blue = blue * (1 - factor);

    // Recombine the RGB values into a single integer color
    int darkened_color = (red << 16) | (green << 8) | blue;

    // Add full opacity (0xFF) to the color
    return (0xFF << 24) | darkened_color;
}


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
	if (start < 0) // need to develop this
		start = 0;	
	end = start + wall_height;
	if (end >= HEIGHT) //either this
		end = HEIGHT;
	i = start;
	// color = get_color(WHITE, dis, 1200);
	while (i < end)
	{
		mlx_put_pixel(data->player_img, data->strip_n, i, RED);
		i++;
	}
}
