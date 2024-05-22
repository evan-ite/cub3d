/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:38:15 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 16:25:33 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static void	check_element(int i, char *line, t_map *map)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
		map->text_files[0] = extract_path(i, line, map);
	else if (line[i] == 'S' && line[i + 1] == 'O')
		map->text_files[2] = extract_path(i, line, map);
	else if (line[i] == 'W' && line[i + 1] == 'E')
		map->text_files[3] = extract_path(i, line, map);
	else if (line[i] == 'E' && line[i + 1] == 'A')
		map->text_files[1] = extract_path(i, line, map);
	else if (line[i] == 'F')
		map->f = extract_color(i, line, map);
	else if (line[i] == 'C')
		map->c = extract_color(i, line, map);
}

static int	get_content(t_map *map)
{
	char	*line;
	int		i;
	int		width;

	line = get_next_line(map->fd);
	width = 0;
	while (line)
	{
		map->fd_lines++;
		i = -1;
		while (ft_isspace(line[++i]))
			map->fd_lines++;
		check_element(i, line, map);
		if (map_line(line, 0, map))
		{
			map->max_height++;
			width = ft_strlen(line);
			if (width > map->max_width)
				map->max_width = width;
		}
		free(line);
		line = get_next_line(map->fd);
	}
	return (1);
}

/* Checking arguments, valid file and file content.*/
int	parsing(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		handle_error(ERR_ARGC, 1, NULL, NULL);
	if (!check_extension(argv[1]))
		handle_error(ERR_FILE, 1, NULL, NULL);
	init_map(map);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		handle_error(ERR_FILE, 1, map, NULL);
	get_content(map);
	if (map->max_height == 0 || map->max_width == 0)
		handle_error(ERR_MAP, 1, map, NULL);
	ft_close(&map->fd);
	map->fd = open(argv[1], O_RDONLY);
	get_map(map);
	ft_close(&map->fd);
	check_struct(map);
	return (1);
}
