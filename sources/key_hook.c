/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/07 11:13:10 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision(t_data *data, float x, float y)
{
	if (data->map[(int)((y - RADIUS2) / TILE)]
		[(int)((x - RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y + RADIUS2) / TILE)]
		[(int)((x - RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y - RADIUS2) / TILE)]
		[(int)((x + RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y + RADIUS2) / TILE)]
		[(int)((x + RADIUS2) / TILE)] == '1')
		return (1);
	return (0);
}

int	up_down(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
	draw_direction(data, x, y);
	return (0);
}

int	left_right(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
	draw_direction(data, x, y);
	return (0);
}

void key_hook_3(mlx_key_data_t key, t_data *data)
{
	float	old_angle = data->player->angle;
	if (key.key == MLX_KEY_LEFT)
	{
		// Rotate player direction to the left
		data->player->angle -= ROTATE_ANGLE;
		if (data->player->angle < 0)
		    data->player->angle += 2 * M_PI; // Keep angle within [0, 2π]
		remove_direction(data, data->player->sqaure_x, data->player->sqaure_y, old_angle);
		draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	}
	else if (key.key == MLX_KEY_RIGHT)
	{
		data->player->angle += ROTATE_ANGLE;
		if (data->player->angle > 2 * M_PI)
			data->player->angle -= 2 * M_PI;
		
		// Redraw the direction
		remove_direction(data, data->player->sqaure_x, data->player->sqaure_y, old_angle);
		draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	}
	else if (key.key == MLX_KEY_ESCAPE)
	{
		write(1, "WINDOW CLOSED\n", 14);
		exit(0);
	}
}
void	key_hook_2(mlx_key_data_t key, t_data *data)
{
	int	i;

	i = 0;
	if (key.key == MLX_KEY_D)
	{
		while (i < MOVE_SPEED)
		{
			if (left_right(data->player->sqaure_x + 1,
					data->player->sqaure_y, data))
				return ;
			data->player->sqaure_x += 1;
			i++;
		}
	}
	else if (key.key == MLX_KEY_S || key.key == MLX_KEY_UP)
	{
		while (i < MOVE_SPEED)
		{
			if (up_down(data->player->sqaure_x,
					data->player->sqaure_y + 1, data))
				return ;
			data->player->sqaure_y += 1;
			i++;
		}
	}
	else
		key_hook_3(key, data);
}

void	my_key_hook(mlx_key_data_t key, void *st)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)st;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
	{
		while (i < MOVE_SPEED)
		{
			if (up_down(data->player->sqaure_x,
					data->player->sqaure_y - 1, data))
				return ;
			data->player->sqaure_y -= 1;
			i++;
		}
	}
	else if (key.key == MLX_KEY_A)
	{
		while (i < MOVE_SPEED)
		{
			if (left_right(data->player->sqaure_x - 1,
					data->player->sqaure_y, data))
				return ;
			data->player->sqaure_x -= 1;
			i++;
		}
	}
	else
		key_hook_2(key, data);
}
