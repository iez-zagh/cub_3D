NAME = cub3d2
NAME2 = cub3d
CC = cc
# CFLAGS = -Wextra -Wall -Werror  --- do not forgot that
CFLAGS = -g -fsanitize=address
LIBFT_DIR = libft
GNL_DIR = gnl
LIBS =  libft/libft.a gnl/libftgnl.a
#LIBS2 =  -L /Users/$(USER)/Desktop/cub_3d/MLX42/build -lmlx42 -L "/Users/$(USER)/homebrew/opt/glfw/lib" -lglfw -L /Users/$(USER)/Desktop/cub_3d/libft -lft -L /Users/$(USER)/Desktop/cub_3d/gnl -lftgnl
LIBS2 = -L /Users/$(USER)/Desktop/cub_3d/libft -lft -L /Users/$(USER)/Desktop/cub_3d/gnl -lftgnl
INCLUDES = -I includes -I MLX42/include/MLX42
HEADER = $(addprefix includes/, cub3d.h)
M_SOURCES = $(addprefix sources/, main.c parsing.c parsing_utils.c parsing_v1.c f_c_parse.c news_parse.c )#key_hook.c render.c minimap.c cast_rays.c parsing.c)
M_OBJECTS = $(M_SOURCES:.c=.o)

%.o: %.c $(HEADER)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

mac : $(NAME2)
$(NAME2): $(M_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) -o $(NAME2) $(LIBS2) 

# linux : $(NAME)

# $(NAME): $(M_OBJECTS)
# 	@make -C $(LIBFT_DIR)
# 	@make -C $(GNL_DIR)
# 	$(CC) $(M_OBJECTS) $(LIBS) MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm -o $(NAME)
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	rm -f $(M_OBJECTS)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	rm -f $(NAME)
	rm -f $(NAME2)
re: clean fclean mac

norm:
	@norminette $(M_SOURCES) $(HEADER)
.PHONY:clean re fclean all
