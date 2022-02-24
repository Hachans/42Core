# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 00:34:32 by ekraujin          #+#    #+#              #
#    Updated: 2022/02/02 12:12:19 by ekraujin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

SRC = so_long.c map_check.c error.c make_map.c hooks.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C mlx/
	$(CC) $(OBJ) mlx/libmlx.a libft/libft.a -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C mlx/
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all

.PHONY: all clean fclean re