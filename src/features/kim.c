/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:58:33 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/17 15:53:17 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Save all the coordinates of the sprites in an array and return
the array with coordinates */
static t_coord	*get_sprite_coord(t_game *g)
{
	t_coord	*sprite;
	int		i;
	int		j;
	int		ctr;

	ctr = 0;
	i = -1;
	sprite = gnl_calloc(g->map->n_kim + 1, sizeof(t_coord));
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
	return (sprite);
}

/* Sorts sprites based on distance in descending order. So the
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
	t_sprite_meta	d;

	if (g->map->n_kim <= 0)
		return ;
	size = KIMSIZE;
	d.sprites = get_sprite_coord(g);
	d.img = mlx_xpm_file_to_image(g->win->mlx, KIM, &size, &size);
	i = -1;
	while (++i < g->map->n_kim)
	{
		d.order[i] = i;
		d.dist[i] = pow(g->player->coord.x - d.sprites[i].x, 2) + pow(g->player->coord.y - d.sprites[i].y, 2);
	}
	sort_sprites(d.order, d.dist, g->map->n_kim);
	calc_sprite(g, &d);
}
