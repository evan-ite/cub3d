/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:03:45 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/03 13:07:08 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
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
# define ERR_FILE "Please provide a valid map file\n"
# define ERR_MEM "Error allocating memory\n"
# define ERR_TEXT "Map does not contain valid texture files\n"
# define ERR_COL "Map does not contain valid RGB colors\n"
# define ERR_MAP "Please provide a valid map\n"
# define WINDOW_NAME "PAPARAZZO"
# define WIDTH 1920
# define HEIGHT 960
// # define WIDTH 600
// # define HEIGHT 300
# define TEX_X 640
# define TEX_Y 640
# define TURNSPEED 0.30
# define MOUSE_SENS 10
# define FOV 0.8
# define DEBUG 1

#endif
