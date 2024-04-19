/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:17:35 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/19 15:32:32 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_win
{
	void	*mlx;
	void	*win;
}	t_win;

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
	int		fd; // Jan you don't need it but i need it in case of error to close file
}	t_map;

typedef struct s_game
{
	t_map	*map;
	t_win	*win;
}	t_game;

#endif
