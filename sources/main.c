	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/21 11:09:24 by iez-zagh         ###   ########.fr       */
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
	int		stat;
	t_player player;

	char	*map = NULL;
	if (ac != 2)
		return (how_2_use(), 1);
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (stat);
	for (float i = 0;i < 15;i++)
	{
		for (float j=0;j<30;j++)
		{
			if (data.map.map[(int)i][(int)j] == 'W')
			{
				player.x = j;
				player.y = i;
				break ;
			}	
		}
	}
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;
	data.player = &player;
	start_render(&data);
	return (0);
}
