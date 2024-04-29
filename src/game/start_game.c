/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/29 16:07:12 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	next_frame(t_game *game)
{
	void*	win;
	void*	mlx;

	win = game->win->win;
	mlx = game->win->mlx;
	on_mouse_move(game);
	draw_frame(game);
	mlx_put_image_to_window(mlx, win, game->frame->mlx_img, 0, 0);
	game->tick++;
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

	game->tick = 0;
	win_ptr = game->win->win;
	mlx_ptr = game->win->mlx;
	init_player(game);
	init_textures(game);
	init_frame(game);
	// mlx_destroy_window(mlx_ptr, win_ptr); // init testing only!
	mlx_mouse_hide(mlx_ptr, win_ptr);
	mlx_mouse_move(mlx_ptr, win_ptr, WIDTH/2, HEIGHT/2);
	mlx_hook(win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, game);
	// mlx_mouse_hook(win_ptr, &on_mouse_click, game); // mouse clicks only, do we need that?
	mlx_hook(win_ptr, DestroyNotify, StructureNotifyMask, &on_end, game);
	mlx_loop_hook(mlx_ptr, next_frame, game);
	mlx_loop(mlx_ptr);
	return (1);
}
