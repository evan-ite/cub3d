/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:52:02 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/27 16:01:01 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Scale sprite height according to distance*/
void	calc_height(t_sprite *sprite)
{
	sprite->h = abs((int)(HEIGHT / sprite->trans_y)) / HSCALE;
	sprite->start_y = -sprite->h / 2 + HEIGHT / 2;
	if (sprite->start_y < 0)
		sprite->start_y = 0;
	sprite->end_y = sprite->h / 2 + HEIGHT / 2;
	if (sprite->end_y >= HEIGHT)
		sprite->end_y = HEIGHT - 1;
}

/* Scale sprite width according to distance*/
void	calc_width(t_sprite *sprite)
{
	sprite->w = abs((int)(HEIGHT / sprite->trans_y)) / WSCALE;
	sprite->start_x = -sprite->w / 2 + sprite->scrx;
	if (sprite->start_x < 0)
		sprite->start_x = 0;
	sprite->end_x = sprite->w / 2 + sprite->scrx;
	if (sprite->end_x >= WIDTH)
		sprite->end_x = WIDTH - 1;
}

static void	loop_y(t_sprite_loop loop, t_sprite sprite, t_game *g, t_img *img)
{
	loop.y = sprite.start_y - 1;
	while (++loop.y < sprite.end_y)
	{
		loop.d = loop.y * 256 - HEIGHT * 128 + sprite.h * 128;
		loop.tex.y = \
		ft_clamp((((loop.d * KIMSIZE) / sprite.h) / 256), 0, KIMSIZE - 1);
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

void	loop_stripes(t_sprite sprite, t_game *g, t_img *img)
{
	t_sprite_loop	loop;

	set_coord(0, 0, &(loop.tex));
	loop.d = 0;
	loop.y = 0;
	loop.stripe = sprite.start_x - 1;
	while (++loop.stripe < sprite.end_x)
	{
		loop.tex.x = (int)(256 * (loop.stripe - (-sprite.w / 2 + sprite.scrx)) \
			* KIMSIZE / sprite.w) / 256;
		if (sprite.trans_y > 0 && loop.stripe > 0 && \
			loop.stripe < WIDTH && sprite.trans_y < g->zbuf[loop.stripe])
			loop_y(loop, sprite, g, img);
	}
}
