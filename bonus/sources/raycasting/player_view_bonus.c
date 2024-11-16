/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/15 18:02:02 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_key_hook5(t_data *data)
{
	if (data->add_key)
	{
		if (data->mouse_sensive > 10)
			return ;
		data->mouse_sensive += 0.2;
	}
	if (data->sub_key)
	{
		if (data->mouse_sensive < 1)
			return ;
		data->mouse_sensive -= 0.2;
	}
}

void	draw_direction(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	i = 0.0 ;
	while (i < 20)
	{
		if (checking_collision2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i))
			|| checking_collision_door2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i++;
	}
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

mlx_image_t	*get_texture(t_data *data)
{
	if (data->found_horz_hit)
	{
		if (checking_collision_door3(data, data->hor_hit_x, data->hor_hit_y)) // i add this to check the door 9tae3 lah ydir l7mar
			return (data->tex.i_door);
		if (data->facing_down)
			return (data->tex.i_north);
		else
			return (data->tex.i_south);
	}
	else
	{
		if (checking_collision_door3(data, data->hor_hit_x, data->hor_hit_y))
			return (data->tex.i_door);
		if (data->facing_left)
			return (data->tex.i_west);
		else 
			return (data->tex.i_east);
	}
	return (NULL);
}

uint32_t	get_texture_pixel(mlx_image_t *texture, int x, int y)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
	int		index;

	if (!texture)
		return (0x000000);
	if (x >= 0 && (uint32_t)x < texture->width
		&& y >= 0 && (uint32_t)y < texture->height)
	{
		index = (y * texture->width + x) * 4;
		r = texture->pixels[index];
		g = texture->pixels[index + 1];
		b = texture->pixels[index + 2];
		a = texture->pixels[index + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0x000000);
}


void	player_view(t_data *data)
{
	float	dis_projection_plane;
	float	start;
	float	end;
	mlx_image_t	*img;

	data->wall_dis = data->wall_dis
		* cos(data->cast_angle - data->player->angle);
	dis_projection_plane = (WIDTH / 2) / tan(FOV_ANGLE / 2);
	data->wall_height = (TILE / data->wall_dis) * dis_projection_plane;
	start = (HEIGHT / 2) - (data->wall_height / 2);
	if (start < 0)
		start = 0;
	end = start + data->wall_height;
	if (end >= HEIGHT)
		end = HEIGHT;

	img = get_texture(data);
	double step = (double)img->height / data->wall_height;
	double textureofssetX;
	if (data->found_horz_hit)
		textureofssetX = ((int)(data->hor_hit_x * img->width) / TILE) % img->width;
	else if (data->foundverticalhit)
		textureofssetX = ((int)(data->ver_hit_y * img->width) / TILE) % img->width;

	int distance_from_top = start + (data->wall_height / 2) - (HEIGHT / 2);
	double texturePosY = distance_from_top * step;

	while (start < end)
	{
		int textureofssetY = (int)texturePosY;
		uint32_t color = get_texture_pixel(img, textureofssetX, textureofssetY);
		mlx_put_pixel(data->player_img, data->strip_n, start, color);
		texturePosY += step;
		start++;
	}
}
