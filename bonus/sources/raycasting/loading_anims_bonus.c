/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading_anims_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 20:52:33 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/17 01:10:00 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_frames(t_data *data, int i, int x)
{
	if (x == 1)
	{
		while (i >= 0)
		{
			mlx_delete_image(data->mlx, data->tex.i_frames[i]);
			i--;
		}
	}
	else
	{
		while (i >= 0)
		{
			mlx_delete_texture(data->tex.frames[i]);
			i--;
		}
	}
}

int	from_texture_to_image(t_data *data)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		data->tex.i_frames[i] = mlx_texture_to_image(data->mlx, data->tex.frames[i]);
		if (!data->tex.i_frames[i])
			return (free_frames(data, i, 1), free_frames(data, 7, 0),-1);
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
	while (i < 7)
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
			return (free(tmp), free(path), free_frames(data, i, 0), -1);
		free(tmp);
		free(path);
		i++;
	}
	return (0);
}
