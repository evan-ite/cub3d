/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:58:33 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/29 14:43:11 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Save all the coordinates of the sprites in an array and return
the array with coordinates */
static int	get_sprite_coord(t_game *g, t_coordf *sprite)
{
	int		i;
	int		j;
	int		ctr;

	if (!g || !sprite)
		return (-1);
	ctr = 0;
	i = -1;
	while (g->map->m[++i])
	{
		j = -1;
		while (g->map->m[i][++j])
		{
			if (g->map->m[i][j] == 'X')
			{
				sprite[ctr].x = j + 0.5;
				sprite[ctr++].y = i + 0.5;
			}
		}
	}
	g->sp_data.sp_left = ctr;
	return (0);
}

/* Sorts coords based on distance in descending order. So the
furthest sprite will be first in the list, the closest last.
The array order will be sorted based on the matching index
in dist. */
static void	sort_sprites(int *order, float *dist, int len)
{
	int	i;
	int	j;
	int	temp;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (dist[order[j]] < dist[order[j + 1]])
			{
				temp = order[j];
				order[j] = order[j + 1];
				order[j + 1] = temp;
			}
		}
	}
}

/* Find sprite coordinates on screen */
void	calc_screen_coor(t_game *g, t_sprite *s)
{
	float	inv_d;

	inv_d = 1.0 / (s->plane.x * g->plyr->view.y - g->plyr->view.x * s->plane.y);
	s->trans_x = inv_d * \
		(g->plyr->view.y * s->dist.x - g->plyr->view.x * s->dist.y);
	s->trans_y = inv_d * \
		(-s->plane.y * s->dist.x + s->plane.x * s->dist.y);
	s->scrx = (int)((WIDTH / 2) * (1 + s->trans_x / s->trans_y));
}

/* Calculate the values for every sprite and then draw them
on the screen */
void	create_sprites(t_game *g, t_sprite_data *sp_data)
{
	int		i;
	t_coord	temp;

	i = -1;
	while (++i < sp_data->sp_left)
	{
		sp_data->sp[i].plane = perp_vec(g->plyr->view);
		sp_data->sp[i].dist.x = sp_data->coords[sp_data->order[i]].x \
								- g->plyr->crd.x;
		sp_data->sp[i].dist.y = sp_data->coords[sp_data->order[i]].y \
								- g->plyr->crd.y;
		calc_screen_coor(g, &sp_data->sp[i]);
		calc_height(&sp_data->sp[i]);
		calc_width(&sp_data->sp[i]);
		temp.x = (int)(sp_data->coords[sp_data->order[i]].x - 0.5);
		temp.y = (int)(sp_data->coords[sp_data->order[i]].y - 0.5);
		if (g->plyr->take_pic[0] > 0 && temp.x == g->plyr->take_pic[1] && \
			temp.y == g->plyr->take_pic[2])
			draw_flash(i, g);
		else
			loop_stripes(sp_data->sp[i], g, g->sp_data.img);
	}
}

void	draw_sprites(t_game *g)
{
	int	i;

	if (g->map->n_kim <= 0)
		return ;
	g->sp_data.sp_left = 0;
	if (g->plyr->take_pic[0] == 6)
		g->plyr->take_pic[0] = 0;
	if (get_sprite_coord(g, g->sp_data.coords) == -1)
		handle_error("Couldn't find sprites", 1, NULL, g);
	i = -1;
	while (++i < g->map->n_kim)
	{
		g->sp_data.order[i] = i;
		g->sp_data.dist[i] = pow(g->plyr->crd.x - g->sp_data.coords[i].x, 2) + \
			pow(g->plyr->crd.y - g->sp_data.coords[i].y, 2);
	}
	sort_sprites(g->sp_data.order, g->sp_data.dist, g->sp_data.sp_left);
	create_sprites(g, &g->sp_data);
}
