/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:38:15 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 12:50:44 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parsing.h"

int	parsing(int argc, char **argv, t_map *map)
{
	if (argc != 2)
		exit_error(ERR_ARGC);

//Except for the map content which always has to be the last, each type of
//element can be set in any order in the file !!!

// ◦Except for the map, each type of information from an element can be separated
// by one or more space(s).

	// right .cub extension
	// existing file

	// contains NESW textures
	// all 4 are valid files

	// contains floor and ceiling color
	// both valid RGB colors

	// there's a map
	// 6 possible chars: 0,1,N,S,E,W
	// map is surrounded by walls
	// only 1 player

}
