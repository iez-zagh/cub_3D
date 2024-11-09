/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_view.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:56:18 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/09 13:48:46 by zmaghdao         ###   ########.fr       */
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
		return (mlx_delete_image(data->mlx, data->tex.i_north), -18);
	data->tex.i_west = mlx_texture_to_image(data->mlx, data->tex.west);
	if (!data->tex.i_west)
		return (mlx_delete_image(data->mlx, data->tex.i_north),
				mlx_delete_image(data->mlx, data->tex.i_south), -18);
	data->tex.i_east = mlx_texture_to_image(data->mlx, data->tex.east);
	if (!data->tex.i_east)
		return (mlx_delete_image(data->mlx, data->tex.i_north),
				mlx_delete_image(data->mlx, data->tex.i_south),
				mlx_delete_image(data->mlx, data->tex.i_west), -18);
	mlx_delete_texture(data->tex.north);
	mlx_delete_texture(data->tex.south);
	mlx_delete_texture(data->tex.west);
	mlx_delete_texture(data->tex.east);
	return (0);
}

//to do : a function to put the texture on the wall named put_texture

void	start_render(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
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

void	get_the_pixel(t_data *data, float i);

void	player_view(t_data *data)
{
	float	dis_projection_plane;
	float	start;
	float	end;
	float	i;

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
	i = start;
	while (i < end)
	{
		// get_the_pixel(data, i);÷
		// if ((int )i % 2 == 0)
		// 	mlx_put_pixel(data->player_img, data->strip_n, i, BLUE);
		// else
			mlx_put_pixel(data->player_img, data->strip_n, i, RED);
		i++;
	}
}

// void	get_the_pixel(t_data *data, float i)
// {
// 	//to do : get the pixel from the texture and put it on the wall
// 	float		step;

// 	step =  / data->wall_height;
// }
