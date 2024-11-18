/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:29:49 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:41:44 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision3(t_data *data, int x, int y)
{
	if (!data->map.map[(int)(y / TILE)][(int)(x / TILE)]
	|| (data->map.map[(int)(y / TILE)][(int)(x / TILE)] == '1')
	)
		return (1);
	if ((data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x + 1) / TILE)] == '1' &&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x + 1) / TILE)] == '0')
		|| (data->map.map[(int)((y + 1) / TILE)]
		[(int)((x) / TILE)] == '1' &&
		data->map.map[(int)((y) / TILE)]
		[(int)((x - 1) / TILE)] == '1' &&
		data->map.map[(int)((y + 1) / TILE)]
		[(int)((x - 1) / TILE)] == '0'))
		return (1);
	return (0);
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

uint32_t	get_rgb(int rgb[3])
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	r = rgb[0];
	g = rgb[1];
	b = rgb[2];
	a = 255;
	return (r << 24 | g << 16 | b << 8 | a);
}

void	floor_(t_data *data)
{
	int	i;
	int	j;
	int	color;

	i = 349;
	color = get_rgb(data->map.frgb);
	while (i < 700)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->player_img, j, i, color);
			j++;
		}
		i++;
	}
}

void	sky(t_data *data)
{
	float		i;
	float		j;
	uint32_t	color;

	i = 0;
	color = get_rgb(data->map.crgb);
	while (i < 350)
	{
		j = 0;
		while (j < WIDTH)
		{
			mlx_put_pixel(data->player_img, j, i, color);
			j++;
		}
		i++;
	}
	floor_(data);
}
