/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:52:02 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 17:07:16 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Find sprite coordinates on screen */
void	calc_screen_coor(t_game *g, t_sprite *s)
{
	float	inv_d;

	inv_d = 1.0 / (s->plane.x * g->plyr->view.y - g->plyr->view.x * s->plane.y);
	s->trans_x = inv_d * \
		(g->plyr->view.y * s->vec_spr.x - g->plyr->view.x * s->vec_spr.y);
	s->trans_y = inv_d * \
		(-s->plane.y * s->vec_spr.x + s->plane.x * s->vec_spr.y);
	s->sp_scrx = (int)((WIDTH / 2) * (1 + s->trans_x / s->trans_y));
}

/* Scale sprite height according to distance*/
void	calc_height(t_sprite *s)
{
	s->sp_h = abs((int)(HEIGHT / s->trans_y)) / HSCALE;
	s->start_y = -s->sp_h / 2 + HEIGHT / 2 + s->mv_screen;
	if (s->start_y < 0)
		s->start_y = 0;
	s->end_y = s->sp_h / 2 + HEIGHT / 2 + s->mv_screen;
	if (s->end_y >= HEIGHT)
		s->end_y = HEIGHT - 1;
}

/* Scale sprite width according to distance*/
void	calc_width(t_sprite *s)
{
	s->sp_w = abs((int)(HEIGHT / s->trans_y)) / WSCALE;
	s->start_x = -s->sp_w / 2 + s->sp_scrx;
	if (s->start_x < 0)
		s->start_x = 0;
	s->end_x = s->sp_w / 2 + s->sp_scrx;
	if (s->end_x >= WIDTH)
		s->end_x = WIDTH - 1;
}

/* loop through every vertical stripe of the sprite on screen, if the stripe is
on the screen and not covered by a wall, draw every pixel of the stripe. If int
flash = 1, the flash textures will be drawn, if flash = 0 a normal texture will
be drawn. */
void	loop_stripes(t_sprite s, t_game *g, t_img *img)
{
	int		stripe;
	int		y;
	int		d;
	int		color;
	t_coord	tex;
	t_coord	set;

	stripe = s.start_x - 1;
	while (++stripe < s.end_x)
	{
		tex.x = (int)(256 * (stripe - (-s.sp_w / 2 + s.sp_scrx)) * KIMSIZE / s.sp_w) / 256;
		if (s.trans_y > 0 && stripe > 0 && stripe < WIDTH && s.trans_y < g->zbuf[stripe])
		{
			y = s.start_y - 1;
			while (++y < s.end_y)
			{
				d = (y - s.mv_screen) * 256 - HEIGHT * 128 + s.sp_h * 128;
				tex.y = ((d * KIMSIZE) / s.sp_h) / 256;
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
		sm->sp->mv_screen = (int)(MOVE / sm->sp->trans_y);
		calc_height(&sm->sp[i]);
		calc_width(&sm->sp[i]);
		loop_stripes(sm->sp[i], g, g->sm.img);
	}
}
