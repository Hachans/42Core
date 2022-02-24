# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edgars <edgars@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 22:32:09 by ekraujin          #+#    #+#              #
#    Updated: 2022/02/22 14:53:59 by edgars           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c utils1.c utils2.c checknget.c\

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

