/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:45:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 10:45:22 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_side_dist(t_ray *r, t_game *g)
{
	if (r->r_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g->player->coord.x - r->cell.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->cell.x + 1.0 - g->player->coord.x) \
		* r->delta_dist.x;
	}
	if (r->r_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g->player->coord.y - r->cell.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->cell.y + 1.0 - g->player->coord.y) * \
		r->delta_dist.y;
	}
}

static void	init_ray(t_ray *r, int ctr, t_game *g)
{
	set_coord(g->player->coord.x, g->player->coord.y, &(r->cell));
	r->side = 0;
	r->height = 0;
	r->w_dist = 0;
	r->w_ratio = 0;
	r->plane = perp_vec(g->player->view);
	r->cam.x = ((2 * ctr / (float) WIDTH) - 1) * FOV;
	set_coordf((g->player->view.x + r->plane.x * r->cam.x), \
	(g->player->view.y + r->plane.y * r->cam.x), &(r->r_dir));
	set_coordf(fabs(1 / r->r_dir.x), fabs(1 / r->r_dir.y), &(r->delta_dist));
	set_side_dist(r, g);
}

static void	find_wall(t_ray *r, t_game *g)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->cell.x += r->step.x;
			r->side = 0;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->cell.y += r->step.y;
			r->side = 1;
		}
		if (g->map->m[r->cell.y][r->cell.x] == '1' || g->map->m[r->cell.y][r->cell.x] == 'D')
			hit = g->map->m[r->cell.y][r->cell.x];
	}
	if (hit == 'D')
		r->side = 2;
}

static void	get_wall_width(t_ray *r, t_game *g)
{
	t_coordf	p;

	set_coordf(g->player->coord.x, g->player->coord.y, &p);
	if (!r->side)
	{
		if (r->r_dir.x)
			r->w_dist = (r->cell.x - p.x + (1 - r->step.x) / 2) / r->r_dir.x;
		else
			r->w_dist = INFINITY;
		r->intersect.y = p.y + r->w_dist * r->r_dir.y;
	}
	else
	{
		if (r->r_dir.y)
			r->w_dist = (r->cell.y - p.y + (1 - r->step.y) / 2) / r->r_dir.y;
		else
			r->w_dist = INFINITY;
		r->intersect.x = p.x + r->w_dist * r->r_dir.x;
	}
	if (!r->side)
		r->w_ratio = r->intersect.y - r->cell.y;
	else
		r->w_ratio = r->intersect.x - r->cell.x;
}

void	raycast(t_game *g)
{
	int		ctr;
	t_ray	r;

	ctr = -1;
	while (++ctr < WIDTH)
	{
		init_ray(&r, ctr, g);
		find_wall(&r, g);
		get_wall_width(&r, g);
		r.height = (int)(HEIGHT / r.w_dist);
		if (!r.side && r.step.x < 0)
			draw_line(r.height, ctr, r.w_ratio, 0, g);
		if (!r.side && r.step.x > 0)
			draw_line(r.height, ctr, r.w_ratio, 1, g);
		if (r.side == 1 && r.step.y < 0)
			draw_line(r.height, ctr, r.w_ratio, 2, g);
		if (r.side == 1 && r.step.y > 0)
			draw_line(r.height, ctr, r.w_ratio, 3, g);
		if (r.side == 2)
			draw_line(r.height, ctr, r.w_ratio, 4, g); // DRAW DOOR
		g->zbuf[ctr] = r.w_dist;
	}
	draw_kim(g);
	if (interaction_ray(g))
		show_hint(g);
}
