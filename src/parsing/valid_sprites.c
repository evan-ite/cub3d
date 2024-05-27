/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_sprites.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 09:58:19 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/27 15:20:43 by evan-ite         ###   ########.fr       */
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

static int	flood_fill(int x, int y, char **tls, t_map *map)
{
	if (x < 0 || x > map->max_width || y < 0 || y > map->max_height)
		handle_error(ERR_MAP, 1, map, NULL);
	if (tls[y][x] == 'V' || tls[y][x] == '1')
		return (0);
	if (ft_strchr("NESW", tls[y][x]))
		return (1);
	tls[y][x] = 'V';
	if (flood_fill(x + 1, y, tls, map) || flood_fill(x - 1, y, tls, map))
		return (1);
	else if (flood_fill(x, y + 1, tls, map) || flood_fill(x, y - 1, tls, map))
		return (1);
	else
		return (0);
}

int	valid_sprites(t_map *map)
{
	int		i;
	int		j;
	char	**copy;

	if (map->n_kim > 100)
		handle_error(ERR_NKIM, 1, map, NULL);
	i = -1;
	while (map->m[++i])
	{
		j = -1;
		while (map->m[i][++j])
		{
			if (map->m[i][j] == 'X')
			{
				copy = copy_map(map->m, map->max_height);
				if (flood_fill(j, i, copy, map) != 1)
				{
					free_array((void **)copy, -1);
					handle_error(ERR_KIM_VALID, 1, map, NULL);
				}
				free_array((void **)copy, -1);
			}
		}
	}
	return (1);
}
