/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/14 15:41:17 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	next_frame(t_game *game)
{
	void	*win;
	void	*mlx;

	win = game->win->win;
	mlx = game->win->mlx;
	move(game);
	draw_frame(game);
	// draw_kim(game);
	draw_minimap(game);
	mlx_put_image_to_window(mlx, win, game->frame->mlx_img, 0, 0);
	game->tick++;
	return (0);
}

static int	on_end(t_game *g)
{
	free_game(g);
	(void) g;
	exit(0);
}

int	start_game(t_game *game)
{
	void	*win;
	void	*mlx;

	game->tick = 0;
	win = game->win->win;
	mlx = game->win->mlx;
	init_player(game);
	init_textures(game);
	init_frame(game);
	mlx_mouse_hide(mlx, win);
	mlx_mouse_move(mlx, win, WIDTH / 2, HEIGHT / 2);
	mlx_hook(win, KeyPress, KeyPressMask, &key_on, game);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &key_off, game);
	mlx_hook(win, MotionNotify, PointerMotionMask, &mouse_move, game);
	mlx_hook(win, DestroyNotify, StructureNotifyMask, &on_end, game);
	mlx_loop_hook(mlx, next_frame, game);
	mlx_loop(mlx);
	return (1);
}
