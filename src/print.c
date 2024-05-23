/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:51:20 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/23 12:28:39 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_map(t_map *map)
{
	int	i;

	ft_printf("------ 	PRINT MAP -----\n");
	ft_printf("North: '%s'\n", map->text_files[0]);
	ft_printf("South: '%s'\n", map->text_files[2]);
	ft_printf("West: '%s'\n", map->text_files[3]);
	ft_printf("East: '%s'\n", map->text_files[2]);
	ft_printf("Floor color: %i\n", map->f);
	ft_printf("Ceiling color: %i\n", map->c);
	ft_printf("Max width: %i\n", map->max_width);
	ft_printf("Max height: %i\n", map->max_height);
	if (map->m)
	{
		i = -1;
		while (++i < map->max_height)
			ft_printf("map[%i]: %s\n", i, map->m[i]);
	}
}

void	print_img(t_img *i)
{
	ft_printf("------ 	PRINT IMAGE -----\n");
	ft_printf("addr(10): '%.10s'\n", i->addr);
	ft_printf("bpp: '%d'\n", i->bpp);
	ft_printf("endian: '%d'\n", i->endian);
	ft_printf("len: '%d'\n", i->len);
	ft_printf("mlx_img: %p\n", i->mlx_img);
}

void	printfd(const char *format, ...)
{
	va_list	args;

	if (!DEBUG)
		return ;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
