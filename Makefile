# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 09:59:26 by elisevanite       #+#    #+#              #
#    Updated: 2024/05/22 16:44:15 by jstrozyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
CFLAGS_NM = -Wall -Werror -Wextra -D HIDE_MOUSE=1 -g
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz -fsanitize=address
# LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = src/libft/libft.a

SRC = src/main.c src/error.c src/print.c src/free.c \
	src/parsing/parsing.c src/parsing/utils.c src/parsing/color.c src/parsing/map.c \
	src/parsing/valid_map.c src/parsing/walls.c src/parsing/valid_kim.c \
	src/game/start_game.c src/game/init.c src/game/draw.c \
	src/game/pixels.c src/dda/dda.c src/game/input.c \
	src/dda/dda_utils.c src/game/move.c src/game/collision.c \
	src/features/minimap.c src/parsing/textures.c src/features/kim.c \
	src/features/doors.c src/dda/dda_objects.c src/features/kim_utils.c \
	src/features/photo.c

OBJ := $(SRC:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LFLAGS)

libft:
	$(MAKE) -C src/libft

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

no_mouse: $(OBJ:.o=_nm.o) libft
	$(CC) $(CFLAGS_NM) -o $(NAME) $(OBJ:.o=_nm.o) $(LIBFT) $(LFLAGS)

%_nm.o: %.c
	$(CC) $(CFLAGS_NM) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ:.o=_nm.o)
	$(MAKE) -C src/libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C src/libft fclean

re: fclean all

.PHONY: all clean fclean re

