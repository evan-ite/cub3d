# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 11:18:30 by jstrozyk          #+#    #+#              #
#    Updated: 2024/06/03 11:20:41 by jstrozyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME_BONUS = cub3D_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_BONUS = -Wall -Werror -Wextra -D BONUS=1
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = src/libft/libft.a

SRC = src/main.c src/error.c src/free.c \
	src/parsing/parsing.c src/parsing/utils.c src/parsing/color.c src/parsing/map.c \
	src/parsing/valid_map.c src/parsing/walls.c src/parsing/valid_sprites.c \
	src/game/start_game.c src/game/init.c src/game/draw.c \
	src/game/pixels.c src/dda/dda.c src/game/input.c \
	src/dda/dda_utils.c src/game/move.c src/game/collision.c \
	src/features/minimap.c src/parsing/textures.c src/features/sprites.c \
	src/features/doors.c src/dda/dda_objects.c src/features/sprite_utils.c \
	src/features/photo.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC:.c=_bonus.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LFLAGS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS_BONUS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(LFLAGS)

libft:
	$(MAKE) -C src/libft


bonus: libft $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %.c
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_NM) $(OBJ_BONUS)
	$(MAKE) -C src/libft clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C src/libft fclean

re: fclean all

.PHONY: bonus all clean fclean re libft
