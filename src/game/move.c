/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:23 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/29 15:23:54 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coordf	movement_vec(t_coordf vec, float speed)
{
	t_coordf	movement_vec;

	movement_vec.x = vec.x * speed;
	movement_vec.y = vec.y * speed;
	return (movement_vec);
}

static int	move_forward_backward(t_game *g, float speed, int dir)
{
	t_coordf	movement;
	t_coordf	adjusted;

	movement = movement_vec(g->plyr->view, (speed * dir));
	adjusted = check_collision(movement, g);
	add_vectors(&g->plyr->crd, &adjusted);
	return (1);
}

// 1 = l, -1 = r
static int	move_left_right(t_game *g, float speed, int dir)
{
	t_coordf	perpendicular;
	t_coordf	movement;
	t_coordf	adjusted;

	perpendicular = perp_vec(g->plyr->view);
	movement = movement_vec(perpendicular, (speed * dir));
	adjusted = check_collision(movement, g);
	add_vectors(&g->plyr->crd, &adjusted);
	return (1);
}

int	move(t_game *g)
{
	if (g->plyr->move[0])
		move_left_right(g, WALKSPEED, -1);
	if (g->plyr->move[1])
		move_forward_backward(g, WALKSPEED, 1);
	if (g->plyr->move[2])
		move_forward_backward(g, WALKSPEED, -1);
	if (g->plyr->move[3])
		move_left_right(g, WALKSPEED, 1);
	if (g->plyr->move[4])
		turn(g, 'l', TURNSPEED);
	if (g->plyr->move[5])
		turn(g, 'r', TURNSPEED);
	if (!g->plyr->move[0] && !g->plyr->move[1] && !g->plyr->move[2] \
	&& !g->plyr->move[3] && !g->plyr->move[4] && !g->plyr->move[5])
		return (0);
	return (1);
}
