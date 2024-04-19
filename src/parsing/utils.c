/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:18:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 17:30:22 by jstrozyk         ###   ########.fr       */
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
}

char	*extract_path(int start, char *str)
/* extracts the filepath from str and saves it in dest */
{
	int		i;
	int		len;
	char	*path;

	len = ft_strlen(str);
	i = start + 2;
	while (ft_isspace(str[i]))
		i++;
	path = ft_substr(str, i, len - i);
	len = ft_strlen(path);
	if (path[len - 1] == '\n')
		path[len - 1] = '\0';
	return (path);
}

int	extract_color(int start, char *str)
/* extracts the RGB colors from str and saves it in dest */
{
	start++;
	str++;
	// printf("extract colors %s %i\n", str, start);
	return (1);
}
