	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 12:04:14 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/14 09:49:16 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	checking_collision(t_data *data, float x, float y)
{
	if (data->map[(int)((y - RADIUS2) / TILE)]
		[(int)((x - RADIUS2) / TILE)] && // check this to avoid segv near to wall
		(data->map[(int)((y - RADIUS2) / TILE)]
		[(int)((x - RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y + RADIUS2) / TILE)]
		[(int)((x - RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y - RADIUS2) / TILE)]
		[(int)((x + RADIUS2) / TILE)] == '1' ||
		data->map[(int)((y + RADIUS2) / TILE)]
		[(int)((x + RADIUS2) / TILE)] == '1'))
			return (1);
	return (0);
}

int	up_down(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE, data->img); //destroy the image and draw it again	
	draw_player2(data, x, y, RED, data->img);
	draw_direction(data, x, y);
	return (0);
}

int	left_right(float x, float y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE, data->img);
	draw_player2(data, x, y, RED, data->img);
	draw_direction(data, x, y);
	return (0);
}

void	key_hook_3(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		data->player->old_angle = data->player->angle;
		data->player->angle -= ROTATE_ANGLE;
		if (data->player->angle < 0)
			data->player->angle = 2 * M_PI; // Keep angle within 0 and  180 and need to musch under this
		remove_rays(data);
		remove_direction(data, data->player->sqaure_x, data->player->sqaure_y);
		data->cast_angle = data->player->angle;
		draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, RED, data->img); //need to reput the map every time i guess
		cast_rays(data);
		draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		data->player->old_angle = data->player->angle;
		data->player->angle += ROTATE_ANGLE;
		if (data->player->angle > M_PI * 2)
			data->player->angle = 0;
		remove_rays(data);
		remove_direction(data, data->player->sqaure_x, data->player->sqaure_y);
		data->cast_angle = data->player->angle;
		draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, RED, data->img);
		cast_rays(data);
		draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	}
}

void	key_hook_2(t_data *data)
{
	int	i;

	i = 0;
	if (data->d_key)
	{
		remove_rays(data);
		while (i < MOVE_SPEED)
		{
			if (left_right(data->player->sqaure_x + 1,
					data->player->sqaure_y, data))
				break ;
			data->player->sqaure_x += 1;
			i++;
		}
		cast_rays(data);
	}
	if (data->s_key)
	{
		remove_rays(data);
		while (i < MOVE_SPEED)
		{
			if (up_down(data->player->sqaure_x,
					data->player->sqaure_y + 1, data))
				break ;
			data->player->sqaure_y += 1;
			i++;
		}
		cast_rays(data);
	}
	key_hook_3(data);
}

void	my_key_hook(void *st)
{
	t_data	*data;
	int		i;

	i = 0;
	data = (t_data *)st;
	if (data->w_key)
	{
		if (!checking_collision(data, data->player->sqaure_x, data->player->sqaure_y - MOVE_SPEED))
		{
			mlx_delete_image(data->mlx, data->img);
			data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
			data->player->sqaure_y -= MOVE_SPEED;
			draw_minimap(data);
			draw_player(data, data->player->sqaure_x, data->player->sqaure_y, RED);
			cast_rays(data);
			draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
			mlx_image_to_window(data->mlx, data->img, 0, 0);
		}


		// i = 0;
		// remove_rays(data);
		// while (i < MOVE_SPEED)
		// {
		// 	if (checking_collision(data, data->player->sqaure_x, data->player->sqaure_y - 1))
		// 		break ;
		// 	if (up_down(data->player->sqaure_x,
		// 			data->player->sqaure_y - 1, data))
		// 		break ;
		// 	data->player->sqaure_y -= 1;
		// 	i++;
		// }
		// cast_rays(data);
	}
	if (data->a_key)
	{
		i = 0;
		remove_rays(data);
		while (i < MOVE_SPEED)
		{
			if (checking_collision(data, data->player->sqaure_x - 1, data->player->sqaure_y))
				break ;
			if (left_right(data->player->sqaure_x - 1,
					data->player->sqaure_y, data))
				break ;
			data->player->sqaure_x -= 1;
			i++;
		}
		cast_rays(data);
	}
	key_hook_2(data);
}
