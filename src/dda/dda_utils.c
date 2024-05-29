/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/29 15:25:51 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_vectors(t_coordf *v1, t_coordf *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
}

t_coordf	perp_vec(t_coordf v)
{
	t_coordf	per;

	per.x = -v.y;
	per.y = v.x;
	return (per);
}

void	set_coordf(float x, float y, t_coordf *coord)
{
	coord->x = x;
	coord->y = y;
}

void	set_coord(int x, int y, t_coord *coord)
{
	coord->x = x;
	coord->y = y;
}
