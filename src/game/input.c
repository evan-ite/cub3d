/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:17:39 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/26 15:58:08 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_player(t_coord c, t_game *g)
{
	g->player->coord.x += c.x;
	g->player->coord.y += c.y;
}

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
	move_player(change, g);
	return (0);
}
