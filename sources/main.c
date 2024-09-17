/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/17 14:53:38 by iez-zagh         ###   ########.fr       */
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
	t_player player;

	char	*map = NULL;
	if (ac != 2)
		return (how_2_use(), 1);
	int fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "error opening map file\n", 23), 1);
	while (1)
	{
		res = get_next_line(fd);
		if (!res)
			break ;
		map = ft_strjoin(map, res);
		if (!map)
			return (write(2, "some thing went wrong\n", 22), 1);
		free(res);
	}
	data.map = ft_split(map, '\n');
	player.sqaure_x = 4 * TILE;
	player.sqaure_y = 3 * TILE;
	data.player = &player;
	start_render(&data);
	return (0);
}
