/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:59:29 by elisevanite       #+#    #+#             */
/*   Updated: 2024/04/18 14:35:34 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (parsing(argc, argv, map))
	{
		// start_game(map);
		printf("START GAME!! :)\n");
		return (0);
	}
	else
		return (1);
}
