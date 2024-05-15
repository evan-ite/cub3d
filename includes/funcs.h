/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:18:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/15 15:20:37 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "structs.h"

// init parsing
void	init_map(t_map *map);

// extract from file
char	*extract_path(int start, char *str, t_map *map);
int		extract_color(int start, char *str, t_map *map);
int		get_map(t_map *map);
int		map_line(char *str, int check_vals, t_map *map);

// check validity
int		check_valid(t_map *map);
int		is_mapchar(char c);
int		check_walls(t_map *map);
int		check_struct(t_map *map);

// parsing
int		parsing(int argc, char **argv, t_map *map);

// init
int		fill_bg(t_img *frame, int c, int f);
int		init_textures(t_game *g);
int		init_frame(t_game *g);
int		init_player(t_game *g);
void	reverse_texture(t_img *img);
void	draw_minimap(t_game *g);

// visualization
int		start_game(t_game *game);
int		draw_frame(t_game *g);
int		draw_line(int height, int col, float width_ratio, int dir, t_game *g);
int		get_px(t_coord *px, t_img *i, int verify);
int		set_px(t_coord	*px, int c, t_game *g);
void	draw_kim(t_game *g, t_ray r);

// movement
int			key_on(int keysym, t_game *g);
int			key_off(int keysym, t_game *g);
int			on_mouse_click (int button,int x,int y, t_game *g);
int			mouse_move(int x, int y, t_game *g);
int			turn(t_game *g, char dir, float speed);
int			move(t_game *g);
t_coordf	check_collision(t_coordf mov, t_game *g);

// vectors
void		add_vectors(t_coordf *v1, t_coordf *v2);
t_coordf	perp_vec(t_coordf v);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);
void	set_coordf(float x, float y, t_coordf *coord);
void	set_coord(int x, int y, t_coord *coord);
int		ft_clamp(int value, int min, int max);

// debugging
void	print_map(t_map *map);
void	print_img(t_img *i);
void	raycast(t_game *g);
void	printfd(const char *format, ...);

// free
int		on_end(t_game *g);
void	free_game(t_game *game);
void	free_map(t_map *map);

// bonus
// void	mini_map(t_game *game);

#endif
