/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/05 17:06:21 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	go_to(int x, int y, t_data *data)
{
	printf("%d]]\n%d]]\n", y / TILE, x / TILE);
	if (data->map[y / TILE][x / TILE] == '1')
		return (puts("here"), 1);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
	return (0);
}
void	my_key_hook(mlx_key_data_t key, void *st)
{
	t_data	*data;
	data = (t_data *)st;

	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
	{
		if (go_to(data->player->sqaure_x, data->player->sqaure_y - MOVE_SPEED, data))
			return ;
		data->player->sqaure_y -= MOVE_SPEED;
		
	}
	if (key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
	{
		if (go_to(data->player->sqaure_x - MOVE_SPEED, data->player->sqaure_y, data))
			return ;
		data->player->sqaure_x -= MOVE_SPEED;
	}
	if (key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
	{
		if (go_to(data->player->sqaure_x + MOVE_SPEED, data->player->sqaure_y, data))
			return ;
		data->player->sqaure_x += MOVE_SPEED;
	}
	if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
	{
		if (go_to(data->player->sqaure_x, data->player->sqaure_y + MOVE_SPEED, data))
			return ;
		data->player->sqaure_y += MOVE_SPEED;
	}
	if (key.key == MLX_KEY_ESCAPE)
	{
		write(1, "WINDOW CLOSED\n", 14);
		exit (0);
	}
}
