/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/11/01 17:17:19 by iez-zagh         ###   ########.fr       */
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

# define RED 0xE11E00FF // need to know this later
# define BLUE 0x87CEFAFF
# define WHITE 0xFFFFFFFF
# define BLACK 0x00000FF
# define GRAY 0x808080FF
# define TILE 64
# define TILE_SCALED 28
# define MOVE_SPEED 5.0
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
}	t_player;

typedef struct s_data
{
	bool		w_key;
	bool		s_key;
	bool		d_key;
	bool		a_key;
	int			clmn_n;
	int			rows_n;
	int			strip_n;
	float		cast_angle;
	void		*mlx;
	mlx_image_t	*img;
	mlx_image_t	*player_img;
	t_map		map;
	t_player	*player;
}	t_data;


/*				raycasting					*/
// === === === === === === === === === //

void	my_key_hook(void *data);
void	start_render(t_data *data);
int		checking_collision(t_data *data, float x, float y);
void	draw_minimap(t_data *data);
void	cast_rays(t_data *data);
float	cast_ray(t_data *data, float x, float y);
void	check_keys(mlx_key_data_t key, void *data);
void	player_view(t_data *data, float dis);
int		checking_collision2(t_data *data, int x, int y);

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
int		check_directions(char **map, int i, int j);

void	angle_init(char c, t_data *data);
int		empty_line(char *line);
int		sec_char(char *tab, int i);

// === === === === === === === === === //

#endif