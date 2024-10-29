/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 14:02:03 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/10/29 11:26:57 by iez-zagh         ###   ########.fr       */
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
# define RADIUS 3.0
# define RADIUS2 2.0
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

void	my_key_hook(void *data);
void	start_render(t_data *data);
void	draw_player(t_data *data, float draw_x, float draw_y, int color);
void	draw_player2(t_data *data, float draw_x, float draw_y, int color);
void	draw_direction(t_data *data, float x, float y);
int		checking_collision(t_data *data, float x, float y);
void	draw_minimap(t_data *data);
void	cast_rays(t_data *data);
float	cast_ray(t_data *data, float x, float y);
void	check_keys(mlx_key_data_t key, void *data);
void	player_view(t_data *data, float dis);
int		checking_collision2(t_data *data, int x, int y);
void 	draw_minimap2(t_data *data);
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



// for (float y = 0; y < 6; y++)
// 	{
// 		int x1 = k;
// 		for (float x = 0; x < 8; x++)
// 		{
// 			// printf("%c", data->map[(int)y1][(int)x1]);
// 			if (data->map.map[(int)y1][(int)x1] == '1')
// 				color = BLACK;
// 			else
// 				color = WHITE;
// 			float draw_x = x * TILE;
// 			float draw_y = y * TILE;
// 			for (int dy = 0; dy < TILE; dy++)
// 			{
// 				for (int dx = 0; dx < TILE; dx++)
// 					mlx_put_pixel(data->img, draw_x + dx, draw_y + dy, color);
// 			}
// 			x1++;
// 		}
// 		y1++;
// 	}