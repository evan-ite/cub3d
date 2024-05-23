/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:52:02 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/23 12:26:21 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void	loop_y(t_sprite_loop loop, t_sprite s, t_game *g, t_img *img)
{
	loop.y = s.start_y - 1;
	while (++loop.y < s.end_y)
	{
		loop.d = (loop.y - s.mv_screen) * 256 - HEIGHT * 128 + s.sp_h * 128;
		loop.tex.y = ((loop.d * KIMSIZE) / s.sp_h) / 256;
		loop.color = get_px(&(loop.tex), img, 0);
		set_coord(loop.stripe, loop.y, &(loop.set));
		if (loop.color > 0)
			set_px(&(loop.set), loop.color, g);
	}
}

/* loop through every vertical stripe of the sprite on screen, if the stripe is
on the screen and not covered by a wall, draw every pixel of the stripe. If int
flash = 1, the flash textures will be drawn, if flash = 0 a normal texture will
be drawn. */
void	loop_stripes(t_sprite s, t_game *g, t_img *img)
{
	t_sprite_loop	loop;

	loop.stripe = s.start_x - 1;
	while (++loop.stripe < s.end_x)
	{
		loop.tex.x = (int)(256 * (loop.stripe - (-s.sp_w / 2 + s.sp_scrx)) \
			* KIMSIZE / s.sp_w) / 256;
		if (s.trans_y > 0 && loop.stripe > 0 && \
			loop.stripe < WIDTH && s.trans_y < g->zbuf[loop.stripe])
			loop_y(loop, s, g, img);
	}
}
