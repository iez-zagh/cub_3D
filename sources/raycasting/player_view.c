/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:47:33 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	convert_textures(t_data *data)
{
	data->tex.i_north = mlx_texture_to_image(data->mlx, data->tex.north);
	if (!data->tex.i_north)
		return (-18);
	data->tex.i_south = mlx_texture_to_image(data->mlx, data->tex.south);
	if (!data->tex.i_south)
		return (delete_images(data, 0), delete_texture(data, 4), -18);
	data->tex.i_west = mlx_texture_to_image(data->mlx, data->tex.west);
	if (!data->tex.i_west)
		return (delete_images(data, 1), delete_texture(data, 4), -18);
	data->tex.i_east = mlx_texture_to_image(data->mlx, data->tex.east);
	if (!data->tex.i_east)
		return (delete_images(data, 2), delete_texture(data, 4), -18);
	return (delete_texture(data, 4), 0);
}

void	start_render(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	if (!data->mlx)
	{
		// do something
	}
	data->img = mlx_new_image(data->mlx, 336, 224);
	if (convert_textures(data) < 0)
		return ;
	data->player_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player->sqaure_x = data->player->x * TILE;
	data->player->sqaure_y = data->player->y * TILE;
	data->player->sqaure_x += TILE / 2;
	data->player->sqaure_y += TILE / 2;
	cast_rays(data);
	mlx_image_to_window(data->mlx, data->player_img, 0, 0);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	data->a_key = false;
	data->w_key = false;
	data->s_key = false;
	data->d_key = false;
	mlx_key_hook(data->mlx, check_keys, data);
	mlx_loop_hook(data->mlx, my_key_hook, data);
	mlx_loop(data->mlx);
}

mlx_image_t	*get_texture(t_data *data)
{
	if (data->found_horz_hit)
	{
		if (data->cast_angle > 0 && data->cast_angle < M_PI)
			return (data->tex.i_north);
		else
			return (data->tex.i_south);
	}
	else
	{
		if (data->cast_angle > M_PI_2 && data->cast_angle < 3 * M_PI_2)
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

	img = get_texture(data);
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
