# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/01 16:03:47 by iez-zagh          #+#    #+#              #
#    Updated: 2024/09/01 16:06:29 by iez-zagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftgnl.a
FLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rc
RM = rm -f

SRC  =  get_next_line.c get_next_line_utils.c
OBJS = $(SRC:.c=.o)
all:  $(NAME)
%.o : %.c get_next_line.h
	$(CC) $(FLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY:re clean fclean all