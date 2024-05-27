/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:51:00 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/27 12:07:57 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	on_end(t_game *g)
{
	free_game(g);
	free_images(g);
	mlx_destroy_window(g->win->mlx, g->win->win);
	mlx_destroy_display(g->win->mlx);
	free(g->plyr);
	free(g->win->mlx);
	exit(0);
}

void	handle_error(char *err_msg, int err_code, t_map *map, void *game)
{
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	if (map)
	{
		free_map(map);
		exit(err_code);
	}
	if (game)
		on_end(game);
	exit(err_code);
}

