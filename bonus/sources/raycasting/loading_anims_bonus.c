/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_anims_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:52:33 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/18 16:15:17 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_frames(t_data *data, int i, int x)
{
	if (x == 1)
	{
		while (i >= 0)
		{
			if (data->tex.i_frames[i])
				mlx_delete_image(data->mlx, data->tex.i_frames[i]);
			data->tex.i_frames[i] = NULL;
			i--;
		}
	}
	else if (x == 0)
	{
		while (i >= 0)
		{
			if (data->tex.frames[i])
				mlx_delete_texture(data->tex.frames[i]);
			data->tex.frames[i] = NULL;
			i--;
		}
	}
}

int	from_texture_to_image(t_data *data)
{
	int	i;

	i = 0;
	while (i < 36)
	{
		data->tex.i_frames[i] = mlx_texture_to_image(data->mlx,
				data->tex.frames[i]);
		if (!data->tex.i_frames[i])
			return (free_frames(data, (i - 1), 1), free_frames(data, 36, 0), -1);
		i++;
	}
	return (0);
}

int	frames_loading(t_data *data)
{
	int		i;
	char	*path;
	char	*tmp;

	i = 0;
	while (i < 36)
	{
		tmp = ft_itoa(i);
		if (!tmp)
			return (-1);
		tmp = ft_strjoin(tmp, ".png");
		if (!tmp)
			return (-1);
		path = ft_strjoin(ft_strdup("sprites_anime/"), tmp);
		if (!path)
			return (free(tmp), free_frames(data, i, 0), -1);
		data->tex.frames[i] = mlx_load_png(path);
		if (!data->tex.frames[i])
			return (free(tmp), free(path), free_frames(data, (i - 1), 0), -1);
		free(tmp);
		free(path);
		i++;
	}
	return (0);
}

void	draw_direction(t_data *data, float x, float y)
{
	float	dir_x;
	float	dir_y;
	float	i;

	dir_x = cos(data->player->angle);
	dir_y = sin(data->player->angle);
	i = 0;
	while (i < 20)
	{
		if (checking_collision2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i))
			|| checking_collision_door2(data, (data->player->sqaure_x / TILE)
				* TILE_SCALED
				+ (dir_x * i), (data->player->sqaure_y / TILE) * TILE_SCALED
				+ (dir_y * i)))
			return ;
		mlx_put_pixel(data->img, x + (dir_x * i), y + (dir_y * i), BLACK);
		i++;
	}
}

float	distance_calcul(float x, float y, float x1, float y1)
{
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}
