/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:28:14 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/19 16:20:47 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_mapchar(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\n')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

int	map_line(char *str)
{
	int	i;
	int	space;

	i = 0;
	space = 0;
	while (str[i])
	{
		if (!is_mapchar(str[i]))
			return (0);
		if (ft_isspace(str[i]))
			space++;
		i++;
	}
	if (space == (int)ft_strlen(str))
		return (0);
	return (1);
}

int	get_map(t_map *map)
{
	map->map = gnl_calloc(map->max_height, sizeof(char *));
	if (!map)
		handle_error(ERR_MEM, 1, map, NULL);

	// 6 possible chars: 0,1,N,S,E,W
	// map is surrounded by walls
	// only 1 player
	return (1);
}
