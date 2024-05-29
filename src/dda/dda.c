/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:45:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/29 14:31:23 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_side_dist(t_ray *r, t_game *g)
{
	if (r->r_dir.x < 0)
	{
		r->step.x = -1;
		r->side_dist.x = (g->plyr->crd.x - r->cell.x) * r->delta_dist.x;
	}
	else
	{
		r->step.x = 1;
		r->side_dist.x = (r->cell.x + 1.0 - g->plyr->crd.x) \
		* r->delta_dist.x;
	}
	if (r->r_dir.y < 0)
	{
		r->step.y = -1;
		r->side_dist.y = (g->plyr->crd.y - r->cell.y) * r->delta_dist.y;
	}
	else
	{
		r->step.y = 1;
		r->side_dist.y = (r->cell.y + 1.0 - g->plyr->crd.y) * \
		r->delta_dist.y;
	}
}

static void	init_ray(t_ray *r, int ctr, t_game *g)
{
	set_coord(g->plyr->crd.x, g->plyr->crd.y, &(r->cell));
	r->side = 0;
	r->height = 0;
	r->w_dist = 0;
	r->w_ratio = 0;
	r->plane = perp_vec(g->plyr->view);
	r->cam.x = ((2 * ctr / (float) WIDTH) - 1) * FOV;
	set_coordf((g->plyr->view.x + r->plane.x * r->cam.x), \
	(g->plyr->view.y + r->plane.y * r->cam.x), &(r->r_dir));
	set_coordf(fabs(1 / r->r_dir.x), fabs(1 / r->r_dir.y), &(r->delta_dist));
	set_side_dist(r, g);
}

static void	find_wall(t_ray *r, t_game *g)
{
	r->hit = 0;
	while (!r->hit)
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
		if (g->map->m[r->cell.y][r->cell.x] == '1' \
			|| g->map->m[r->cell.y][r->cell.x] == 'D')
			r->hit = g->map->m[r->cell.y][r->cell.x];
	}
}

static void	get_wall_width(t_ray *r, t_game *g)
{
	t_coordf	p;

	set_coordf(g->plyr->crd.x, g->plyr->crd.y, &p);
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
			draw_line(r, ctr, 0, g);
		if (!r.side && r.step.x > 0)
			draw_line(r, ctr, 1, g);
		if (r.side == 1 && r.step.y < 0)
			draw_line(r, ctr, 2, g);
		if (r.side == 1 && r.step.y > 0)
			draw_line(r, ctr, 3, g);
		if (r.hit == 'D')
			draw_line(r, ctr, 4, g);
		g->zbuf[ctr] = r.w_dist;
	}
	interaction_ray(g);
}
