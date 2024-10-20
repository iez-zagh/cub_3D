/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/13 17:15:29 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define RED 0xE11E00FF
# define WHITE 0xFFFFFFFF
# define BLACK 0x00000FF
# define TILE 32
# define MOVE_SPEED 3.0
# define RADIUS 4.0
# define RADIUS2 3.0
# define ROTATE_ANGLE 0.05233333333
# define WIDTH	1200
# define HEIGHT	700
// # define ROTATE_ANGLE 0.05233333333/

typedef struct s_map
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*fcolor;
	int			color_f;
	char		*ccolor;
	int			color_c;
	int			news[4];
	int			crgb[3];
	int			frgb[3];
	char		**map;
	char		**table;
}	t_map;

typedef struct s_player
{
	float		angle;
	float		old_angle;
	float		sqaure_x;
	float		sqaure_y;
}	t_player;

typedef struct s_data
{
	float		cast_angle;
	void		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*player_img;
	t_map		map;
	t_player	*player;
}	t_data;

void	my_key_hook(void *data);
void	start_render(t_data *data);
void	draw_player(t_data *data, float draw_x, float draw_y, int color);
void	draw_player2(t_data *data, float draw_x, float draw_y, int color);
void	draw_direction(t_data *data, float x, float y);
void	remove_direction(t_data *data, float x, float y);
void	remove_direction2(t_data *data, float x, float y);
int		checking_collision(t_data *data, float x, float y);
void	draw_minimap(t_data *data);
void	cast_rays(t_data *data);
void	cast_lines(t_data *data, float x, float y);
void	remove_rays(t_data *data);
void	remove_direction3(t_data *data, float x, float y);

/*				parsing				*/

int		parsing(t_data *data, char mapname[]);
int		check_table(t_data *data);
void	inisialize_vars(t_data *data);
void	ft_free_par(char **tab);
void	perreur(int x);
int		ft_isspace(char c);
int		f_c_checker(t_map *map);
int		check_news_ptrs(char *coor, char *str, t_map *map);


#endif
