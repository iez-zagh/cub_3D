/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:27:38 by zmaghdao          #+#    #+#             */
/*   Updated: 2024/11/18 23:03:43 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

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
		if (i == 4)
			mlx_delete_texture(data->tex.door);
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
		if (i == 4)
			mlx_delete_image(data->mlx, data->tex.i_door);
		i++;
	}
}

int	is_forbidden(char c)
{
	if (c == 'D' || c == ' ' || c == '\0')
		return (1);
	return (0);
}
