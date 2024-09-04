/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/04 16:03:49 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	go_to(int x, int y, t_data *data)
{
	// if (data->map[y][x] == '1')
	// 	return (1);
	draw_player(data, data->player->player_x * 8, data->player->player_y * 8, WHITE);
	draw_player(data, x * 8, y * 8, RED);
	return (0);
}
void	my_key_hook(mlx_key_data_t key, void *st)
{
	t_data	*data;
	data = (t_data *)st;

	if (key.key == MLX_KEY_W)
	{
		if (go_to(data->player->player_x, data->player->player_y - 1, data))
			return ;
		data->player->player_y--;
	}
	if (key.key == MLX_KEY_A)
	{
		if (go_to(data->player->player_x - 1, data->player->player_y, data))
			return ;
		data->player->player_x--;
	}
	if (key.key == MLX_KEY_D)
	{
		if (go_to(data->player->player_x + 1, data->player->player_y, data))
			return ;
		data->player->player_x++;
	}
	if (key.key == MLX_KEY_S)
	{
		if (go_to(data->player->player_x, data->player->player_y + 1, data))
			return ;
		data->player->player_y++;
	}
	if (key.key == MLX_KEY_ESCAPE)
	{
		write(1, "WINDOW CLOSED\n", 14);
		exit (0);
	}
}
