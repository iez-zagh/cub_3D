/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:54:13 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/31 16:38:58 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void how_2_use(void)
{
    printf("Usage: ./cub3D ./path_to_map\n");
}
int main(int ac, char **av)
{
	(void)av;
	if (ac == 1)
		return (how_2_use(), 1);
	just_test();
	void *mlx = mlx_init(800, 600, "cub3d", 1);
	// mlx_image_to_window(mlx)
		
	mlx_image_t *win = mlx_new_image(mlx, 800, 600);
		
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return 0;
}