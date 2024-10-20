/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/11 22:35:35 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*res;
	int		stat;
	t_player player;

	char	*map = NULL;
	if (ac != 2)
		return (how_2_use(), 1);
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (stat);
	// player.sqaure_x = 4 * TILE;
	// player.sqaure_y = 3 * TILE;
	// data.player = &player;
	// start_render(&data);
	return (0);
}
