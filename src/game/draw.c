/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:20 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/29 15:24:55 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_bg(t_img *frame, int c, int f)
{
	int	total_pixels;
	int	half_pixels;
	int	*px;
	int	i;

	total_pixels = frame->len * HEIGHT / (frame->bpp / 8);
	half_pixels = total_pixels / 2;
	px = (int *)frame->addr;
	i = -1;
	while (++i < half_pixels)
		px[i] = c;
	i = half_pixels;
	while (++i < total_pixels)
		px[i] = f;
	return (1);
}

static void	draw_camera_overlay(t_game *g)
{
	t_img	*cam;
	t_coord	get;
	t_coord	set;
	int		col;

	cam = g->cam_overlay;
	set.x = WIDTH / 2 - cam->x / 2;
	get.x = 0;
	while (get.x < cam->x)
	{
		get.y = 0;
		set.y = HEIGHT / 2 - cam->y / 2;
		while (get.y < cam->y)
		{
			col = get_px(&get, cam, 1);
			if (col > 0)
				set_px(&set, col, g);
			get.y++;
			set.y++;
		}
		get.x++;
		set.x++;
	}
}

int	draw_frame(t_game *g)
{
	fill_bg(g->frame, g->map->c, g->map->f);
	raycast(g);
	draw_sprites(g);
	if (g->plyr->interact)
		show_hint(g);
	if (g->plyr->interact == 'X')
		draw_camera_overlay(g);
	return (1);
}

static int	get_color(int x, int y, int dir, t_game *g)
{
	t_coord	px;

	px.x = x;
	px.y = y;
	return (get_px(&px, g->texts[dir], 0));
}

int	draw_line(t_ray r, int col, int dir, t_game *g)
{
	t_coord	px;
	t_coord	tx;
	int		ctr;
	int		color;
	float	height_ratio;

	ctr = -1;
	height_ratio = (float)g->texts[dir]->y / r.height;
	px.y = (HEIGHT - r.height) / 2;
	px.x = (int) col;
	tx.x = (int)(r.w_ratio * g->texts[dir]->y);
	while (++ctr <= r.height)
	{
		tx.y = (int)(ctr * height_ratio);
		color = get_color(tx.x, tx.y, dir, g);
		set_px(&px, color, g);
		px.y++;
	}
	return (1);
}
