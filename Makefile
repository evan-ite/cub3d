# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 09:59:26 by elisevanite       #+#    #+#              #
#    Updated: 2024/05/27 16:40:39 by jstrozyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME_BONUS = cub3d_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
CFLAGS_NM = -Wall -Werror -Wextra -D BONUS=1 -D HIDE_MOUSE=1
CFLAGS_BONUS = -Wall -Werror -Wextra -D BONUS=1
LFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz

LIBFT = src/libft/libft.a

SRC = src/main.c src/error.c src/print.c src/free.c \
	src/parsing/parsing.c src/parsing/utils.c src/parsing/color.c src/parsing/map.c \
	src/parsing/valid_map.c src/parsing/walls.c src/parsing/valid_sprites.c \
	src/game/start_game.c src/game/init.c src/game/draw.c \
	src/game/pixels.c src/dda/dda.c src/game/input.c \
	src/dda/dda_utils.c src/game/move.c src/game/collision.c \
	src/features/minimap.c src/parsing/textures.c src/features/sprites.c \
	src/features/doors.c src/dda/dda_objects.c src/features/sprite_utils.c \
	src/features/photo.c

OBJ := $(SRC:.c=.o)
OBJ_NM := $(SRC:.c=_nm.o)
OBJ_BONUS := $(SRC:.c=_bonus.o)

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LFLAGS)

libft:
	$(MAKE) -C src/libft

no_mouse: $(OBJ_NM) libft
	$(CC) $(CFLAGS_NM) -o $(NAME_BONUS) $(OBJ_NM) $(LIBFT) $(LFLAGS)

bonus: $(OBJ_BONUS) libft
	$(CC) $(CFLAGS_BONUS) -o $(NAME_BONUS) $(OBJ_BONUS) $(LIBFT) $(LFLAGS)

%.o: %.c
	@echo "Rebuilding $@ because of the following dependencies:"
	@ls -l $?
	$(CC) $(CFLAGS) -c $< -o $@

%_nm.o: %.c
	@echo "Rebuilding $@ because of the following dependencies:"
	@ls -l $?
	$(CC) $(CFLAGS_NM) -c $< -o $@

%_bonus.o: %.c
	@echo "Rebuilding $@ because of the following dependencies:"
	@ls -l $?
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_NM) $(OBJ_BONUS)
	$(MAKE) -C src/libft clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	$(MAKE) -C src/libft fclean

re: fclean all

.PHONY: bonus all clean fclean re no_mouse libft

