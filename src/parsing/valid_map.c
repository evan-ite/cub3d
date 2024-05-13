/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:04:47 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/13 12:11:45 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// checks if map only contains 6 possible chars: 0,1,N,S,E,W,space
static int	valid_chars(char *str)
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
	while (map->map[i])
	{
		if (!valid_chars(map->map[i]))
			handle_error(ERR_MAP, 1, map, NULL);
		j = 0;
		while (map->map[i][j])
		{
			if (ft_strchr("NESW", map->map[i][j]))
				player++;
			j++;
		}
		i++;
	}
	if (player != 1)
		handle_error(ERR_MAP, 1, map, NULL);
	check_walls(map);
	return (1);
}
