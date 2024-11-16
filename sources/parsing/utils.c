/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:22:31 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/16 20:39:57 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_leaks(t_map *map, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			free(map->north);
		if (i == 1)
			free(map->west);
		if (i == 2)
			free(map->east);
		if (i == 3)
			free(map->south);
		i++;
	}
}

void	delete_texture(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i <= x)
	{
		if (i == 0)
			mlx_delete_texture(data->tex.north);
		if (i == 1)
			mlx_delete_texture(data->tex.south);
		if (i == 2)
			mlx_delete_texture(data->tex.west);
		if (i == 3)
			mlx_delete_texture(data->tex.east);
		i++;
	}
}

void	delete_images(t_data *data, int x)
{
	int	i;

	i = 0;
	while (i <= x)
	{
		if (i == 0)
			mlx_delete_image(data->mlx, data->tex.i_north);
		if (i == 1)
			mlx_delete_image(data->mlx, data->tex.i_south);
		if (i == 2)
			mlx_delete_image(data->mlx, data->tex.i_west);
		if (i == 3)
			mlx_delete_image(data->mlx, data->tex.i_east);
		i++;
	}
}
