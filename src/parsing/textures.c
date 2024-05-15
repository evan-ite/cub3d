/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:21:24 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/15 17:56:39 by jstrozyk         ###   ########.fr       */
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
		temp = img->addr[top * (img->x * (img->bpp / 8)) + left + byte];
		img->addr[top * (img->x * (img->bpp / 8)) + left + byte] = \
		img->addr[top * (img->x * (img->bpp / 8)) + right + byte];
		img->addr[top * (img->x * (img->bpp / 8)) + right + byte] = temp;
		byte++;
	}
}

void	reverse_texture(t_img *img)
{
	int		top;
	int		left;
	int		right;

	top = -1;
	while (++top < img->x)
	{
		left = 0;
		right = (img->x * (img->bpp / 8)) - (img->bpp / 8);
		while (left < right)
		{
			switch_byte(top, left, right, img);
			left += (img->bpp / 8);
			right -= (img->bpp / 8);
		}
	}
}
