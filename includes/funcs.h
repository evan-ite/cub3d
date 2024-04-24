/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:18:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/24 15:02:37 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "structs.h"

void	init_map(t_map *map);
char	*extract_path(int start, char *str, t_map *map);
int		extract_color(int start, char *str, t_map *map);
int		get_map(t_map *map);
int		map_line(char *str);
int		check_valid(t_map *map);
int		is_mapchar(char c);
int		check_walls(t_map *map);

// parsing
int		parsing(int argc, char **argv, t_map *map);

// visualization
int		start_game(t_game *game);
int		init_textures(t_game *g);
int		init_frame(t_game *g);
int		fill_bg(t_img *frame, int c, int f);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);

// debugging
void	print_map(t_map *map);
void	print_img(t_img *i);
#endif
