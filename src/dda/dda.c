/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/03 17:10:17 by jstrozyk         ###   ########.fr       */
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
	float	width_ratio;
	t_coord	plane;
	t_coord	cam;
	t_coord	ray_dir;
	t_coord	side_dist;
	t_coord	delta_dist;

	ctr = -1;
	plane = perp_vec(g->player->view);
	set_coord(g->player->view.x, g->player->view.y, &cam);
	width_ratio = FOV / WIDTH;

	// Perform DDA for each column of the screen
	while (++ctr < WIDTH)
	{
		// Calculate ray direction
		cam.x = (2 * ctr / (float) WIDTH) * FOV;// x-coordinate in camera space
		cam.x += width_ratio * 0.5;
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

		// calculate intersection points or x-axis ratio
		float intersection_x, intersection_y;
		if (!side)
		{
			intersection_x = (float)(g->player->coord.x + wall_dist * ray_dir.x);
			intersection_y = cell_y + ((ray_dir.y > 0) ? 1 : 0);
		}
		else
		{
			intersection_x = cell_x + ((ray_dir.x > 0) ? 1 : 0);
			intersection_y = g->player->coord.y + wall_dist * ray_dir.y;
		}

		// Calculate height of line to draw on screen
		height = (int)(HEIGHT / wall_dist);
		if (height >= HEIGHT)
			height = HEIGHT - 1;
		if (!side && step_x < 0)
			draw_line(height, ctr, 1, 0, g);
		if (!side && step_x > 0)
			draw_line(height, ctr, 1, 1, g);
		if (side && step_y < 0)
			draw_line(height, ctr, 1, 2, g);
		if (side && step_y > 0)
			draw_line(height, ctr, 1, 3, g);
	}
}

//int	draw_line(int height, int col, int dir, t_game *g)
