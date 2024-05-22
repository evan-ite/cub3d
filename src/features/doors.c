/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:37:34 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 16:41:51 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_doors(t_game *g)
{
	char	*state;

	state = &(g->map->m[g->plyr->object.y][g->plyr->object.x]);
	if (*state == 'd')
		*state = 'D';
	else if (*state =='D')
		*state = 'd';
}
