/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/06 17:45:04 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision(t_data *data, float x, float y)
{
	if (data->map[(int)((y - radius2) / TILE)][(int)((x - radius2) / TILE)] == '1' ||
		data->map[(int)((y + radius2) / TILE)][(int)((x - radius2) / TILE)] == '1' ||
		data->map[(int)((y - radius2) / TILE)][(int)((x + radius2) / TILE)] == '1' ||
		data->map[(int)((y + radius2) / TILE)][(int)((x + radius2) / TILE)] == '1') 
		return (1);
	return (0);
}

int	up_down(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
	draw_direction(data, x, y);
	return (0);
}

int	left_right(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
	draw_direction(data, x, y);
	return (0);
}

void	key_hook_2(mlx_key_data_t key, t_data *data)
{

	if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
	{
		int i = 0;
		while (i < MOVE_SPEED)
		{	
			if (left_right(data->player->sqaure_x + 1, data->player->sqaure_y, data))
				return ;
			data->player->sqaure_x += 1;
			i++;
		}
	}
	else if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
	{
		int i = 0;
		while (i < MOVE_SPEED)
		{	
			if (up_down(data->player->sqaure_x, data->player->sqaure_y + 1, data))
				return ;
			data->player->sqaure_y += 1;
			i++;
		}
	}
	else if (key.key == MLX_KEY_ESCAPE)
	{
		write(1, "WINDOW CLOSED\n", 14);
		exit (0);
	}
}

void	my_key_hook(mlx_key_data_t key, void *st)
{
	t_data	*data;

	data = (t_data *)st;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
	{
		int i = 0;
		while (i < MOVE_SPEED)
		{
			if (up_down(data->player->sqaure_x, data->player->sqaure_y - 1, data))
				return ;
			data->player->sqaure_y -= 1;
			i++;
		}
	}
	else if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
	{
		int i = 0;
		while (i < MOVE_SPEED)
		{
			if (left_right(data->player->sqaure_x - 1, data->player->sqaure_y, data))
				return ;
			data->player->sqaure_x -= 1;
			i++;
		}
	}
	key_hook_2(key, data);
}
