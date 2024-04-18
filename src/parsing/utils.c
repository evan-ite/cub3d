/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:18:41 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 15:58:14 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

void	init_map(t_map *map)
/* Initializes map struct */
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f[0] = -1;
	map->f[1] = -1;
	map->f[2] = -1;
	map->c[0] = -1;
	map->c[1] = -1;
	map->c[2] = -1;
	map->max_height = 0;
	map->max_width = 0;
}

int	extract_path(char **dest, char *str)
/* extracts the filepath from str and saves it in dest */
{
	int		i;
	int		len;
	char	*path;

	len = ft_strlen(str);
	i = 2;
	while (ft_isspace(str[i]))
		i++;
	path = ft_substr(str, i, len - i);
	*dest = ft_strdup(path);
	printf("path = %s\n", path);
	free(path);
	return (1);
}

int	extract_colors(char *str)
/* extracts the RGB colors from str and saves it in dest */
{
	printf("extract colors %s\n", str);
	return (1);
}
