NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
# CUBHEADER = -I includes
INCLUDES = -I includes -I /usr/local/include
HEADER = $(addprefix includes/, cub3d.h)
M_SOURCES = $(addprefix sources/, main.c test.c)
M_OBJECTS = $(M_SOURCES:.c=.o)

%.o:%.c $(HEADER)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(M_OBJECTS) $(CUBHEADER) -o $(NAME)
clean:
	rm -f $(M_OBJECTS)
fclean: clean
	rm -f $(NAME)
re: clean fclean all
.PHONY:clean re fclean all