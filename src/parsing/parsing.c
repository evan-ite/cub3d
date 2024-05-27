/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:38:15 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/27 12:11:35 by jstrozyk         ###   ########.fr       */
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
	free(temp);
	return (0);
}

/* checks if line is a color element, if color is sucessfully extracted
function will return 1, on failure return 0*/
static int	check_elements2(int i, char *line, t_map *map)
{
	if (line[i] == 'E' && line[i + 1] == 'A')
	{
		if (map->text_files[1])
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->text_files[1] = extract_path(i, line, map);
		return (1);
	}
	else if (line[i] == 'F')
	{
		if (map->f > -1)
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->f = extract_color(i, line, map);
		return (1);
	}
	else if (line[i] == 'C')
	{
		if (map->c > -1)
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->c = extract_color(i, line, map);
		return (1);
	}
	return (0);
}

/* checks if line is a texture element, if texture is sucessfully extracted
function will return 1, on failure return 0*/
static int	check_element(int i, char *line, t_map *map)
{
	if (line[i] == 'N' && line[i + 1] == 'O')
	{
		if (map->text_files[0])
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->text_files[0] = extract_path(i, line, map);
		return (1);
	}
	else if (line[i] == 'S' && line[i + 1] == 'O')
	{
		if (map->text_files[2])
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->text_files[2] = extract_path(i, line, map);
		return (1);
	}
	else if (line[i] == 'W' && line[i + 1] == 'E')
	{
		if (map->text_files[3])
			handle_error(ERR_DOUBLE, 1, map, NULL);
		map->text_files[3] = extract_path(i, line, map);
		return (1);
	}
	return (check_elements2(i, line, map));
}

static int	get_content(t_map *map)
{
	int		i;
	int		width;

	map->line = get_next_line(map->fd);
	width = 0;
	while (map->line)
	{
		map->fd_lines++;
		i = -1;
		while (ft_isspace(map->line[++i]))
			map->fd_lines++;
		if (!check_element(i, map->line, map))
		{
			if (!check_map(map->line, &width, map) && !white_line(map->line))
				handle_error(ERR_ELEMENT, 1, map, NULL);
		}
		free(map->line);
		map->line = get_next_line(map->fd);
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
