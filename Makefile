NAME = cub3d2
NAME2 = cub3d
BONUS = cub3D_bonus
CC = cc
# CFLAGS = -fsanitize=address -Wextra -Wall -Werror 
LIBFT_DIR = libft
GNL_DIR = gnl
LIBS2 =  -L /Users/$(USER)/Desktop/cub_3d/MLX42/build -lmlx42 -L "/Users/$(USER)/homebrew/opt/glfw/lib" -lglfw -L /Users/$(USER)/Desktop/cub_3d/libft -lft -L /Users/$(USER)/Desktop/cub_3d/gnl -lftgnl   -Ofast
INCLUDES = -I includes -I MLX42/include/MLX42
B_INCLUDES = -I bonus/cub3d_bonus.h -I MLX42/include/MLX42
HEADER = includes/cub3d.h
B_HEADER = bonus/sources/cub3d_bonus.h

M_SOURCES = sources/raycasting/main.c sources/raycasting/key_hook.c sources/raycasting/render.c\
 			sources/raycasting/minimap.c sources/raycasting/cast_rays.c sources/raycasting/player_view.c\
			sources/parsing/parsing.c sources/parsing/parsing_v1.c sources/parsing/parsing_utils.c\
			sources/parsing/news_parse.c sources/parsing/f_c_parse.c sources/parsing/parsing_utils2.c\
			sources/parsing/parsing_utils3.c

B_SOURCES = bonus/sources/raycasting/main_bonus.c bonus/sources/raycasting/key_hook_bonus.c\
			bonus/sources/raycasting/render_bonus.c bonus/sources/raycasting/minimap_bonus.c\
			bonus/sources/raycasting/cast_rays_bonus.c bonus/sources/raycasting/player_view_bonus.c \
			bonus/sources/parsing/parsing_bonus.c bonus/sources/parsing/parsing_v1_bonus.c\
			bonus/sources/parsing/parsing_utils_bonus.c bonus/sources/parsing/news_parse_bonus.c\
			bonus/sources/parsing/f_c_parse_bonus.c bonus/sources/parsing/parsing_utils2_bonus.c \
			bonus/sources/parsing/parsing_utils3_bonus.c 

M_OBJECTS = $(M_SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

sources/%.o:sources/%.c $(HEADER)
	@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

bonus/%.o:bonus/%.c $(B_HEADER)
	@$(CC) $(B_INCLUDES) $(CFLAGS) -c $< -o $@

all : $(NAME2)
$(NAME2): $(M_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) $(LIBS2) -o $(NAME2)
	@echo the mandatory executable created successfully

bonus : $(BONUS)
$(BONUS): $(B_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	@$(CC) $(CFLAGS) -I bonus/cub3d_bonus.h -I MLX42/include/MLX42 $(B_OBJECTS) $(LIBS2) -o $(BONUS)
	@echo the bonus executable created successfully

# linux : $(NAME)
# $(NAME): $(M_OBJECTS)
# 	@make -C $(LIBFT_DIR)
# 	@make -C $(GNL_DIR)
# 	$(CC) $(M_OBJECTS) $(LIBS) MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME)

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
	@rm -f $(NAME2)
	@rm -f $(BONUS)
	@echo object files removed successfully
	@echo the executable file removed successfully

re: clean fclean all

norm:
	@norminette $(M_SOURCES) $(HEADER)

.PHONY: clean re fclean all