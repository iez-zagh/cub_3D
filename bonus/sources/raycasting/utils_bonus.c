/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utis_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:47 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 17:55:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_all(t_data *data)
{
	if (data->mlx)
	{
		free_frames(data, 36, 1);
		free_frames(data, 36, 0);
	}
	ft_free_par(data->map.map);
	free_leaks(&data->map, 4);
	if (data->mlx)
		delete_images(data, 5);
}
