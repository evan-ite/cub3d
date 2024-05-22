/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:51 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 17:04:53 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* finds and returns the index of the sprite that the player
is pointing at in the sprite array */
// static int	find_index(t_game *g)
// {
// 	int	i;

// 	i = -1;
// 	while (++i < g->sm.sp_left)
// 	{
// 		if (g->sm.sp_coor[i].x == g->player->object.x && g->sm.sp_coor[i].y == g->player->object.y)
// 			return (i);
// 	}
// 	return (-1);
// }

// static void	calc_flash(int i, t_game *g, t_sp_meta *sm)
// {
// 	sm->sp[i].plane = perp_vec(g->player->view);
// 	sm->sp[i].vec_spr.x = sm->sp_coor[sm->order[i]].x - g->player->coord.x;
// 	sm->sp[i].vec_spr.y = sm->sp_coor[sm->order[i]].y - g->player->coord.y;
// 	calc_screen_coor(g, &sm->sp[i]);
// 	sm->sp->mv_screen = (int) (MOVE / sm->sp->trans_y);
// 	calc_height(&sm->sp[i]);
// 	calc_width(&sm->sp[i]);
// }

// static void	draw_flash(t_game *g)
// {
// 	int	target;

// 	target = find_index(g);
// 	calc_flash(target, g, &g->sm);
// 	loop_stripes(g->sm.sp[target], g, g->sm.flash[4]);
// }

/* Creates a flash on the screen if player is close to
kim and presses spacebar */
void	take_photo(t_game *g)
{
	// char	*state;

	// state = &(g->map->m[g->player->object.y][g->player->object.x]);
	// if (*state == 5 + 'X')
	// {
	// 	*state = 0;
	g->photos++;
	if ((g->photos) == g->map->n_kim)
		g->won = 1;
	// }
	// else
	// 	(*state)++;
	// draw_flash(g);
	g->map->m[g->plyr->object.y][g->plyr->object.x] = 0;
}
