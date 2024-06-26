/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:59:29 by elisevanite       #+#    #+#             */
/*   Updated: 2024/05/15 11:20:42 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_window(t_game *g, void *mlx)
{
	g->win->mlx = mlx;
	g->win->win = mlx_new_window(mlx, WIDTH, HEIGHT, WINDOW_NAME);
}

int	main(int argc, char **argv)
{
	t_game	g;
	t_map	m;
	t_win	w;

	if (parsing(argc, argv, &m))
	{
		g.map = &m;
		g.win = &w;
		init_window(&g, mlx_init());
		start_game(&g);
		return (0);
	}
	else
		return (1);
}
