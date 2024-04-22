/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:20 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/22 16:28:57 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	printf("------ 	PRINT MAP -----\n");
	printf("North: '%s'\n", map->no);
	printf("South: '%s'\n", map->so);
	printf("West: '%s'\n", map->we);
	printf("East: '%s'\n", map->ea);
	printf("Floor color: %i\n", map->f);
	printf("Ceiling color: %i\n", map->c);
	printf("Max width: %i\n", map->max_width);
	printf("Max height: %i\n", map->max_height);
	if (map->map)
	{
		for (int i = 0; i < map->max_height; i++)
			printf("map[%i]: %s\n", i, map->map[i]);
	}
}
