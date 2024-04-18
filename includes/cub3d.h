/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:03:45 by elisevanite       #+#    #+#             */
/*   Updated: 2024/04/18 16:10:43 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../src/libft/libft.h"
# include "../src/libft/getnextline.h"
# include "../src/libft/ft_printf.h"

typedef struct s_map
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c; //https://gontjarow.github.io/MiniLibX/mlx_pixel_put.html
	char	**map;
	int		max_width;
	int		max_height;
}	t_map;

// parsing
int		parsing(int argc, char **argv, t_map *map);

// visualization
int		start_game(t_map *map);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);

#endif
