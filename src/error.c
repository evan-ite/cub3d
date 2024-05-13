/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:51:00 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 12:56:37 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while(i < 4)
	{
		if (map->text_files[i])
		{
			free(map->text_files[i]);
			map->text_files[i] = NULL;
		}
		i++;
	}
	if (map->map)
		free_array((void **)map->map, -1);
	ft_close(&map->fd);
	free(map);
}

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	// free other stuff
	free(game);
}

void	handle_error(char *err_msg, int err_code, t_map *map, void *game)
{
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	if (map)
		free_map(map);
	if (game)
		free_game(game);
	exit(err_code);
}
