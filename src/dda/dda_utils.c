/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/03 16:45:50 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_vectors(t_coord *v1, t_coord *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
}

t_coord	perp_vec(t_coord v)
{
	t_coord	per;

	per.x = -v.y;
	per.y = v.x;
	return (per);
}

void	set_coord(int x, int y, t_coord *coord)
{
	coord->x = x;
	coord->y = y;
}

int ft_clamp(int value, int min, int max)
{
	if (value < min)
		return (min);
	else if (value > max)
		return (max);
	else
		return (value);
}
