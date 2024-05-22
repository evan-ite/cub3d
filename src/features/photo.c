/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   photo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:42:51 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 13:00:13 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

/* Calculates difference between kim and the player.
returns 1 if player is close enough to take photo, 0 otherwise */
// static int	distance_kim(t_game *g)
// {
// 	int	distx;
// 	int	disty;

// 	distx = g->player->coord.x - g->sm.sp_coor[g->sm.order[g->sm.sp_left - 1]].x;
// 	disty = g->player->coord.y - g->sm.sp_coor[g->sm.order[g->sm.sp_left - 1]].y;
// 	if (abs(distx) < 3 && abs(disty) < 3)
// 		return (1);
// 	return (0);
// }

/* Creates a flash on the screen if player is close to
kim and presses spacebar */
void	take_photo(t_game *g)
{
	int		size;
	void	*img;

	if (g->player->interact != 'X')
		return ;

	// Draw different kim textures in pixel
	size = KIMSIZE;
	img = mlx_xpm_file_to_image(g->win->mlx, FLASH, &size, &size);
	mlx_put_image_to_window(g->win->mlx, g->win->win, img, WIDTH / 3, HEIGHT / 4);
	mlx_do_sync(g->win->mlx);
	g->map->m[g->sm.sp_coor[g->sm.order[g->sm.sp_left - 1]].y][g->sm.sp_coor[g->sm.order[g->sm.sp_left - 1]].x] = '0';
	// sleep(1);
	mlx_destroy_image(g->win->mlx, img);
	g->photos++;
	if (g->photos == g->map->n_kim)
		g->won = 1;
}
