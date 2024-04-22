/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/22 18:10:54 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void *draw_tex(t_game *g)
{
	void	*ptr;
	int		x;
	int		y;

	ptr = malloc(1);
	x = TEX_X;
	y = TEX_Y;
	ptr = mlx_xpm_file_to_image(g->win->mlx, g->map->no, &x, &y);
	return(ptr);
}

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
	ceiling = game->map->c;
	floor = game->map->f;
	c = 0;
	void	*ptr = draw_tex(game);
	printf("%s\n", (char *)ptr);
	while(++c < WIDTH)
	{
		r = 0;
		// now draw the rest of the owl
		while(++r < HEIGHT)
		{

			if (r > HEIGHT/3)
				mlx_pixel_put(mlx_ptr, win_ptr, c, r, floor);
			else
				mlx_pixel_put(mlx_ptr, win_ptr, c, r, ceiling);
		}
	}
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
	mlx_loop_hook(mlx_ptr, next_frame, game);
	mlx_loop(mlx_ptr);
	return (1);
}
