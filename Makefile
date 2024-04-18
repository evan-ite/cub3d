# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 09:59:26 by elisevanite       #+#    #+#              #
#    Updated: 2024/04/18 15:32:03 by evan-ite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = src/libft/libft.a

SRC = src/main.c src/error.c src/parsing/parsing.c \
	src/parsing/utils.c

OBJ := $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	$(MAKE) -C src/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C src/libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C src/libft fclean

re: fclean all

.PHONY: all clean fclean re
