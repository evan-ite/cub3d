/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 14:45:40 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/27 16:24:25 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Taking the RGB values and putting it in an integer which is returned. */
// static uint32_t	create_color(int red, int green, int blue, t_map *map)
static uint32_t	create_color(char ***rgb, t_map *map)
{
	uint32_t	color_integer;
	int			red;
	int			green;
	int			blue;

	red = ft_atoi((*rgb)[0]);
	green = ft_atoi((*rgb)[1]);
	blue = ft_atoi((*rgb)[2]);
	if (red < 0 || red > 255 || green < 0 || green > 255 || \
		blue < 0 || blue > 255)
	{
		free_array((void **)(*rgb), -1);
		handle_error(ERR_COL, 1, map, NULL);
	}
	color_integer = 0;
	color_integer |= (uint32_t)blue;
	color_integer |= ((uint32_t)green << 8);
	color_integer |= ((uint32_t)red << 16);
	return (color_integer);
}

/* Checks if the input contains 3 digits divides by comma's */
static int	check_rgb(char *str)
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

static void	find_start_end(int *start, int *i, char *str, t_map *m)
{
	*i = *start + 1;
	while (ft_isspace(str[*i]))
		(*i)++;
	*start = *i;
	while (ft_isdigit(str[*i]) || str[*i] == ',')
		(*i)++;
	if (str[*i + 1] && !ft_isspace(str[*i + 1]))
		handle_error(ERR_COL, 1, m, NULL);
}

/* Extracts the RGB color from a string and converts it to an integer */
int	extract_color(int start, char *str, t_map *m)
{
	int		i;
	char	*temp;
	char	**rgb;
	int		result;

	find_start_end(&start, &i, str, m);
	temp = ft_substr(str, start, i - start);
	if (!temp || !check_rgb(temp))
	{
		free(temp);
		handle_error(ERR_COL, 1, m, NULL);
	}
	rgb = ft_split(temp, ',');
	free(temp);
	if (!rgb)
		handle_error(ERR_MEM, 1, m, NULL);
	result = create_color(&rgb, m);
	free_array((void **)rgb, -1);
	return (result);
}
