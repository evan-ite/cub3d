/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:04:47 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/15 12:38:57 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	valid_chars(char *str)
// checks if map only contains 6 possible chars: 0,1,N,S,E,W,space
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!is_mapchar(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* checks if the map contains valid characters, 1 player and walls. */
int	check_valid(t_map *map)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	player = 0;
	while (map->m[i])
	{
		if (!valid_chars(map->m[i]))
			handle_error(ERR_MAP, 1, map, NULL);
		j = 0;
		while (map->m[i][j])
		{
			if (ft_strchr("NESW", map->m[i][j]))
				player++;
			if (map->m[i][j] == 'X')
				map->n_kim++;
			j++;
		}
		i++;
	}
	if (player != 1)
		handle_error(ERR_MAP, 1, map, NULL);
	check_walls(map);
	return (1);
}
