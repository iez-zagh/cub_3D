/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/01 20:17:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

void	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 800, 600);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}

void draw_minimap(char **map, void *mlx_ptr, void *win_ptr)
{
	int x, y;

	for (y = 0; y < 10; y++)
	{
		for (x = 0; x < 10; x++)
		{
			int color = (map[y][x] == 1) ? 0x000000 : 0xFFFFFF; // Black for wall, white for floor
			
			int draw_x = x * 10;
			int draw_y = y * 10;
			
			for (int dy = 0; dy < 10; dy++)
			{
				for (int dx = 0; dx < 10; dx++)
				{
					mlx_pixel_put_to_image(mlx_ptr, win_ptr, draw_x + dx, draw_y + dy, color);
				}
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*res;

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
	printf("%s\n", map); return (0);
	data.mlx = mlx_init(800, 600, "cub3d", 1);
	render(&data);
	return (0);
}
