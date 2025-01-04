# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 17:07:47 by hsamir            #+#    #+#              #
#    Updated: 2025/01/04 15:00:18 by hsamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = push_swap.c src/commands/swap.c src/commands/push.c src/commands/rotate.c src/utils/print_utils.c
CC = clang
FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -g $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
