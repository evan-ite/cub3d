/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:17:39 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/03 12:21:21 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	on_end(t_game *g)
{
	// free_game(g);
	(void) g;
	exit(0);
}

static	int	turn(t_game *g, char dir, float speed)
{
	float	dir_x = g->player->view.x;
	float	dir_y = g->player->view.y;

	printfd("%f, %f, %f\n", dir_x, dir_y, speed);

	if (dir == 'r')
	{
		// turn right
		g->player->view.x = dir_x * cos(speed) - dir_y * sin(speed);
		g->player->view.y = dir_x * sin(speed) + dir_y * cos(speed);

	}
	else
	{
		// turn left
		g->player->view.x = dir_x* cos(-speed) - dir_y * sin(-speed);
		g->player->view.y = dir_x * sin(-speed) + dir_y * cos(-speed);
	}
	return (0);
}

int	on_keypress(int keysym, t_game *g)
{
	t_coord	change;

	set_coord(0, 0, &change);
	if (keysym == 65361) // left
		turn(g, 'l', TURNSPEED);
	if (keysym == 97) // a
		change.x = -0.5;
	if (keysym == 65362 || keysym == 119) // up or w
		change.y = -0.5;
	if (keysym == 65364 || keysym == 115) // down or s
		change.y = 0.5;
	if (keysym == 65363) // right
		turn(g, 'r', TURNSPEED);
	if (keysym == 100) // d
		change.x = 0.5;
	if (keysym == 65307) //esc
		on_end(g);
	add_vectors(&(g->player->coord), &change);
	return (0);
}

int	on_mouse_click(int button,int x,int y, t_game *g)
{
	(void) button;
	(void) g;
	printfd("%d, %d \n", x, y);
	return (0);
}

int	on_mouse_move(int x, int y, t_game *g)
{
	float	turnval;

	(void)y;
	turnval = MOUSE_SENS * fabs((float)x / 1000000);
	if ((x - WIDTH/2) < 0)
		turn(g, 'l', turnval);
	else if ((x - WIDTH/2) > 0)
		turn(g, 'r', turnval);
	mlx_mouse_move(g->win->mlx, g->win->win, WIDTH/2, HEIGHT/2);
	return (0);
}
