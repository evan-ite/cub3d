/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/18 16:19:43 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_window()
{
	int	x;
	int	y;

	x = (BLOCK_SIZE * g->max_x);
	if (x < 9)
		x = 9;
	y = (BLOCK_SIZE * (g->max_y + HUD_SIZE));
	if (!mlx_ptr)
		return (-1);
	w->mlx_ptr = mlx_ptr;
	w->win_ptr = mlx_new_window(w->mlx_ptr, x, y, WINDOW_NAME);
	w->bg_ptr = ftoi(w, BACKG, 1, 1);
	w->block_ptr = ftoi(w, BLOCK, 1, 1);
	w->coin_ptr = ftoi(w, COIN, 1, 1);
	w->enemy_1_ptr = ftoi(w, E1, 1, 1);
	w->enemy_2_ptr = ftoi(w, E2, 1, 1);
	w->enemy = w->enemy_1_ptr;
	w->exit_ptr = ftoi(w, DOOR, 1, 1);
	w->player_1_ptr = ftoi(w, P1, 1, 1);
	w->player_2_ptr = ftoi(w, P2, 1, 1);
	w->player_3_ptr = ftoi(w, P3, 1, 1);
	w->player_4_ptr = ftoi(w, P4, 1, 1);
	w->player = w->player_1_ptr;
	_init_hud(w);
	return (1);
}
}

int	start_game(t_map *map)
{

}
