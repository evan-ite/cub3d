/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:37:34 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 14:04:28 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	open_doors(t_game *g)
{
	char	*state;

	state = &(g->map->m[g->player->object.y][g->player->object.x]);

	if (*state == 'd')
		*state = 'D';
	if (*state =='D')
		*state = 'd';
}
