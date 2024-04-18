/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:38:15 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 15:56:52 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

static int	check_extension(char *file)
/*Check if the input file has the .cub extension.
Returns 1 if file has .cub extension, 0 if it hasn't */
{
	int		len;
	char	*temp;

	if (!file || !*file)
		return (0);
	len = ft_strlen(file);
	temp = ft_substr(file, len - 4, 4);
	if (ft_strcmp(".cub", temp) == 0)
	{
		free(temp);
		return (1);
	}
	return (0);
}

static int	get_content(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (*line == 'N')
			extract_path(&map->no, line);
		else if (*line == 'S')
			extract_path(&map->so, line);
		else if (*line == 'W')
			extract_path(&map->we, line);
		else if (*line == 'E')
			extract_path(&map->ea, line);
		// else if (*line == 'F')
		// 	map->f[0] = extract_colors(line);
		// else if (*line == 'C')
		// 	map->c[0] = extract_colors(line);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
// ◦Except for the map, each type of information from an element can be separated
// by one or more space(s).

	// contains NESW textures
	// all 4 are valid files

	// contains floor and ceiling color
	// both valid RGB colors

	// there's a map
	// 6 possible chars: 0,1,N,S,E,W
	// map is surrounded by walls
	// only 1 player

}

int	parsing(int argc, char **argv, t_map *map)
/* Checking arguments, valid file and file content.*/
{
	int	fd;

	if (argc != 2)
		handle_error(ERR_ARGC, 1, map, NULL);
	if (!check_extension(argv[1]))
		handle_error(ERR_FILE, 1, map, NULL);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		handle_error(ERR_FILE, 1, map, NULL);
	init_map(map);
	get_content(fd, map);
	return (1);
}
