/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 14:19:23 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/07 16:28:41 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coord	movement_vec(t_coord vec, float speed)
{
	t_coord	movement_vec;

	movement_vec.x = vec.x * speed;
	movement_vec.y = vec.y * speed;
	return (movement_vec);
}

/* checks if player is moving towards a wall, returns 0 if player is
is colliding with wall, returns 1 if there's is no collision */
static int	check_collision(t_coord movement, int dir, t_game *g)
{
	int		new_x;
	int		new_y;

	// if (dir > 0)
	// {
	// 	new_x = ceil(g->player->coord.x + movement.x);
	// 	new_y = ceil(g->player->coord.y + movement.y);
	// }
	// else
	// {
	// 	new_x = floor(g->player->coord.x + movement.x);
	// 	new_y = floor(g->player->coord.y + movement.y);
	// }
	(void)dir;
	new_x = g->player->coord.x + movement.x;
	new_y = g->player->coord.y + movement.y;
	if (g->map->map[new_y][new_x] == '1')
		return (0);
	else if (g->map->map[new_y + 1][new_x] == '1' || g->map->map[new_y][new_x + 1] == '1')
		return (0);
	else if (g->map->map[new_y - 1][new_x] == '1' || g->map->map[new_y][new_x - 1] == '1')
		return (0);
	printfd("map[%i][%i] = %c\n", new_y, new_x, g->map->map[new_y][new_x]);
	return (1);
}

static int	move_forward_backward(t_game *g, float speed, int dir)
{
	t_coord	movement;

	movement = movement_vec(g->player->view, (speed * dir));
	if (check_collision(movement, dir, g))
		add_vectors(&g->player->coord, &movement);
	return (1); // error handling!?
}

static int	move_left_right(t_game *g, float speed, int dir) // 1 = l, -1 = r
{
	t_coord	perpendicular;
	t_coord	movement;

	perpendicular = perp_vec(g->player->view);
	movement = movement_vec(perpendicular, (speed * dir));
	if (check_collision(movement, dir, g))
		add_vectors(&g->player->coord, &movement);
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
