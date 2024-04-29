/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:17:39 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/29 12:49:39 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	on_end(t_game *g)
{
	// free_game(g);
	(void) g;
	exit(0);
}

int	on_keypress(int keysym, t_game *g)
{
	t_coord	change;

	set_coord(0, 0, &change);
	if ((keysym == 65361 || keysym == 97)) // left or a
		change.x = -0.5;
	if ((keysym == 65362 || keysym == 119)) // up or w
		change.y = -0.5;
	if (keysym == 65364 || keysym == 115) // down or s
		change.y = 0.5;
	if (keysym == 65363 || keysym == 100) // right or d
		change.x = 0.5;
	if (keysym == 65307) //esc
		on_end(g);
	add_vectors(&(g->player->coord), &change);
	return (0);
}

int	on_mouse_click(int button,int x,int y, t_game *g)
{
	(void) button;
	(void) g;
	printfd("%d, %d \n", x, y);
	return (0);
}

int	on_mouse_move(t_game *g)
{
	t_coord	mouse;

	set_coord(0, 0, &mouse);
	mlx_mouse_get_pos(g->win->mlx, g->win->win, (int *)&(mouse.x), (int *)&(mouse.y));
	mlx_mouse_move(g->win->mlx, 0, 0);
	if (mouse.x || mouse.y)

		// add_vectors(&(g->player->coord), &mouse);
	return (0);
}
