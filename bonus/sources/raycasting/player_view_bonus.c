/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/19 00:31:07 by iez-zagh         ###   ########.fr       */
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

mlx_image_t	*get_texture(t_data *data, float x, float y)
{
	if (data->found_horz_hit)
	{
		1 && (x = data->hor_hit_x, y = data->hor_hit_y);
		if (data->facing_up)
			y--;
		if (data->map.map[(int)((y) / TILE)][(int)((x) / TILE)] == 'D')
			return (data->tex.i_door);
		if (data->facing_down)
			return (data->tex.i_north);
		else
			return (data->tex.i_south);
	}
	else if (data->foundverticalhit)
	{
		1 && (x = data->ver_hit_x, y = data->ver_hit_y);
		if (data->facing_left)
			x--;
		if (data->map.map[(int)((y) / TILE)][(int)((x) / TILE)] == 'D')
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

void	set_texture(t_data *data, float start, float end)
{
	mlx_image_t	*img;
	int			distance_from_top;
	int			textureofssety;

	img = get_texture(data, 0, 0);
	data->step = (double)img->height / data->wall_height;
	if (data->found_horz_hit)
		data->textureofssetx = ((int)(data->hor_hit_x * img->width) / TILE)
			% img->width;
	else if (data->foundverticalhit)
		data->textureofssetx = ((int)(data->ver_hit_y * img->width) / TILE)
			% img->width;
	distance_from_top = start + (data->wall_height / 2) - (HEIGHT / 2);
	data->textureposy = distance_from_top * data->step;
	while (start < end)
	{
		textureofssety = (int)data->textureposy;
		data->color = get_texture_pixel(img, data->textureofssetx,
				textureofssety);
		mlx_put_pixel(data->player_img, data->strip_n, start, data->color);
		data->textureposy += data->step;
		start++;
	}
}

void	player_view(t_data *data)
{
	float	dis_projection_plane;
	float	start;
	float	end;

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
	set_texture(data, start, end);
}
