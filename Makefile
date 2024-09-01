NAME = cub3d
CC = cc
CFLAGS = -Wextra -Wall -Werror
LIBFT_DIR = libft
GNL_DIR = gnl
LIBS =  -L /Users/$(USER)/Desktop/cub_3d/MLX42/build -lmlx42 -L "/Users/$(USER)/homebrew/opt/glfw/lib" -lglfw -L /Users/$(USER)/Desktop/cub_3d/libft -lft -L /Users/$(USER)/Desktop/cub_3d/gnl -lftgnl
INCLUDES = -I includes -I /usr/local/include -I ./MLX42/include
HEADER = $(addprefix includes/, cub3d.h)
M_SOURCES = $(addprefix sources/, main.c test.c)
M_OBJECTS = $(M_SOURCES:.c=.o)

%.o:%.c $(HEADER)
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o $@

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	@make -C $(LIBFT_DIR)
	@make -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) $(LIBS) -o $(NAME)
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(GNL_DIR)
	rm -f $(M_OBJECTS)
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(GNL_DIR)
	rm -f $(NAME)
re: clean fclean all
norm:
	@norminette $(M_SOURCES) $(HEADER)
.PHONY:clean re fclean all
