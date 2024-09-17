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

int	checking_collision(t_data *data, double x, double y)
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

int	up_down(double x, double y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE); //destroy the image and draw it again	
	draw_player2(data, x, y, RED);
	draw_direction(data, x, y);
	return (0);
}

int	left_right(double x, double y, t_data *data)
{
	if (checking_collision(data, x, y))
		return (1);
	remove_direction2(data, data->player->sqaure_x, data->player->sqaure_y);
	draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, WHITE);
	draw_player2(data, x, y, RED);
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
			data->player->angle = 2 * M_PI; // Keep angle within 0 and  2π) and need to musch under this
		remove_rays(data);
		remove_direction(data, data->player->sqaure_x, data->player->sqaure_y);
		data->cast_angle = data->player->angle;
		draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, RED); //need to reput the map every time i guess
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
		draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, RED);
		cast_rays(data);
		draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		//needs to release resources
		write(1, "WINDOW CLOSED\n", 14);
		exit(0);
	} 
}

void	key_hook_2(t_data *data)
{
	int	i;

	i = 0;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_S) || mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
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
	if (mlx_is_key_down(data->mlx, MLX_KEY_W) || mlx_is_key_down(data->mlx, MLX_KEY_UP))
	{
		i = 0;
		remove_rays(data);
		while (i < MOVE_SPEED)
		{
			if (checking_collision(data, data->player->sqaure_x, data->player->sqaure_y - 1))
				break ;
			if (up_down(data->player->sqaure_x,
					data->player->sqaure_y - 1, data))
				break ;
			data->player->sqaure_y -= 1;
			//think about this later
			// image = mlx_new_image(data->mlx, 1920, 960); 
			// data->player->sqaure_y -= 1;
			// draw_minimap(data);
			// draw_player2(data, data->player->sqaure_x, data->player->sqaure_y, RED);
			// draw_direction(data, data->player->sqaure_x, data->player->sqaure_y);
			// mlx_image_to_window(data->mlx, image, 0 , 0);
			// mlx_delete_image(data->mlx, data->img);
			// data->img = image;
			i++;
		}
		cast_rays(data);
	}
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
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
