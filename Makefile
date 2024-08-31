NAME = cub3d
CC = cc
CFLAGS = -g
LIBS =  -L /Users/$(USER)/Desktop/cub_3d/MLX42/build -lmlx42 -lglfw -lglfw -L "/Users/$(USER)/homebrew/opt/glfw/lib" #-framework OpenGL -framework AppKit
INCLUDES = -I includes -I /usr/local/include -I ./MLX42/include
HEADER = $(addprefix includes/, cub3d.h)
M_SOURCES = $(addprefix sources/, main.c test.c)
M_OBJECTS = $(M_SOURCES:.c=.o)

%.o:%.c $(HEADER)
	$(CC) $(INCLUDES) $(CFLAGS) -c  $< -o $@

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) $(LIBS) -o $(NAME)
clean:
	rm -f $(M_OBJECTS)
fclean: clean
	rm -f $(NAME)
re: clean fclean all
norm:
	@norminette $(M_SOURCES) $(HEADER)
.PHONY:clean re fclean all
