/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:23 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/13 15:20:16 by evan-ite         ###   ########.fr       */
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

static t_coordf	get_check_coor(t_coordf mov, t_game *g)
{
	t_coordf		new;

	if (mov.x >= 0)
		new.x = 0.5 + g->player->coord.x + mov.x;
	else
		new.x = -0.5 + g->player->coord.x + mov.x;
	if (mov.y >= 0)
		new.y = 0.5 + g->player->coord.y + mov.y;
	else
		new.y = -0.5 + g->player->coord.y + mov.y;
	return (new);
}

/* checks if player is moving towards a wall, returns 0 if player is
is colliding with wall, returns 1 if there's is no collision */
static t_coordf	check_collision(t_coordf mov, t_game *g)
{
	t_coordf	new;
	char		tile;
	t_coordf	check;

	check = get_check_coor(mov, g);
	tile = g->map->map[(int)g->player->coord.y][(int)check.x];
	if (tile == '1')
		new.x = 0;
	else
		new.x = mov.x;
	tile = g->map->map[(int)check.y][(int)g->player->coord.x];
	if (tile == '1')
		new.y = 0;
	else
		new.y = mov.y;

	return (new);
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
	// collision checks should go here
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
