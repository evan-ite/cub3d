/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:23 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/14 14:39:41 by evan-ite         ###   ########.fr       */
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

	movement = movement_vec(g->player->view, (speed * dir));
	adjusted = check_collision(movement, g);
	add_vectors(&g->player->coord, &adjusted);
	return (1); // error handling!?
}

static int	move_left_right(t_game *g, float speed, int dir) // 1 = l, -1 = r
{
	t_coordf	perpendicular;
	t_coordf	movement;
	t_coordf	adjusted;

	perpendicular = perp_vec(g->player->view);
	movement = movement_vec(perpendicular, (speed * dir));
	adjusted = check_collision(movement, g);
	add_vectors(&g->player->coord, &adjusted);
	return (1); // error handling!?
}

int	move(t_game *g)
{
	if (g->player->move[0])
		move_left_right(g, WALKSPEED, -1);
	if (g->player->move[1])
		move_forward_backward(g, WALKSPEED, 1);
	if (g->player->move[2])
		move_forward_backward(g, WALKSPEED, -1);
	if (g->player->move[3])
		move_left_right(g, WALKSPEED, 1);
	if (g->player->move[4])
		turn(g, 'l', TURNSPEED);
	if (g->player->move[5])
		turn(g, 'r', TURNSPEED);
	return (1); // error handling!?
}
