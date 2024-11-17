/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/17 01:59:26 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	my_key_hook4(t_data *data)
{
	float	new_x;
	float	new_y;

	if (data->a_key)
	{
		new_x = data->player->sqaure_x
			+ cos(data->cast_angle - (M_PI / 2)) * MOVE_SPEED;
		new_y = data->player->sqaure_y
			+ sin(data->cast_angle - (M_PI / 2)) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y)
			&& !checking_collision_door(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player->angle -= ROTATE_ANGLE;
		draw_minimap(data);
		cast_rays(data);
	}
	my_key_hook5(data);
}

void	key_hook_3(t_data *data)
{
	float	new_x;	
	float	new_y;	

	if (data->player->angle > M_PI * 2)
		data->player->angle = 0;
	if (data->player->angle < 0)
		data->player->angle = 2 * M_PI;
	if (data->s_key)
	{
		new_x = data->player->sqaure_x
			+ cos(data->cast_angle + M_PI) * MOVE_SPEED;
		new_y = data->player->sqaure_y
			+ sin(data->cast_angle + M_PI) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y)
			&& !checking_collision_door(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	my_key_hook4(data);
}

void	key_hook_2(t_data *data)
{
	float	new_x;
	float	new_y;

	if (data->d_key)
	{
		new_x = data->player->sqaure_x
			+ cos(data->cast_angle + (M_PI / 2)) * MOVE_SPEED;
		new_y = data->player->sqaure_y
			+ sin(data->cast_angle + (M_PI / 2)) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y)
			&& !checking_collision_door(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player->angle += ROTATE_ANGLE;
		draw_minimap(data);
		cast_rays(data);
	}
	key_hook_3(data);
}

void	handle_mouse(void *d)
{
	int		last_position;
	float	direction;
	t_data	*data;

	data = (t_data *)d;
	last_position = data->player->mouse_x;
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	if (data->player->mouse_x > WIDTH || data->player->mouse_x < 0)
		mlx_set_mouse_pos(data->mlx, WIDTH / 2, data->player->mouse_y);
	mlx_get_mouse_pos(data->mlx, &data->player->mouse_x,
		&data->player->mouse_y);
	if (last_position != data->player->mouse_x)
	{
		if (data->player->mouse_x > last_position)
			direction = data->mouse_sensive;
		else
			direction = -data->mouse_sensive;
		data->player->angle += direction * ROTATE_ANGLE;
		draw_minimap(data);
		cast_rays(data);
	}
}

void	run_animation(t_data *data)
{
	static int	i = 0;

	if (i == 7)
		i = 0;
	if (data->frames == 7)
	{
		mlx_image_to_window(data->mlx, data->tex.i_frames[i], 250, 350);
		if (i == 6)
			data->animation = 0;
		if (i > 0)
		{
			mlx_delete_image(data->mlx, data->tex.i_frames[i - 1]);
			data->tex.i_frames[i - 1] = mlx_texture_to_image(data->mlx, data->tex.frames[i - 1]);
		}
		else
		{
			mlx_delete_image(data->mlx, data->tex.i_frames[6]);
			data->tex.i_frames[6] = mlx_texture_to_image(data->mlx, data->tex.frames[6]);
		}
		i++;
		data->frames = 0;
	}
	data->frames++;
}

void	my_key_hook(void *st)
{
	t_data	*data;
	float	new_x;
	float	new_y;

	data = (t_data *)st;
	if (data->w_key)
	{
		new_x = data->player->sqaure_x
			+ cos(data->cast_angle) * MOVE_SPEED;
		new_y = data->player->sqaure_y
			+ sin(data->cast_angle) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y)
			&& !checking_collision_door(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data); // why this
			cast_rays(data);
		}
	}
	if(data->animation)
	{
		run_animation(data);
	}
	key_hook_2(data);
}
