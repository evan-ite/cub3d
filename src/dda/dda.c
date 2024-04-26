/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/26 16:38:34 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

#include <stdio.h>
#include <math.h>

void raycast(t_game *g)
{
	int		ctr;
	int		step_x;
	int		step_y;
	int		cell_x;
	int		cell_y;
	int		hit;
	int		side;
	int		height;
	float	wall_dist;
	t_coord	plane;
	t_coord	cam;
	t_coord	ray_dir;
	t_coord	side_dist;
	t_coord	delta_dist;

	ctr = -1;
	set_coord(0, 1, &plane);
	set_coord(0, 1, &cam);
	if (DEBUG)
		set_coord(1, 0, &(g->player->view));

	// Perform DDA for each column of the screen
	while (++ctr < WIDTH)
	{
		// Calculate ray direction
		cam.x = 2 * ctr / (float) WIDTH; // x-coordinate in camera space
		cam.x = cam.x * FOV;
		ray_dir.x = g->player->view.x + plane.x * cam.x;
		ray_dir.y = g->player->view.y + plane.y * cam.x;
		// Map position
		cell_x = (int) g->player->coord.x;
		cell_y = (int) g->player->coord.y;
		// Length of ray from one side to next in map
		delta_dist.x = fabs(1 / ray_dir.x);
		delta_dist.y = fabs(1 / ray_dir.y);
		// Calculate step and initial sideDist
		if (ray_dir.x < 0)
		{
			step_x = -1;
			side_dist.x = (g->player->coord.x - cell_x) * delta_dist.x;
		}
		else
		{
			step_x = 1;
			side_dist.x = (cell_x + 1.0 - g->player->coord.x) * delta_dist.x;
		}
		if (ray_dir.y < 0)
		{
			step_y = -1;
			side_dist.y = (g->player->coord.y - cell_y) * delta_dist.y;
		}
		else
		{
			step_y = 1;
			side_dist.y = (cell_y + 1.0 - g->player->coord.y) * delta_dist.y;
		}
		// DDA algorithm loop
		hit = 0; // Was a wall hit?
		while (!hit)
		{
			// Jump to next map square, either in x-direction or y-direction
			if (side_dist.x < side_dist.y)
			{
				side_dist.x += delta_dist.x;
				cell_x += step_x;
				side = 0; // NS wall
			}
			else
			{
				side_dist.y += delta_dist.y;
				cell_y += step_y;
				side = 1; // EW wall
			}
			if (g->map->map[cell_y][cell_x] == '1')
				hit = 1;
		}
		// Calculate distance projected on camera direction
		if (!side)
		{
			if (ray_dir.x)
				wall_dist = (cell_x - g->player->coord.x + (1 - step_x) / 2) / ray_dir.x;
			else
				wall_dist = INFINITY; // Handle division by zero case
		}
		else
		{
			if (ray_dir.y)
				wall_dist = (cell_y - g->player->coord.y + (1 - step_y) / 2) / ray_dir.y;
			else
				wall_dist = INFINITY; // Handle division by zero case
		}

		// Calculate height of line to draw on screen
		height = (int)(HEIGHT / wall_dist);
		if (height >= HEIGHT)
			height = HEIGHT - 1;
		if (side)
			draw_line(height, ctr, 0xFFF1F1F1, g);
		else
			draw_line(height, ctr, 0xFF000000, g);
	}
}

