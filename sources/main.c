/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/01 16:11:38 by iez-zagh         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_data	data;

	char *res = get_next_line(0);
	printf("%s]]\n", res);return 0;
	if (ac == 1)
		return (how_2_use(), 1);
	just_test();
	data.mlx = mlx_init(800, 600, "cub3d", 1);
	render(&data);
	return (0);
}
