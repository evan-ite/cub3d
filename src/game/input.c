/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:17:39 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/15 15:30:51 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	on_end(t_game *g)
{
	// free_game(g);
	(void) g;
	exit(0);
}

int	turn(t_game *g, char dir, float speed)
{
	float	dir_x = g->player->view.x;
	float	dir_y = g->player->view.y;

	// printfd("%f, %f, %f\n", dir_x, dir_y, speed);

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

// 0 left, 1 up, 2 down, 3 right, 4 turn l, 5 turn r
int	key_on(int keysym, t_game *g)
{
	if (keysym == 97) // a
		g->player->move[0] = 1;
	if (keysym == 65362 || keysym == 119) // up or w
		g->player->move[1] = 1;
	if (keysym == 65364 || keysym == 115) // down or s
		g->player->move[2] = 1;
	if (keysym == 100) // d
		g->player->move[3] = 1;
	if (keysym == 65361) // left
		g->player->move[4] = 1;
	if (keysym == 65363) // right
		g->player->move[5] = 1;
	if (keysym == 65307) //esc
		on_end(g);
	return (0);
}

int	key_off(int keysym, t_game *g)
{
	if (keysym == 97) // a
		g->player->move[0] = 0;
	if (keysym == 65362 || keysym == 119) // up or w
		g->player->move[1] = 0;
	if (keysym == 65364 || keysym == 115) // down or s
		g->player->move[2] = 0;
	if (keysym == 100) // d
		g->player->move[3] = 0;
	if (keysym == 65361) // left
		g->player->move[4] = 0;
	if (keysym == 65363) // right
		g->player->move[5] = 0;
	if (keysym == 32) // space
		open_doors(g);
	return (0);
}

int	on_mouse_click(int button,int x,int y, t_game *g)
{
	(void) button;
	(void) g;
	printfd("%d, %d \n", x, y);
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
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
