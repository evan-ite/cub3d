/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:35 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/27 15:14:45 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef struct s_coordf
{
	float	x;
	float	y;
}	t_coordf;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_player
{
	t_coordf	crd;
	t_coordf	view;
	int			move[6];
	t_coord		object;
	int			interact;
	int			take_pic[3];
}	t_player;

typedef struct s_map
{
	char	*text_files[7];
	int		f;
	int		c;
	char	**m;
	int		max_width;
	int		max_height;
	int		fd;
	int		fd_lines;
	int		n_kim;
	char	*line;
}	t_map;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
	int		x;
	int		y;
}	t_img;

typedef struct s_sprite
{
	t_coordf	plane;
	t_coordf	dist;
	float		trans_y;
	float		trans_x;
	int			scrx;
	int			h;
	int			w;
	int			start_y;
	int			end_y;
	int			start_x;
	int			end_x;
}	t_sprite;

typedef struct s_sprite_data
{
	t_sprite	sp[100];
	t_coordf	coords[100];
	int			order[100];
	float		dist[100];
	t_img		*img;
	t_img		*flash[5];
	int			sp_left;
	int			last_tick;
}	t_sprite_data;

typedef struct s_game
{
	t_map		*map;
	t_win		*win;
	t_img		*texts[7];
	t_img		*cam_overlay;
	t_img		*hint;
	t_img		*frame;
	t_player	*plyr;
	size_t		tick;
	int			photos;
	float		zbuf[1920];
	int			won;
	t_sprite_data	sp_data;
}	t_game;

typedef struct s_ray
{
	int			height;
	char		hit;
	int			side;
	float		w_dist;
	float		w_ratio;
	t_coord		cell;
	t_coord		step;
	t_coordf	plane;
	t_coordf	cam;
	t_coordf	r_dir;
	t_coordf	side_dist;
	t_coordf	delta_dist;
	t_coordf	intersect;
}	t_ray;

typedef struct s_sprite_loop
{
	int		stripe;
	int		y;
	int		d;
	int		color;
	t_coord	tex;
	t_coord	set;
}	t_sprite_loop;

#endif
