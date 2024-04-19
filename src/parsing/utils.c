/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:18:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/19 16:23:44 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_map(t_map *map)
/* Initializes map struct */
{
	map = gnl_calloc(1, sizeof(t_map));
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = -1;
	map->c = -1;
	map->max_height = 100;
	map->max_width = 100;
	map->fd = -1;
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
	if ( fd_valid == -1)
		handle_error(ERR_TEXT, 1, map, NULL);
	close(fd_valid);
	return (path);
}
