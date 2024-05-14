/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:21:24 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/14 14:30:24 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	switch_byte(int top, int left, int right, t_img *img)
{
	int		byte;
	char	temp;

	byte = 0;
	while (byte < (img->bpp / 8))
	{
		temp = img->addr[top * (TEX_X * (img->bpp / 8)) + left + byte];
		img->addr[top * (TEX_X * (img->bpp / 8)) + left + byte] = \
		img->addr[top * (TEX_X * (img->bpp / 8)) + right + byte];
		img->addr[top * (TEX_X * (img->bpp / 8)) + right + byte] = temp;
		byte++;
	}
}

void	reverse_texture(t_img *img)
{
	int		top;
	int		left;
	int		right;

	top = -1;
	while (++top < TEX_Y)
	{
		left = 0;
		right = (TEX_X * (img->bpp / 8)) - (img->bpp / 8);
		while (left < right)
		{
			switch_byte(top, left, right, img);
			left += (img->bpp / 8);
			right -= (img->bpp / 8);
		}
	}
}
