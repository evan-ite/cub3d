/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:20 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/24 15:57:52 by jstrozyk         ###   ########.fr       */
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

int	draw_px(t_coord	*px, int c, t_game *g)
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
	if(verify)
	{
		if (px->x > TEX_X || px->y > TEX_Y)
			return (-1);
	}
	return ((int) *(i->addr + ((px->y * i->len) + (i->bpp / 8) * px->x)));
}
