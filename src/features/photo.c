/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:51 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 14:22:01 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// static void	draw_flash(t_game *g)
// {
// 	t_coord	target;

// 	set_coord(g->player->object.x, g->player->object.y, &target);

// }

/* Creates a flash on the screen if player is close to
kim and presses spacebar */
void	take_photo(t_game *g)
{
	if (g->player->interact != 'X')
		return ;
	// draw_flash(g);
	g->photos++;
	if (g->photos == g->map->n_kim)
		g->won = 1;
}
