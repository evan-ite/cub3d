/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:20 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/03 11:37:15 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_bg(t_img *frame, int c, int f)
{
	int		ctr;
	char	*px;

	ctr = 0;
	px = frame->addr;
	while(ctr < (frame->len * HEIGHT))
	{
		if (ctr < (frame->len * HEIGHT/2))
			*(int *)(px) = c;
		else
			*(int *)(px) = f;
		px += frame->bpp/8;
		ctr += frame->bpp/8;
	}
	return (1); // meaningfull error handling tbi
}

int	draw_frame(t_game *g)
{
	t_img	*text;
	t_coord	get;
	t_coord	set;

	text = g->texts[0];
	set.x = 250;
	get.x = 0;

	while(get.x < TEX_X)
	{
		get.y = 0;
		set.y = 250;
		while(get.y < TEX_Y)
		{
			set_px(&set, get_px(&get, text, 1), g);
			get.y++;
			set.y++;

		}
		get.x++;
		set.x++;
	}
	fill_bg(g->frame, g->map->c, g->map->f);
	raycast(g);
	return (1); // meaningfull error handling tbi
}

int	draw_line(int height, int col, int c, t_game *g)
{
	t_coord	px;
	int		ctr;

	ctr = -1;
	px.y = (int) (HEIGHT - height) / 2;
	px.x = (int) col;
	while (++ctr <= height)
	{
		set_px(&px, c, g);
		px.y++;
	}
	return (1); // meaningfull error handling tbi
}
// int	set_px(t_coord	*px, int c, t_game *g)
