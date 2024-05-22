/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_objects.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 15:45:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 12:52:27 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_middle_ray(t_ray *r, t_game *g)
{
	int center = WIDTH / 2;
	set_coord(g->player->coord.x, g->player->coord.y, &(r->cell));
	r->side = 0;
	r->height = 0;
	r->w_dist = 0;
	r->w_ratio = 0;
	r->plane = perp_vec(g->player->view);
	r->cam.x = ((2 * center / (float) WIDTH) - 1) * FOV;
	set_coordf((g->player->view.x + r->plane.x * r->cam.x), \
	(g->player->view.y + r->plane.y * r->cam.x), &(r->r_dir));
	set_coordf(fabs(1 / r->r_dir.x), fabs(1 / r->r_dir.y), &(r->delta_dist));
	set_side_dist(r, g);
}

void	show_hint(t_game *g)
{
	t_coord	get;
	t_coord	set;

	set.x = WIDTH / 2 - g->hint->x;
	get.x = 0;
	while(get.x < g->hint->x)
	{
		get.y = 0;
		set.y = HEIGHT - 100 - g->hint->y;
		while(get.y < g->hint->y)
		{
			int col	= get_px(&get, g->hint, 1);
			set_px(&set, col, g);
			get.y++;
			set.y++;
		}
		get.x++;
		set.x++;
	}
}

int	set_object(t_ray r, t_game *g)
{
	if (r.side == 0)
		r.w_dist = (r.cell.x - g->player->coord.x + (1 - r.step.x) / 2) / r.r_dir.x;
	else
		r.w_dist = (r.cell.y - g->player->coord.y + (1 - r.step.y) / 2) / r.r_dir.y;
	if (g->map->m[r.cell.y][r.cell.x] == 'X' && r.w_dist < 3.0)
	{
		g->player->interact = g->map->m[r.cell.y][r.cell.x];
		set_coord(r.cell.x, r.cell.y, &(g->player->object));
		return (1);
	}
	else if ((g->map->m[r.cell.y][r.cell.x] == 'd' || g->map->m[r.cell.y][r.cell.x] == 'D') && r.w_dist < 1.0)
	{
		g->player->interact = g->map->m[r.cell.y][r.cell.x];
		set_coord(r.cell.x, r.cell.y, &(g->player->object));
		return (1); // Found an interactable object within 1 unit
	}
	return (0);
}

int	interaction_ray(t_game *g)
{
	t_ray	r;

	init_middle_ray(&r, g);
	while (!ft_strchr("XdD1", g->map->m[r.cell.y][r.cell.x]))
	{
		if (r.side_dist.x < r.side_dist.y)
		{
			r.side_dist.x += r.delta_dist.x;
			r.cell.x += r.step.x;
			r.side = 0;
		}
		else
		{
			r.side_dist.y += r.delta_dist.y;
			r.cell.y += r.step.y;
			r.side = 1;
		}
	}
	g->player->interact = 0;
	if (ft_strchr("XdD", g->map->m[r.cell.y][r.cell.x]))
		return(set_object(r, g));
	return (0); // No interactable object found within 1 unit
}
