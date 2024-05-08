/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:40:05 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/08 17:49:38 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_px(t_coord	*px, int c, t_game *g)
{
	char	*ptr;

	// int len = ft_strlen(g->frame->addr);
	// int pxlen = (((int) px->y * g->frame->len) + (g->frame->bpp / 8) * (int) px->x);
	// if (len < pxlen)
	// 	return (0);

	if (px->x > WIDTH || px->y > HEIGHT)
		return (0);
	ptr = (g->frame->addr + (((int) px->y * g->frame->len) + (g->frame->bpp / 8) * (int) px->x));
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
	c = (int *) (i->addr + (((int) px->y * i->len) + (i->bpp / 8) * (int) px->x));
	return (*c);
}
