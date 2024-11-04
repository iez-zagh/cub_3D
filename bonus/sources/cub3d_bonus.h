/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmaghdao <zmaghdao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/04 21:43:22 by zmaghdao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <MLX42.h>
# include "../../libft/libft.h"
# include "../../gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define RED 0xE11E00FF // need to know this later
# define BLUE 0x87CEFAFF
# define WHITE 0xFFFFFFFF
# define BLACK 0x00000FF
# define GRAY 0x808080FF
# define TILE 64
# define TILE_SCALED 28
# define MOVE_SPEED 5.0
# define ROTATE_SPEED 0.05
# define RADIUS 4.0
# define RADIUS2 4.0
# define ROTATE_ANGLE 2.0 * (M_PI / 180)
# define WIDTH	1200
# define HEIGHT	700
# define FOV_ANGLE 60.0 * (M_PI / 180)

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
	float		sqaure_x;
	float		sqaure_y;
	float		x;
	float		y;
	float		map_x;
	float		map_y;
	int			mouse_x;
	int			mouse_y;
}	t_player;

typedef struct s_data
{
	bool		w_key;
	bool		s_key;
	bool		d_key;
	bool		a_key;
	bool		sub_key;
	bool		add_key;
	int			clmn_n;
	int			rows_n;
	int			strip_n;
	float		cast_angle;
	void		*mlx;
	bool		found_horz_hit;
	bool		foundverticalhit;
	float		hor_hit_x;
	float		hor_hit_y;
	float		ver_hit_x;
	float		ver_hit_y;
	float		xintercept;
	float		yintercept;
	float		nexttouchX;
	float		nexttouchY;
	float		wall_dis;
	float		wall_height;
	float		mouse_sensive;
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
int		checking_collision(t_data *data, float x, float y);
void	draw_minimap(t_data *data);
void	cast_rays(t_data *data);
void	cast_ray(t_data *data);
void	check_keys(mlx_key_data_t key, void *data);
void	player_view(t_data *data);
int		checking_collision2(t_data *data, int x, int y);
void	draw_minimap2(t_data *data, int i, int u);
void	handle_mouse(void *d);
int		checking_collision3(t_data *data, int x, int y);
float	distance_calcul(float x, float y, float x1, float y1);
void	my_key_hook5(t_data *data);
void	sub_key(mlx_key_data_t key, t_data *data);
void	add_key(mlx_key_data_t key, t_data *data);

/*				parsing					*/
// === === === === === === === === === //
int		parsing(t_data *data, char mapname[]);
int		check_table(t_data *data);
void	inisialize_vars(t_data *data);
void	ft_free_par(char **tab);
void	perreur(int x);
int		ft_isspace(char c);
int		f_c_checker(t_map *map);
int		check_news_ptrs(char *coor, char *str, t_map *map);

int		map_lines(char **tab, int i);
int		largest_line(char **map);
void	spacetotwo(char **map);
int		is_map_char(char c);
int 	check_directions(char **map, int i, int j, int x);

void	angle_init(char c, t_data *data);
int		sec_char(char *tab, int i);
int 	is_player(char c);
// === === === === === === === === === //

#endif