/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:17:54 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 18:09:55 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->w_key = 1;
	if (key.action == MLX_RELEASE)
		data->w_key = 0;
}

void	a_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->a_key = 1;
	else if (key.action == MLX_RELEASE)
		data->a_key = 0;
}

void	d_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->d_key = 1;
	else if (key.action == MLX_RELEASE)
		data->d_key = 0;
}

void	s_key(mlx_key_data_t key, t_data *data)
{
	if (key.action == MLX_PRESS)
		data->s_key = 1;
	else if (key.action == MLX_RELEASE)
		data->s_key = 0;
}

void	check_keys(mlx_key_data_t key, void *data)
{
	data = (t_data *)data;
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		w_key(key, data);
	if (key.key == MLX_KEY_A)
		a_key(key, data);
	if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		s_key(key, data);
	if (key.key == MLX_KEY_D)
		d_key(key, data);
	if (key.key == MLX_KEY_ESCAPE)
	{
		free_all(data);
		write(1, "WINDOW CLOSED\n", 14);
		exit(0);
	}
}
