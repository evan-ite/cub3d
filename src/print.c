/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:20 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/24 14:16:11 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	printf("------ 	PRINT MAP -----\n");
	printf("North: '%s'\n", map->text_files[0]);
	printf("South: '%s'\n", map->text_files[2]);
	printf("West: '%s'\n", map->text_files[3]);
	printf("East: '%s'\n", map->text_files[2]);
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

void	print_img(t_img *i)
{
	printf("------ 	PRINT IMAGE -----\n");
	printf("addr(10): '%.10s'\n", i->addr);
	printf("bpp: '%d'\n", i->bpp);
	printf("endian: '%d'\n", i->endian);
	printf("len: '%d'\n", i->len);
	printf("mlx_img: %p\n", i->mlx_img);
}
