/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:35 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 15:55:12 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H


typedef	struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;


typedef	struct s_coordf
{
	float	x;
	float	y;
}	t_coordf;

typedef	struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef	struct s_player
{
	t_coordf	coord;
	t_coordf	view;
	int			move[6]; // 0 left, 1 up, 2 down, 3 right, 4 turn l, 5 turn r
	t_coord		object;
	int			interact;
}	t_player;

typedef struct s_map
{
	char	*text_files[7]; // 0 == North, 1 == East, 2 == South, 3 == West, 4-6 == Door closed, half open, open
	int		f;
	int		c; // https://gontjarow.github.io/MiniLibX/mlx_pixel_put.html
	char	**m;
	int		max_width;
	int		max_height; // I don't think we will use these?
	int		fd; // Jan you don't need it but i need it in case of error to close file
	int		fd_lines;
	int		n_kim;
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

typedef	struct s_sprite
{
	t_coordf	plane;
	t_coordf	vec_spr;
	float		transformY;
	float		transformX;
	int			spriteScreenX;
	int			spriteHeight;
	int			drawStartY;
	int			drawEndY;
	int			spriteWidth;
	int			drawStartX;
	int			drawEndX;
	int			moveScreen;
}	t_sprite;

typedef	struct s_sprite_meta
{
	t_sprite	sp[100];
	t_coord		sp_coor[100];
	int			order[100];
	float		dist[100];
	void		*img;
	void		*flash[5];
	int			sp_left;
	int			last_tick;
}	t_sp_meta;

typedef struct s_game
{
	t_map		*map;
	t_win		*win;
	t_img		*texts[7]; // 0 == North, 1 == East, 2 == South, 3 == West, 4-6 == Door closed, half open, open,
	t_img		*cam_overlay;
	t_img		*hint;
	t_img		*frame;
	t_player	*player;
	size_t		tick;
	int			photos; //photos taken by player
	int			zbuf[1920];
	int			won;
	t_sp_meta	sm;
}	t_game;

typedef	struct s_ray
{
	int			height;
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

#endif
