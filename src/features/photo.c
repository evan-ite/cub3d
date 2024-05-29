/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:51 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/29 14:51:44 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_flash(int i, t_game *g)
{
	t_img	*img;

	img = g->sp_data.flash[g->plyr->take_pic[0] - 1];
	loop_stripes(g->sp_data.sp[i], g, img);
	if (g->plyr->take_pic[0] == 5)
	{
		g->map->m[g->plyr->take_pic[2]][g->plyr->take_pic[1]] = '0';
		g->plyr->take_pic[0]++;
		g->plyr->take_pic[1] = 0;
		g->plyr->take_pic[2] = 0;
		g->sp_data.last_tick = 0;
	}
	else if (g->tick - g->sp_data.last_tick > ANIMATIONSPEED)
	{
		g->sp_data.last_tick = g->tick;
		g->plyr->take_pic[0]++;
	}
}

/* Creates a flash on the screen if player is close to
kim and presses spacebar */
void	take_photo(t_game *g)
{
	if (g->plyr->take_pic[0] > 0)
		return ;
	g->plyr->take_pic[0] = 1;
	g->plyr->take_pic[1] = g->plyr->object.x;
	g->plyr->take_pic[2] = g->plyr->object.y;
	g->photos++;
	if ((g->photos) == g->map->n_kim)
		g->won = 1;
}
