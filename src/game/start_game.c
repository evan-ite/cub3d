/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/22 16:22:59 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	next_frame(t_game *game)
{
	void*	win_ptr;
	void*	mlx_ptr;
	int		ceiling;
	int		floor;
	int		r;
	int		c;

	win_ptr = game->win->win;
	mlx_ptr = game->win->mlx;
	ceiling = 0xFF0000;
	floor = 0xFF0000;
	r = 0;
	c = 0;
	printf("%p, %p, %x, %x \n", mlx_ptr, win_ptr, ceiling, floor);
	mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 101, 101, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 102, 102, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 102, 101, 0xFF0000);
	mlx_pixel_put(mlx_ptr, win_ptr, 101, 102, 0xFF0000);

	// while(++c < WIDTH)
	// {
	// 	while(++r < HEIGHT)
	// 	{
	// 		if (r < HEIGHT/2)
	// 			mlx_pixel_put(mlx_ptr, win_ptr, r, c, floor);
	// 		else
	// 			mlx_pixel_put(mlx_ptr, win_ptr, r, c, ceiling);

	// 	}
	// }
	return (0);
}

static int	on_keypress()
{
	return (0);
}

static int	on_end(t_game *g)
{
	// free_game(g);
	(void) g;
	exit(0);
}

int	start_game(t_game *game)
{
	void*	win_ptr;
	void*	mlx_ptr;

	win_ptr = game->win->win;
	mlx_ptr = game->win->mlx;
	mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &game);
	mlx_hook(win_ptr, DestroyNotify, StructureNotifyMask, &on_end, &game);
	mlx_loop_hook(mlx_ptr, next_frame, &game);
	mlx_loop(mlx_ptr);
	return (1);
}
