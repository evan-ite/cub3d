/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:35 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/03 14:04:07 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

typedef	struct s_coord
{
	float	x;
	float	y;
}	t_coord;

typedef	struct s_player
{
	t_coord	coord;
	t_coord	view;
	int		move[6]; // 0 left, 1 up, 2 down, 3 right, 4 turn l, 5 turn r
}	t_player;

typedef struct s_map
{
	char	*text_files[4]; // 0 == North, 1 == East, 2 == South, 3 == West
	int		f;
	int		c; // https://gontjarow.github.io/MiniLibX/mlx_pixel_put.html
	char	**map;
	int		max_width;
	int		max_height; // I don't think we will use these?
	int		fd; // Jan you don't need it but i need it in case of error to close file
}	t_map;

typedef struct s_image
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_map		*map;
	t_win		*win;
	t_img		*texts[4]; // 0 == North, 1 == East, 2 == South, 3 == West
	t_img		*frame;
	t_player	*player;
	size_t		tick;
}	t_game;

#endif
