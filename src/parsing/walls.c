/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:58:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/04/22 10:23:34 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// Loop over each tile in the map
	// if i + 1, i - 1, j + 1 or j - 1 doesn't exist/ is empty
		// if current tile not a wall
			// Invalid map

static int	check_surrounding(char** tiles, int i, int j, t_map *map)
{
	if (tiles[i + 1][j] && ft_isspace(tiles[i + 1][j]))
	{
		if (tiles[i][j] != '1')
			handle_error(ERR_MAP, 1, map, NULL);
	}
	else if (tiles[i - 1][j] && ft_isspace(tiles[i - 1][j]))
	{
		if (tiles[i][j] != '1')
			handle_error(ERR_MAP, 1, map, NULL);
	}
	else if (tiles[i][j + 1] && ft_isspace(tiles[i][j + 1]))
	{
		if (tiles[i][j] != '1')
			handle_error(ERR_MAP, 1, map, NULL);
	}
	else if (tiles[i][j - 1] && ft_isspace(tiles[i][j - 1]))
	{
		if (tiles[i][j] != '1')
			handle_error(ERR_MAP, 1, map, NULL);
	}
	return (1);
}

int	check_walls(t_map *map)
{
	char	**tiles;
	int		i;
	int		j;

	tiles = map->map;
	i = 0;
	while (tiles[i])
	{
		j = 0;
		while(tiles[i][j])
		{
			check_surrounding(tiles, i, j, map);
			j++;
		}
		i++;
	}
	return (1);
}

