/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:17:39 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/06/03 17:12:40 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	do_action(t_game *g)
{
	if (!g->plyr->interact)
		return ;
	if ((int) g->plyr->crd.x == g->plyr->object.x && \
	(int) g->plyr->crd.y == g->plyr->object.y)
		return ;
	if ('X' == g->plyr->interact)
		take_photo(g);
	else
		open_doors(g);
}

int	turn(t_game *g, char dir, float speed)
{
	float	dir_x;
	float	dir_y;

	dir_x = g->plyr->view.x;
	dir_y = g->plyr->view.y;
	if (dir == 'r')
	{
		g->plyr->view.x = dir_x * cos(speed) - dir_y * sin(speed);
		g->plyr->view.y = dir_x * sin(speed) + dir_y * cos(speed);
	}
	else
	{
		g->plyr->view.x = dir_x * cos(-speed) - dir_y * sin(-speed);
		g->plyr->view.y = dir_x * sin(-speed) + dir_y * cos(-speed);
	}
	g->draw = 1;
	return (0);
}

// 0 left, 1 up, 2 down, 3 right, 4 turn l, 5 turn r
int	key_on(int keysym, t_game *g)
{
	if (keysym == 97)
		g->plyr->move[0] = 1;
	if (keysym == 65362 || keysym == 119)
		g->plyr->move[1] = 1;
	if (keysym == 65364 || keysym == 115)
		g->plyr->move[2] = 1;
	if (keysym == 100)
		g->plyr->move[3] = 1;
	if (keysym == 65361)
		g->plyr->move[4] = 1;
	if (keysym == 65363)
		g->plyr->move[5] = 1;
	if (keysym == 65307)
		on_end(g);
	return (0);
}

int	key_off(int keysym, t_game *g)
{
	if (keysym == 97)
		g->plyr->move[0] = 0;
	if (keysym == 65362 || keysym == 119)
		g->plyr->move[1] = 0;
	if (keysym == 65364 || keysym == 115)
		g->plyr->move[2] = 0;
	if (keysym == 100)
		g->plyr->move[3] = 0;
	if (keysym == 65361)
		g->plyr->move[4] = 0;
	if (keysym == 65363)
		g->plyr->move[5] = 0;
	if (keysym == 32)
		do_action(g);
	if (keysym == 107)
		g->start_win = 0;
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
{
	float	turnval;

	(void)y;
	turnval = MOUSE_SENS * fabs((float)x / 1000000);
	if ((x - WIDTH / 2) < 0)
		turn(g, 'l', turnval);
	else if ((x - WIDTH / 2) > 0)
		turn(g, 'r', turnval);
	mlx_mouse_move(g->win->mlx, g->win->win, WIDTH / 2, HEIGHT / 2);
	return (0);
}
