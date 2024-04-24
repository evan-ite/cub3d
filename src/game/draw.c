/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:20 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/24 18:37:46 by jstrozyk         ###   ########.fr       */
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

int	set_px(t_coord	*px, int c, t_game *g)
{
	char	*ptr;

	if (px->x > WIDTH || px->y > HEIGHT)
		return (0);
	ptr = (g->frame->addr + ((px->y * g->frame->len) + (g->frame->bpp / 8) * px->x));
	*(int *)(ptr) = c;
	return (1);
}

int	get_px(t_coord *px, t_img *i, int verify)
{
	int	*c;

	if(verify)
	{
		if (px->x > TEX_X || px->y > TEX_Y)
			return (-1);
	}
	c = (int *) (i->addr + ((px->y * i->len) + (i->bpp / 8) * px->x));
	return (*c);
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
	return (1); // meaningfull error handling tbi
}
