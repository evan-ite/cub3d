/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisevaniterson <elisevaniterson@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:58:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/28 11:45:05 by elisevanite      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static char	**copy_map(char **map, int height)
{
	int		i;
	char	**copy;

	copy = gnl_calloc(height + 1, sizeof(char *));
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

//!tiles[y] || !tiles[y][x] ||
static void	flood_fill(int x, int y, char **tiles, t_map *map)
{
	if (x < 0 || y < 0 || y >= map->max_height || x >= (int)ft_strlen(tiles[y]))
	{
		free_array((void **)tiles, -1);
		handle_error(ERR_MAP, 1, map, NULL);
	}
	if (tiles[y][x] == 'V' || tiles[y][x] == '1')
		return ;
	tiles[y][x] = 'V';
	flood_fill(x + 1, y, tiles, map);
	flood_fill(x - 1, y, tiles, map);
	flood_fill(x, y + 1, tiles, map);
	flood_fill(x, y - 1, tiles, map);
}

int	check_walls(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	copy = copy_map(map->m, map->max_height);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (ft_strchr("NESW", copy[i][j]))
				flood_fill(j, i, copy, map);
			j++;
		}
		i++;
	}
	free_array((void **)copy, -1);
	return (1);
}
