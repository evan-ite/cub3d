/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:18:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/14 14:45:09 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
/* Initializes map struct */
{
	map->m = NULL;
	map->text_files[0] = NULL;
	map->text_files[1] = NULL;
	map->text_files[2] = NULL;
	map->text_files[3] = NULL;
	map->f = -1;
	map->c = -1;
	map->max_height = 0;
	map->max_width = 0;
	map->fd = -1;
	map->fd_lines = 0;
}

char	*extract_path(int start, char *str, t_map *map)
/* extracts the filepath from str and saves it in dest */
{
	int		i;
	int		fd_valid;
	int		len;
	char	*path;

	len = ft_strlen(str);
	i = start + 2;
	while (ft_isspace(str[i]))
		i++;
	path = ft_substr(str, i, len - i);
	if (!path)
		handle_error(ERR_MEM, 1, map, NULL);
	len = ft_strlen(path);
	if (path[len - 1] == '\n')
		path[len - 1] = '\0';
	fd_valid = open(path, O_RDONLY);
	if (fd_valid == -1)
		handle_error(ERR_TEXT, 1, map, NULL);
	close(fd_valid);
	return (path);
}

int	check_struct(t_map *map)
/* checks if all the necessary values are valid in the struct.
	If somethings wrong an error is handled and the program will exit,
	if the struct is valid the function returns 1. */
{
	if (!map->m)
		handle_error(ERR_MAP, 1, map, NULL);
	if (!map->text_files[0] || !map->text_files[1] \
		|| !map->text_files[2] || !map->text_files[3])
		handle_error(ERR_TEXT, 1, map, NULL);
	if (map->f == -1 || map->c == -1)
		handle_error(ERR_COL, 1, map, NULL);
	if (map->max_height == 0 || map->max_width == 0)
		handle_error(ERR_MAP, 1, map, NULL);
	return (1);
}
