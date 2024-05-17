/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:58:33 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/17 13:54:49 by evan-ite         ###   ########.fr       */
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
	int		i;
	void	*kim;
	t_coord	*sprite;
	int		s_order[g->map->n_kim];
	float	s_dist[g->map->n_kim];
	int		size;

	// 1. Sort sprites according to distance from player
	size =450;
	sprite = get_sprite_coord(g);
	kim = mlx_xpm_file_to_image(g->win->mlx, "../../textures/kim_before.xpm", &size, &size);
	i = -1;
	while (++i < g->map->n_kim)
	{
		s_order[i] = i;
		s_dist[i] = pow(g->player->coord.x - sprite[i].x, 2) + pow(g->player->coord.y - sprite[i].y, 2);
	}
	sort_sprites(s_order, s_dist, g->map->n_kim);

	// 2. For each sprite:
	i = -1;
	while (++i < g->map->n_kim)
	{
	// 1. Find sprite coordinates on screen
		t_coordf	plane = perp_vec(g->player->view);
		t_coordf	vec_spr;
		vec_spr.x = sprite[s_order[i]].x - g->player->coord.x;
		vec_spr.y = sprite[s_order[i]].y - g->player->coord.y;
		float invDet = 1.0 / (plane.x * g->player->view.y - g->player->view.x * plane.y);

		float transformX = invDet * (g->player->view.y * vec_spr.x - g->player->view.x * vec_spr.y);
		float transformY = invDet * (-plane.y * vec_spr.x + plane.x * vec_spr.y);

		int spriteScreenX = (int)((WIDTH / 2) * (1 + transformX / transformY));

	// 2. Scale sprite according to distance
		// Calculate sprite height
		int spriteHeight = abs((int)(HEIGHT / transformY));
		int drawStartY = -spriteHeight / 2 + HEIGHT / 2;
		if(drawStartY < 0)
			drawStartY = 0;
		int drawEndY = spriteHeight / 2 + HEIGHT / 2;
		if(drawEndY >= HEIGHT)
			drawEndY = HEIGHT - 1;

		// calculate sprite width
		int spriteWidth = abs((int)(HEIGHT / transformY));
      	int drawStartX = -spriteWidth / 2 + spriteScreenX;
     	if(drawStartX < 0)
			drawStartX = 0;
     	int drawEndX = spriteWidth / 2 + spriteScreenX;
      	if(drawEndX >= WIDTH)
			drawEndX = WIDTH - 1;

		//loop through every vertical stripe of the sprite on screen
		int	stripe = drawStartX - 1;
		while (++stripe < drawEndX)
		{
			t_coord	tex;
			tex.x = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * KIMSIZE / spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if(transformY > 0 && stripe > 0 && stripe < WIDTH && transformY < g->zbuf[stripe])
			{
				for(int y = drawStartY; y < drawEndY; y++) //for every pixel of the current stripe
				{
					int d = (y) * 256 - HEIGHT * 128 + spriteHeight * 128; //256 and 128 factors to avoid floats
					tex.y = ((d * KIMSIZE) / spriteHeight) / 256;

					int color = get_px(&tex, g->kim, 0); //get current color from the texture
					t_coord	set;
					set_coord(stripe, y, &set);
					if (color > 0)
						set_px(&set, color, g);
				}
			}
		}
	}
	// free(sprite);
}
