/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/29 12:16:54 by jstrozyk         ###   ########.fr       */
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
