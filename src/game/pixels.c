/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:40:05 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/27 11:25:30 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	set_px(t_coord	*px, int c, t_game *g)
{
	char	*ptr;

	if (px->x > WIDTH -1 || px->y > HEIGHT -1 || px->x < 0 || px->y < 0)
		return (0);
	ptr = (g->frame->addr + (((int) px->y * g->frame->len) + \
	(g->frame->bpp / 8) * (int) px->x));
	*(int *)(ptr) = c;
	return (1);
}

int	get_px(t_coord *px, t_img *i, int verify)
{
	int	*c;

	if (verify)
	{
		if (px->x > i->x || px->y > i->y)
			return (-1);
	}
	c = (int *)(i->addr + (((int) px->y * i->len) + \
	(i->bpp / 8) * (int) px->x));
	return (*c);
}
