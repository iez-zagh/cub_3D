/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/18 01:41:17 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	get_color(t_data *data, int x, int y)
{
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '1')
		return (BLACK);
	if ((data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '0')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'W')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'S')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'N')
		|| (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'E'))
		return (GRAY);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == '2')
		return (SHAPE);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'D')
		return (RED);
	if (data->map.map[y / TILE_SCALED][x / TILE_SCALED] == 'C')
		return (GREEN);
	return (WHITE);
}

void	draw_minimap2(t_data *data, int i, int u)
{
	int	y;
	int	x;
	int	j;

	y = 0;
	while (i <= (data->player->sqaure_y / TILE) * TILE_SCALED + 4 * TILE_SCALED)
	{
		j = u;
		x = 0;
		while (j <= (data->player->sqaure_x / TILE)
			* TILE_SCALED + 6 * TILE_SCALED)
		{
			if (!(x / TILE_SCALED > data->clmn_n || x / TILE_SCALED < 0
					|| y / TILE_SCALED > data->rows_n || y / TILE_SCALED < 0))
				mlx_put_pixel(data->img, x, y, get_color(data, j, i));
			j++;
			x++;
		}
		y++;
		i++;
	}
}

void	start_render(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	data->img = mlx_new_image(data->mlx, WIDTH / 2, HEIGHT / 2);
	if (convert_textures(data) < 0)
		return ;
	if (from_texture_to_image(data))
		return ;
	data->player_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->player->sqaure_x = data->player->x * TILE;
	data->player->sqaure_y = data->player->y * TILE;
	data->player->sqaure_x += TILE / 2;
	data->player->sqaure_y += TILE / 2;
	draw_minimap(data);
	cast_rays(data);
	mlx_image_to_window(data->mlx, data->player_img, 0, 0);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	mlx_image_to_window(data->mlx, data->tex.i_frames[0], 250, 350);
	mlx_key_hook(data->mlx, check_keys, data);
	mlx_loop_hook(data->mlx, my_key_hook, data);
	mlx_loop_hook(data->mlx, handle_mouse, data);
	mlx_loop(data->mlx);
}

void	free_all(t_data *data)
{
	free_frames(data, 36, 0);
	free_frames(data, 36, 1);
	ft_free_par(data->map.map);
	free_leaks(&data->map, 4);
	delete_images(data, 5);
}

int	main(int ac, char **av)
{
	t_data		data;
	int			stat;
	t_player	player;
	char		*map;

	map = NULL;
	if (ac != 2)
		return (printf("Usage: ./cub3D ./path_to_map\n"), 1);
	data.player = &player;
	stat = parsing(&data, av[1]);
	if (stat < 0)
		return (ft_free_par(data.map.map), stat);
	player.sqaure_x = player.x * TILE;
	player.sqaure_y = player.y * TILE;
	if (frames_loading(&data))
		return (ft_free_par(data.map.map), -1);
	start_render(&data);
	free_all(&data);
	return (0);
}
