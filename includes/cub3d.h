/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:03:45 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/27 11:26:18 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <string.h>
# include <math.h>
# include "../src/libft/libft.h"
# include "../src/libft/getnextline.h"
# include "../src/libft/ft_printf.h"
# include "../minilibx-linux/mlx.h"
# include "funcs.h"
# include "structs.h"

# define ERR_ARGC "Please provide one map argument\n"
# define ERR_DEBUG "DEBUG\n"
# define ERR_FILE "Please provide a valid map file\n"
# define ERR_MEM "Error allocating memory\n"
# define ERR_TEXT "Map does not contain valid texture files\n"
# define ERR_COL "Map does not contain valid RGB colors\n"
# define ERR_MAP "Please provide a valid map\n"
# define ERR_NKIM "This game can not handle more than 100 Kim K's\n"
# define ERR_KIM_VALID "Not all Kims are reachable\n"
# define ERR_DOUBLE "Element is defined twice\n"
# define ERR_ELEMENT "Unrecognized element in file\n"
# define WINDOW_NAME "PAPARAZZO"
# ifndef HIDE_MOUSE
#  define HIDE_MOUSE 0
# endif
# ifndef BONUS
#  define BONUS 0
# endif
# define WIDTH 1920
# define HEIGHT 960
# define TURNSPEED 0.1
# define WALKSPEED 0.1
# define MOUSE_SENS 20
# define FOV 0.8
# define DEBUG 1
# define MMOFFSET 50
# define MMWALL 0xFA69DA
# define MMDOOR 0x9f4576
# define MMPLAYER 0x0
# define MMDOTSIZE 6
# define KIMSIZE 450
# define HSCALE 1
# define WSCALE 1
# define MOVE 0
# define ANIMATIONSPEED 10
# define DSLR "textures/dlsr.xpm"
# define HINT "textures/hint.xpm"
# define KIM "textures/kim_before.xpm"
# define FLASH "textures/flash.xpm"
# define WIN "textures/win.xpm"
# define DOOR1 "textures/door1.xpm"
# define DOOR2 "textures/door2.xpm"
# define DOOR3 "textures/door3.xpm"

#endif
