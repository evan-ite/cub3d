/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:35 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/24 15:04:12 by jstrozyk         ###   ########.fr       */
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
	int	x;
	int	y;
}	t_coord;

typedef struct s_map
{
	// char	*no;
	// char	*so;
	// char	*we;
	// char	*ea;
	char	*text_files[4]; // 0 == North, 1 == East, 2 == South, 3 == West
	int		f;
	int		c; // https://gontjarow.github.io/MiniLibX/mlx_pixel_put.html
	char	**map;
	int		max_width;
	int		max_height;
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
	t_map	*map;
	t_win	*win;
	t_img	*texts[4]; // 0 == North, 1 == East, 2 == South, 3 == West
	t_img	*frame;
}	t_game;

#endif
