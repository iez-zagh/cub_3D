/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/05 18:10:29 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

#define RED 0xE11E00FF
#define WHITE 0xFFFFFFFF
#define BLACK 0x00000FF
#define TILE 32
#define MOVE_SPEED 5

typedef struct s_player
{
	int		player_x;
	int		player_y;
	int		sqaure_x;
	int		sqaure_y;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	mlx_image_t	*img;
	char		**map;
	t_player	*player;
}	t_data;

void	my_key_hook(mlx_key_data_t key, void *data);
void	start_render(t_data *data);
void	draw_player(t_data *data, int draw_x, int draw_y, int color);
void	draw_player2(t_data *data, int draw_x, int draw_y, int color);

#endif