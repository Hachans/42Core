# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 14:08:47 by ekraujin          #+#    #+#              #
#    Updated: 2022/01/10 21:40:16 by ekraujin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a

SRC = get_next_line.c get_next_line_utils.c \

SRC_BONUS = get_next_line_bonus_utils.c get_next_line_bonus.c \ 

OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(SRC_BONUS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE

$(NAME): $(OBJ) 
	ar rcs $(NAME) $(OBJ)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re