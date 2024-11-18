NAME = cub3D
BONUS = cub3D_bonus
CC = cc
CFLAGS = -fsanitize=address -g
LIBFT_DIR = /Users/$(USER)/Desktop/cub_3d/libft
GNL_DIR = /Users/$(USER)/Desktop/cub_3d/gnl
LIBS2 = -L /Users/$(USER)/Desktop/cub_3d/MLX42/build -lmlx42 \
        -L /Users/$(USER)/homebrew/opt/glfw/lib -lglfw \
        -L /Users/$(USER)/Desktop/cub_3d/libft -lft \
        -L /Users/$(USER)/Desktop/cub_3d/gnl -lftgnl -Ofast
INCLUDES = -I includes -I MLX42/include/MLX42
B_INCLUDES = -I bonus/cub3d_bonus.h -I MLX42/include/MLX42
HEADER = includes/cub3d.h
B_HEADER = bonus/sources/cub3d_bonus.h

M_SOURCES = sources/raycasting/main.c sources/raycasting/key_hook.c sources/raycasting/render.c\
 			sources/raycasting/cal_hit.c sources/raycasting/cast_rays.c sources/raycasting/player_view.c\
			sources/parsing/parsing.c sources/parsing/parsing_v1.c sources/parsing/parsing_utils.c\
			sources/parsing/news_parse.c sources/parsing/f_c_parse.c sources/parsing/parsing_utils2.c\
			sources/parsing/parsing_utils3.c sources/parsing/map_starts.c sources/parsing/map_parse.c \
			sources/parsing/utils.c sources/raycasting/cast_rays_2.c

B_SOURCES = bonus/sources/raycasting/main_bonus.c bonus/sources/raycasting/key_hook_bonus.c\
			bonus/sources/raycasting/render_bonus.c bonus/sources/raycasting/cal_hit_bonus.c\
			bonus/sources/raycasting/cast_rays_bonus.c bonus/sources/raycasting/player_view_bonus.c \
			bonus/sources/parsing/parsing_bonus.c bonus/sources/parsing/parsing_v1_bonus.c\
			bonus/sources/parsing/parsing_utils_bonus.c bonus/sources/parsing/news_parse_bonus.c\
			bonus/sources/parsing/f_c_parse_bonus.c bonus/sources/parsing/parsing_utils2_bonus.c \
			bonus/sources/parsing/parsing_utils3_bonus.c bonus/sources/raycasting/draw_player_bonus.c\
			bonus/sources/raycasting/collision_bonus.c bonus/sources/parsing/utils_bonus.c \
			bonus/sources/parsing/map_starts_bonus.c bonus/sources/parsing/map_parse_bonus.c bonus/sources/raycasting/loading_anims_bonus.c\
			bonus/sources/raycasting/animation_bonus.c bonus/sources/raycasting/check_bonus.c

M_OBJECTS = $(M_SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

sources/%.o:sources/%.c $(HEADER)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

bonus/%.o:bonus/%.c $(B_HEADER)
	@$(CC) $(B_INCLUDES) $(CFLAGS) -c $< -o $@

all : $(NAME)


$(NAME): $(M_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) $(LIBS2) -o $(NAME)
	@echo the mandatory executable created successfully

bonus : $(BONUS)

$(BONUS): $(B_OBJECTS)
	@make bonus -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) -I bonus/cub3d_bonus.h -I MLX42/include/MLX42 $(B_OBJECTS) $(LIBS2) -o $(BONUS)
	@echo the bonus executable created successfully

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	@rm -f $(M_OBJECTS)
	@rm -f $(B_OBJECTS)
	@echo object files removed successfully

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	@rm -f $(NAME)
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo object files removed successfully
	@echo the executable file removed successfully

re: clean fclean all

.PHONY: clean re fclean all
