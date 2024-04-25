# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 09:59:26 by elisevanite       #+#    #+#              #
#    Updated: 2024/04/25 17:39:33 by jstrozyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = src/libft/libft.a

SRC = src/main.c src/error.c src/print.c \
	src/parsing/parsing.c src/parsing/utils.c src/parsing/color.c src/parsing/map.c \
	src/parsing/valid_map.c src/parsing/walls.c \
	src/game/start_game.c src/game/init.c src/game/draw.c \
	src/game/pixels.c src/game/game_utils.c src/dda/dda.c

OBJ := $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LFLAGS)

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
