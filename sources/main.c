/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/03 17:23:36 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	how_2_use(void)
{
	printf("Usage: ./cub3D ./path_to_map\n");
}

void	render(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 1200, 720);
}

void	draw_player(t_data *data, int draw_x, int draw_y)
{
	int	r;
	int	x;
	int	y;

	r = 4;
	y = -r;
	while (y <= r)
	{
		x = -r;
		while (x <= r)
		{
			if (x * x + y * y < r * r)
				mlx_put_pixel(data->img, draw_x + x + 20, 20 + draw_y + y, RED);
			x++;
		}
		y++;
	}
}

void draw_minimap(t_data *data)
{
	int x, y;

	for (y = 0; y < 15; y++)
	{
		for (x = 0; x < 30; x++)
		{
			int color = (data->map[y][x] == '1') ? BLACK : WHITE;
			int draw_x = x * 40;
			int draw_y = y * 40;
			for (int dy = 0; dy < 40; dy++)
			{
				for (int dx = 0; dx < 40; dx++)
					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
			}
			if (data->map[y][x] == 'W' || data->map[y][x] == 'E' || data->map[y][x] == 'S' || data->map[y][x] == 'N')
				draw_player(data, draw_x, draw_y);
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
	data.mlx = mlx_init(1200, 720, "cub3d", 1);
	data.map = ft_split(map, '\n');
	render(&data);
	draw_minimap(&data);
	mlx_image_to_window(data.mlx, data.img, 0 , 0);
	mlx_loop(data.mlx);
	return (0);
}
