/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:40 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/19 15:12:37 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static uint32_t	create_color(int red, int green, int blue, t_map *map)
/* Taking the RGB values and putting it in an integer which is returned. */
{
	uint32_t	color_integer;

	if (red < 0 || red > 255 || green < 0 || green > 255 ||\
		blue < 0 || blue > 255)
		handle_error(ERR_COL, 1, map, NULL);
	color_integer = 0;
	color_integer |= (uint32_t)blue;
	color_integer |= ((uint32_t)green << 8);
	color_integer |= ((uint32_t)red << 16);

	return color_integer;
}

static int	check_rgb(char *str)
/* Checks if the input contains 3 digits divides by comma's */
{
	int	i;
	int	comma;

	if (!str || !*str)
		return (0);
	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma == 2)
		return (1);
	else
		return (0);
}

int	extract_color(int start, char *str, t_map *map)
/* Extracts the RGB color from a string and converts it to an integer */
{
	int		i;
	char	*temp;
	char	**rgb;
	int		result;

	i = start + 1;
	while (ft_isspace(str[i]))
		i++;
	start = i;
	while (ft_isdigit(str[i]) || str[i] == ',')
		i++;
	temp = ft_substr(str, start, i - start);
	if (!temp)
		handle_error(ERR_MEM, 1, map, NULL);
	if (!check_rgb(temp))
		handle_error(ERR_COL, 1, map, NULL);
	rgb = ft_split(temp, ',');
	free(temp);
	if (!rgb)
		handle_error(ERR_MEM, 1, map, NULL);
	result = create_color(ft_atoi(rgb[0]), ft_atoi(rgb[1]), ft_atoi(rgb[2]), map);
	free_array((void **)rgb, -1);
	return (result);
}
