/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 11:21:24 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/10 14:00:14 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void reverse_texture(t_img *img)
{
	char temp;
	int top;
	int left;
	int right;

	top = -1;
	while (++top < TEX_Y)
	{
		left = 0;
		right = (TEX_X * (img->bpp / 8)) - (img->bpp / 8);
		while (left < right)
		{
			int byte = 0;
			while (byte < (img->bpp / 8))
			{
				temp = img->addr[top * (TEX_X * (img->bpp / 8)) + left + byte];
				img->addr[top * (TEX_X * (img->bpp / 8)) + left + byte] = \
				img->addr[top * (TEX_X * (img->bpp / 8)) + right + byte];
				img->addr[top * (TEX_X * (img->bpp / 8)) + right + byte] = temp;
				byte++;
			}
			left += (img->bpp / 8);
			right -= (img->bpp / 8);
		}
	}
}
