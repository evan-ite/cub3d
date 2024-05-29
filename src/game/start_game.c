/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/29 16:41:53 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	winner(t_game *g)
{
	int		h;
	int		w;
	void	*img;

	h = HEIGHT;
	w = WIDTH;
	img = mlx_xpm_file_to_image(g->win->mlx, WIN, &w, &h);
	mlx_put_image_to_window(g->win->mlx, g->win->win, img, (WIDTH - 1800) / 2, (HEIGHT - 900)/ 2);
	mlx_destroy_image(g->win->mlx, img);
}

static int	next_frame(t_game *game)
{
	void	*win;
	void	*mlx;

	win = game->win->win;
	mlx = game->win->mlx;
	if (move(game) || game->draw || game->plyr->take_pic[0])
	{
		draw_frame(game);
		if (BONUS)
			draw_minimap(game);
		if (game->won && game->plyr->take_pic[0] == 0)
			winner(game);
		else
			mlx_put_image_to_window(mlx, win, game->frame->mlx_img, 0, 0);
	}
	game->tick++;
	game->draw = 0;
	return (0);
}

int	start_game(t_game *g)
{
	void	*win;
	void	*mlx;

	g->tick = 0;
	g->photos = 0;
	g->won = 0;
	g->draw = 1;
	g->sp_data.last_tick = 0;
	win = g->win->win;
	mlx = g->win->mlx;
	init_player(g);
	init_textures(g);
	init_frame(g);
	mlx_mouse_move(mlx, win, WIDTH / 2, HEIGHT / 2);
	if (HIDE_MOUSE)
		mlx_mouse_hide(mlx, win);
	mlx_hook(win, KeyPress, KeyPressMask, &key_on, g);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &key_off, g);
	if (BONUS)
		mlx_hook(win, MotionNotify, PointerMotionMask, &mouse_move, g);
	mlx_hook(win, DestroyNotify, StructureNotifyMask, &on_end, g);
	mlx_loop_hook(mlx, next_frame, g);
	mlx_loop(mlx);
	return (1);
}
