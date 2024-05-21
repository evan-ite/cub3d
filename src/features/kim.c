/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:58:33 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/21 11:21:21 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Save all the coordinates of the sprites in an array and return
the array with coordinates */
static int	get_sprite_coord(t_game *g, t_coord *sprite)
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
				sprite[ctr].x = j;
				sprite[ctr++].y = i;
			}
		}
	}
	return (0);
}

/* Sorts sp_coor based on distance in descending order. So the
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

void	draw_kim(t_game *g)
{
	int				i;
	int				size;

	if (g->map->n_kim <= 0)
		return ;
	size = KIMSIZE;
	if (g->sm.sp_coor)
		free(g->sm.sp_coor);
	g->sm.sp_coor = gnl_calloc(g->map->n_kim + 1, sizeof(t_coord));
	if (get_sprite_coord(g, g->sm.sp_coor) == -1)
		handle_error("Couldn't find sprites", 1, NULL, g);
	i = -1;
	while (++i < g->map->n_kim)
	{
		g->sm.order[i] = i;
		g->sm.dist[i] = pow(g->player->coord.x - g->sm.sp_coor[i].x, 2) + pow(g->player->coord.y - g->sm.sp_coor[i].y, 2);
	}
	sort_sprites(g->sm.order, g->sm.dist, g->map->n_kim);
	calc_sprite(g, &g->sm);
}
