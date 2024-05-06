/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:12:13 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/06 15:00:15 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

# define TILE_SIZE 10

void draw_map(t_game *game)
{
	int		x;
	int		y;
	char	**map;
	void	*win;
	void	*mlx;
	void	*wall;
	void	*empty;
	void	*player;
	int		size;

	size = 10;
	map = game->map->map;
	win = game->win->win;
	mlx = game->win->mlx;
	wall = mlx_xpm_file_to_image(mlx, "/home/evan-ite/Projects/cub3d/textures/mini_wall.xpm", &size, &size);
	empty = mlx_xpm_file_to_image(mlx, "/home/evan-ite/Projects/cub3d/textures/mini_empty.xpm", &size, &size);
	player = mlx_xpm_file_to_image(mlx, "/home/evan-ite/Projects/cub3d/textures/mini_pl.xpm", &size, &size);

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			// Calculate the position to draw the tile
			int tile_x = x * TILE_SIZE + 20;
			int tile_y = y * TILE_SIZE + 20;
			// Draw a square based on the value of the cell
			if (map[y][x] == '1')
				mlx_put_image_to_window(mlx, win, wall, tile_x, tile_y);
			else if (map[y][x] == '0' || ft_strchr("NESW", map[y][x]))
				mlx_put_image_to_window(mlx, win, empty, tile_x, tile_y);
			x++;
		}
		y++;
	}
	int player_x = game->player->coord.x * TILE_SIZE + 20;
	int player_y = game->player->coord.y * TILE_SIZE + 20;
	mlx_put_image_to_window(mlx, win, player, player_x, player_y);
}

void	mini_map(t_game *game)
{
	void*	win;
	void*	mlx;
	int		size;

	size = 100;
	win = game->win->win;
	mlx = game->win->mlx;
	draw_map(game);
	// image = mlx_xpm_file_to_image(mlx, "/home/evan-ite/Projects/cub3d/textures/mini_bg.xpm", &size, &size);
	// mlx_put_image_to_window(mlx, win, image, 20, 20);
}
