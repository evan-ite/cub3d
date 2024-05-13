/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:28:14 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/13 11:05:44 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_mapchar(char c)
{
	if (c == '1' || c == '0' || c == ' ' || c == '\n')
		return (1);
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	else
		return (0);
}

static int	white_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	map_line(char *str)
{
	int	i;

	i = 0;
	if (white_line(str))
		return (0);
	while (str[i])
	{
		if (!is_mapchar(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	get_map(t_map *map)
{
	char	*line;
	int		len;
	int		i;

	map->map = gnl_calloc(map->max_height + 1, sizeof(char *));
	if (!map)
		handle_error(ERR_MEM, 1, map, NULL);
	i = -1;
	line = get_next_line(map->fd);
	while (line)
	{
		if (map_line(line))
		{
			len = ft_strlen(line);
			if (line[len - 1] == '\n')
				line[len - 1] = '\0';
			map->map[i] = ft_strdup(line);
			if (!map->map[++i])
				handle_error(ERR_MEM, 1, map, NULL);
		}
		free(line);
		line = get_next_line(map->fd);
	}
	check_valid(map);
	return (1);
}
