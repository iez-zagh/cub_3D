/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:55:47 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 22:06:01 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_all(t_data *data)
{
	ft_free_par(data->map.map);
	if (data->mlx)
	{
		free_frames(data, 36, 1);
		free_frames(data, 36, 0);
		delete_images(data, 4);
		delete_texture(data, 4);
	}
}
