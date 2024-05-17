/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:52:02 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/17 15:52:49 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Find sprite coordinates on screen */
static void	calc_screen_coor(t_game *g, t_sprite *s)
{
	float invDet;

	invDet = 1.0 / (s->plane.x * g->player->view.y - g->player->view.x * s->plane.y);
	s->transformX = invDet * (g->player->view.y * s->vec_spr.x - g->player->view.x * s->vec_spr.y);
	s->transformY = invDet * (-s->plane.y * s->vec_spr.x + s->plane.x * s->vec_spr.y);

	s->spriteScreenX = (int)((WIDTH / 2) * (1 + s->transformX / s->transformY));
}

/* Scale sprite height according to distance*/
static void	calc_height(t_sprite *s)
{
	s->spriteHeight = abs((int)(HEIGHT / s->transformY));
	s->drawStartY = -s->spriteHeight / 2 + HEIGHT / 2;
	if(s->drawStartY < 0)
		s->drawStartY = 0;
	s->drawEndY = s->spriteHeight / 2 + HEIGHT / 2;
	if(s->drawEndY >= HEIGHT)
		s->drawEndY = HEIGHT - 1;
}

/* Scale sprite width according to distance*/
static void	calc_width(t_sprite *s)
{
	s->spriteWidth = abs((int)(HEIGHT / s->transformY));
	s->drawStartX = -s->spriteWidth / 2 + s->spriteScreenX;
	if(s->drawStartX < 0)
		s->drawStartX = 0;
	s->drawEndX = s->spriteWidth / 2 + s->spriteScreenX;
	if(s->drawEndX >= WIDTH)
		s->drawEndX = WIDTH - 1;
}

/* loop through every vertical stripe of the sprite on screen, if the stripe is
on the screen and not covered by a wall, draw every ppixel of the stripe.  */
static void	loop_stripes(t_sprite s, t_game *g)
{
	int		stripe;
	int		y;
	t_coord	tex;
	t_coord	set;

	stripe = s.drawStartX - 1;
	while (++stripe < s.drawEndX)
	{
		tex.x = (int)(256 * (stripe - (-s.spriteWidth / 2 + s.spriteScreenX)) * KIMSIZE / s.spriteWidth) / 256;
		if (s.transformY > 0 && stripe > 0 && stripe < WIDTH && s.transformY < g->zbuf[stripe])
		{
			y = s.drawStartY - 1;
			while (++y < s.drawEndY)
			{
				int d = (y) * 256 - HEIGHT * 128 + s.spriteHeight * 128;
				tex.y = ((d * KIMSIZE) / s.spriteHeight) / 256;

				int color = get_px(&tex, g->kim, 0);
				set_coord(stripe, y, &set);
				if (color > 0)
					set_px(&set, color, g);
			}
		}
	}
}

void	calc_sprite(t_game *g, t_sprite_meta *d)
{
	int			i;
	t_sprite	s;

	i = -1;
	while (++i < g->map->n_kim)
	{
		s.plane = perp_vec(g->player->view);
		s.vec_spr.x = d->sprites[d->order[i]].x - g->player->coord.x;
		s.vec_spr.y = d->sprites[d->order[i]].y - g->player->coord.y;
		calc_screen_coor(g, &s);
		calc_height(&s);
		calc_width(&s);
		loop_stripes(s, g);
	}
}
