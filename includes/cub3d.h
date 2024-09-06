/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/09/06 16:34:22 by iez-zagh         ###   ########.fr       */
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
#define MOVE_SPEED 7.0
#define radius 4.0
#define radius2 3.0

typedef struct s_player
{
	float		player_x;
	float		player_y;
	float		sqaure_x;
	float		sqaure_y;
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
void	draw_player(t_data *data, float draw_x, float draw_y, int color);
void	draw_player2(t_data *data, float draw_x, float draw_y, int color);
void	draw_direction(t_data *data);

#endif
