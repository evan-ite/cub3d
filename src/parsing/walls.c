/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:58:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/13 11:21:49 by evan-ite         ###   ########.fr       */
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

static void	flood_fill(int x, int y, char **tiles, t_map *map)
{
	if (x < 0 || x > map->max_width || y < 0 || y > map->max_height)
		handle_error(ERR_MAP, 1, map, NULL);
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

	copy = copy_map(map->map, map->max_height);
	i = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'N')
				flood_fill(j, i, copy, map);
			j++;
		}
		i++;
	}
	free_array((void **)copy, -1);
	return (1);
}
