/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:28:14 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/29 15:16:13 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* checks if the argument is a valid character in the map.
Returns NULL if not valid */
char	*is_mapchar(char c)
{
	if (BONUS)
		return (ft_strchr("\n 10NSWEDX", c));
	else
		return (ft_strchr("\n 10NSWE", c));
}

/* Checks if the argument is a white line, returns 1 if
line is a white line and 0 if not */
int	white_line(char *line)
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

/* Checks if input string is a valid line. if i_line is > 0 it represents,
the line count of the line in the original file. This way its possible to check
wether a line is part of the map, if so characters are checked. An error
exits the program if invalid chars are found in the map.
Returns 0 if line if invalid or whiteline, returns
1 for a valid line */
int	map_line(char *str, int i_line, t_map *map)
{
	int	i;
	int	start_map;

	i = 0;
	if (white_line(str))
		return (0);
	while (str[i])
	{
		if (!is_mapchar(str[i]))
		{
			if (i_line)
			{
				start_map = map->fd_lines - map->max_height - 1;
				if (i_line >= start_map)
					handle_error(ERR_MAP, 1, map, NULL);
				return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

/* Copy line into map->map[i] without newline character at the end*/
static void	copy_line(char *line, int *i, t_map *map)
{
	int		len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	map->m[*i] = ft_strdup(line);
	if (!map->m[*i])
		handle_error(ERR_MEM, 1, map, NULL);
	(*i)++;
}

int	get_map(t_map *map)
{
	int		i;
	int		count;

	map->m = gnl_calloc(map->max_height + 1, sizeof(char *));
	if (!map)
		handle_error(ERR_MEM, 1, map, NULL);
	i = 0;
	count = 0;
	map->line = get_next_line(map->fd);
	while (map->line)
	{
		count++;
		if (map_line(map->line, count, map))
			copy_line(map->line, &i, map);
		if (i > 0 && white_line(map->line))
			handle_error(ERR_MAP, 1, map, NULL);
		free(map->line);
		map->line = get_next_line(map->fd);
	}
	check_valid(map);
	return (1);
}
