/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:18:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/29 12:45:29 by jstrozyk         ###   ########.fr       */
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

// init
int		fill_bg(t_img *frame, int c, int f);
int		init_textures(t_game *g);
int		init_frame(t_game *g);
int		init_player(t_game *g);

// visualization
int		start_game(t_game *game);
int		draw_frame(t_game *g);
int		draw_line(int height, int col, int c, t_game *g);
int		get_px(t_coord *px, t_img *i, int verify);
int		set_px(t_coord	*px, int c, t_game *g);

// movement
int		on_keypress(int keysym, t_game *g);
int		on_mouse_click (int button,int x,int y, t_game *g);
int		on_mouse_move(t_game *g);

// vectors
void	add_vectors(t_coord *v1, t_coord *v2);
t_coord	perp_vec(t_coord v);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);
void	set_coord(int x, int y, t_coord *coord);

// debugging
void	print_map(t_map *map);
void	print_img(t_img *i);
void	raycast(t_game *g);
void	printfd(const char *format, ...);

#endif
