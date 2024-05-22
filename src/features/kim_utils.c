/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:52:02 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 16:41:51 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Find sprite coordinates on screen */
void	calc_screen_coor(t_game *g, t_sprite *s)
{
	float invDet;

	invDet = 1.0 / (s->plane.x * g->plyr->view.y - g->plyr->view.x * s->plane.y);
	s->transformX = invDet * (g->plyr->view.y * s->vec_spr.x - g->plyr->view.x * s->vec_spr.y);
	s->transformY = invDet * (-s->plane.y * s->vec_spr.x + s->plane.x * s->vec_spr.y);

	s->spriteScreenX = (int)((WIDTH / 2) * (1 + s->transformX / s->transformY));
}

/* Scale sprite height according to distance*/
void	calc_height(t_sprite *s)
{
	s->spriteHeight = abs((int)(HEIGHT / s->transformY)) / HSCALE;
	s->drawStartY = -s->spriteHeight / 2 + HEIGHT / 2 + s->moveScreen;
	if(s->drawStartY < 0)
		s->drawStartY = 0;
	s->drawEndY = s->spriteHeight / 2 + HEIGHT / 2 + s->moveScreen;
	if(s->drawEndY >= HEIGHT)
		s->drawEndY = HEIGHT - 1;
}

/* Scale sprite width according to distance*/
void	calc_width(t_sprite *s)
{
	s->spriteWidth = abs((int)(HEIGHT / s->transformY)) / WSCALE;
	s->drawStartX = -s->spriteWidth / 2 + s->spriteScreenX;
	if(s->drawStartX < 0)
		s->drawStartX = 0;
	s->drawEndX = s->spriteWidth / 2 + s->spriteScreenX;
	if(s->drawEndX >= WIDTH)
		s->drawEndX = WIDTH - 1;
}

/* loop through every vertical stripe of the sprite on screen, if the stripe is
on the screen and not covered by a wall, draw every pixel of the stripe. If int flash = 1,
the flash textures will be drawn, if flash = 0 a normal texture will be drawn. */
void	loop_stripes(t_sprite s, t_game *g, t_img *img)
{
	int		stripe;
	int		y;
	int		d;
	int		color;
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
				d = (y - s.moveScreen) * 256 - HEIGHT * 128 + s.spriteHeight * 128;
				tex.y = ((d * KIMSIZE) / s.spriteHeight) / 256;
				color = get_px(&tex, img, 0);
				set_coord(stripe, y, &set);
				if (color > 0)
					set_px(&set, color, g);
			}
		}
	}
}

void	calc_sprite(t_game *g, t_sp_meta *sm)
{
	int			i;

	i = -1;
	while (++i < sm->sp_left)
	{
		sm->sp[i].plane = perp_vec(g->plyr->view);
		sm->sp[i].vec_spr.x = sm->sp_coor[sm->order[i]].x - g->plyr->crd.x;
		sm->sp[i].vec_spr.y = sm->sp_coor[sm->order[i]].y - g->plyr->crd.y;
		calc_screen_coor(g, &sm->sp[i]);
		sm->sp->moveScreen = (int) (MOVE / sm->sp->transformY);
		calc_height(&sm->sp[i]);
		calc_width(&sm->sp[i]);
		loop_stripes(sm->sp[i], g, g->sm.img);
	}
}
