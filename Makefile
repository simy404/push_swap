# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamir <hsamir@student.42kocaeli.com.tr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 17:07:47 by hsamir            #+#    #+#              #
#    Updated: 2025/01/04 22:42:43 by hsamir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = push_swap.c \
src/commands/swap.c \
src/commands/push.c \
src/commands/rotate.c \
src/commands/reverse_rotate.c \
src/utils/print_utils.c \
src/utils/argument_utils.c \
src/utils/input_validation_utils.c \
src/utils/stack_utils.c \
src/utils/conversions_utils.c

CC = clang
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C libft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
