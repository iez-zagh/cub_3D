/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/02 14:06:43 by iez-zagh         ###   ########.fr       */
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
}

void draw_minimap(char **map, t_data *data)
{
	int x, y;

	for (y = 0; y < 14; y++)
	{
		for (x = 0; x < 29; x++)
		{
			int color = (map[y][x] == '1') ? 0x000000FF : 0xFFFFFFFF;
			int draw_x = x * 20;
			int draw_y = y * 20;
			for (int dy = 0; dy < 20; dy++)
			{
				for (int dx = 0; dx < 20; dx++)
				{
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
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
	data.mlx = mlx_init(800, 600, "cub3d", 1);
	char **map_ = ft_split(map, '\n');
	render(&data);
	draw_minimap(map_, &data);
	mlx_image_to_window(data.mlx, data.img, 0 , 0);
	mlx_loop(data.mlx);
	return (0);
}
