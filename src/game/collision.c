/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:38:34 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 16:41:51 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_coordf	get_check_coor(t_coordf mov, t_game *g)
{
	t_coordf		new;

	if (mov.x >= 0)
		new.x = 0.5 + g->plyr->crd.x + mov.x;
	else
		new.x = -0.5 + g->plyr->crd.x + mov.x;
	if (mov.y >= 0)
		new.y = 0.5 + g->plyr->crd.y + mov.y;
	else
		new.y = -0.5 + g->plyr->crd.y + mov.y;
	return (new);
}

/* checks if player is moving towards a wall, returns 0 if player is
is colliding with wall, returns 1 if there's is no collision */
t_coordf	check_collision(t_coordf mov, t_game *g)
{
	t_coordf	new;
	char		tile;
	t_coordf	check;

	check = get_check_coor(mov, g);
	tile = g->map->m[(int)g->plyr->crd.y][(int)check.x];
	if (tile == '1' || tile == 'D')
		new.x = 0;
	else
		new.x = mov.x;
	tile = g->map->m[(int)check.y][(int)g->plyr->crd.x];
	if (tile == '1' || tile == 'D')
		new.y = 0;
	else
		new.y = mov.y;
	return (new);
}
