/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:30:42 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:35:17 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	run_animation(t_data *data)
{
	static int	i = 0;

	if (i == 36)
		i = 0;
	if (data->frames == 7)
	{
		mlx_image_to_window(data->mlx, data->tex.i_frames[i], 250, 350);
		if (i == 35)
			data->animation = 0;
		if (i > 0)
		{
			mlx_delete_image(data->mlx, data->tex.i_frames[i - 1]);
			data->tex.i_frames[i - 1] = mlx_texture_to_image(data->mlx,
					data->tex.frames[i - 1]);
		}
		else
		{
			mlx_delete_image(data->mlx, data->tex.i_frames[35]);
			data->tex.i_frames[35] = mlx_texture_to_image(data->mlx,
					data->tex.frames[35]);
		}
		i++;
		data->frames = 0;
	}
	data->frames++;
}

void	enter_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->animation = true;
}

void	check_keys_2(t_data *data, mlx_key_data_t key)
{
	if (key.key == MLX_KEY_O)
	{
		open_door(data);
		draw_minimap(data);
		cast_rays(data);
	}
	if (key.key == MLX_KEY_C)
	{
		close_door(data);
		draw_minimap(data);
		cast_rays(data);
	}
	if (key.key == MLX_KEY_ESCAPE)
	{
		// free all res
		write(1, "WINDOW CLOSED\n", 14);
		exit(0);
	}
}

void	vert_traverse(t_data *data, float ystep, float xstep)
{
	float	x;

	if (data->facing_left)
		xstep *= -1;
	if (data->facing_up)
		ystep *= -1;
	while (data->nexttouchx >= 0 && data->nexttouchx < data->clmn_n * TILE
		&& data->nexttouchy >= 0 && data->nexttouchy < data->rows_n * TILE)
	{
		x = data->nexttouchx;
		if (data->facing_left)
			x--;
		if (checking_collision3(data, x, data->nexttouchy)
			|| checking_collision_door3(data, x, data->nexttouchy))
		{
			data->foundverticalhit = true;
			data->ver_hit_x = data->nexttouchx;
			data->ver_hit_y = data->nexttouchy;
			break ;
		}
		data->nexttouchx += xstep;
		data->nexttouchy += ystep;
	}
}

void	draw_minimap(t_data *data)
{
	draw_minimap2(data, (data->player->sqaure_y / TILE) * TILE_SCALED - 4
		* TILE_SCALED, (data->player->sqaure_x / TILE)
		* TILE_SCALED - 6 * TILE_SCALED);
	draw_player(data, 6 * TILE_SCALED, 4 * TILE_SCALED, YELLOW);
	draw_direction(data, 6 * TILE_SCALED, 4 * TILE_SCALED);
}
