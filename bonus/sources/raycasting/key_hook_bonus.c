/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/01 10:59:23 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	checking_collision(t_data *data, float x, float y)
{
	x = x / TILE;
	y = y / TILE;
	x = x * TILE_SCALED;
	y = y * TILE_SCALED;
	if (data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] && // check this to avoid segv near to wall
		(data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x - RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y - RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == '1' ||
		data->map.map[(int)((y + RADIUS2) / TILE_SCALED)]
		[(int)((x + RADIUS2) / TILE_SCALED)] == '1'))
			return (1);
	return (0);
}

void	key_hook_3(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player->angle -= ROTATE_ANGLE;
		if (data->player->angle < 0)
			data->player->angle = 2 * M_PI;
		draw_minimap(data);
		cast_rays(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player->angle += ROTATE_ANGLE;
		if (data->player->angle > M_PI * 2)
			data->player->angle = 0;
		draw_minimap(data);
		cast_rays(data);
	}
}

void	key_hook_2(t_data *data)
{
	float	new_x;
	float	new_y;

	if (data->d_key)
	{
		new_x = data->player->sqaure_x + cos(data->cast_angle + (M_PI / 2)) * MOVE_SPEED;
		new_y = data->player->sqaure_y + sin(data->cast_angle + (M_PI / 2)) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	if (data->s_key)
	{
		new_x = data->player->sqaure_x + cos(data->cast_angle + M_PI) * MOVE_SPEED;
		new_y = data->player->sqaure_y + sin(data->cast_angle + M_PI) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	key_hook_3(data);
}

void	my_key_hook(void *st)
{
	t_data	*data;
	float	new_x;
	float	new_y;

	data = (t_data *)st;
	if (data->w_key)
	{
		new_x = data->player->sqaure_x + cos(data->cast_angle ) * MOVE_SPEED;
		new_y = data->player->sqaure_y + sin(data->cast_angle ) * MOVE_SPEED;
		if (!checking_collision(data, new_x, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	if (data->a_key)
	{
		new_x = data->player->sqaure_x + cos(data->cast_angle - (M_PI / 2)) * MOVE_SPEED; // need to check this
		new_y = data->player->sqaure_y + sin(data->cast_angle - (M_PI / 2)) * MOVE_SPEED;
		if (!checking_collision(data, new_x - MOVE_SPEED, new_y))
		{
			data->player->sqaure_x = new_x;
			data->player->sqaure_y = new_y;
			draw_minimap(data);
			cast_rays(data);
		}
	}
	key_hook_2(data);
}