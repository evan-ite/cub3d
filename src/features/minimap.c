/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:12:13 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 16:41:51 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_mm_pixels(t_coord px, int color, t_game *g)
{
	int		i;
	int		j;
	int		x;
	int		y;
	t_coord	to_set;

	i = -1;
	while (++i < MMDOTSIZE)
	{
		j = -1;
		while (++j < MMDOTSIZE)
		{
			x = i + (MMOFFSET + ((int)px.x) * MMDOTSIZE);
			y = j + (MMOFFSET + ((int)px.y) * MMDOTSIZE);
			set_coord(x, y, &to_set);
			set_px(&to_set, color, g);
		}
	}
}

void	draw_minimap(t_game *g)
{
	int		x;
	int		y;
	t_coord	px;

	y = -1;
	while (g->map->m[++y])
	{
		x = -1;
		while (g->map->m[y][++x])
		{
			if (g->map->m[y][x] == '1')
			{
				set_coord(x, y, &px);
				set_mm_pixels(px, MMWALL, g);
			}
			else if (g->map->m[y][x] == 'd' || g->map->m[y][x] == 'D')
			{
				set_coord(x, y, &px);
				set_mm_pixels(px, MMDOOR, g);
			}
		}
	}
	set_coord((int)g->plyr->crd.x, (int)g->plyr->crd.y, &px);
	set_mm_pixels(px, MMPLAYER, g);
}
