/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:20:10 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/25 17:46:16 by jstrozyk         ###   ########.fr       */
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

	set_coord(0, 1, &plane);
	set_coord(0, 1, &cam);
	ctr = -1;
	while (++ctr <= WIDTH)
	{
	// Perform DDA for each column of the screen
	// for (int x = 0; x < MAP_WIDTH; x++) {
		// Calculate initial position and direction
		// double posX = px;
		// double posY = py;
		// double dirX = vx;
		// double dirY = vy;

		// Camera plane perpendicular to the direction
		// double planeX = 0;
		// double planeY = 1;

		// Calculate ray direction
		cam.x = 2 * ctr / (double)WIDTH - 1; // x-coordinate in camera space
		ray_dir.x = g->player->coord.x + plane.x * cam.x;
		ray_dir.y = g->player->coord.y + plane.y * cam.x;

		// Map position
		cell_x = (int) g->player->coord.x;
		cell_y = (int) g->player->coord.y;

		// Length of ray from current position to next x or y-side
		// double sideDistX;
		// double sideDistY;

		// Length of ray from one side to next in map
		delta_dist.x = fabs(1 / ray_dir.x);
		delta_dist.y = fabs(1 / ray_dir.y);

		// Direction to step in x and y


		// Calculate step and initial sideDist
		if (ray_dir.x < 0) {
			step_x = -1;
			side_dist.x = (g->player->coord.x - cell_x) * delta_dist.x;
		} else {
			step_x = 1;
			side_dist.x = (cell_x + 1.0 - g->player->coord.x) * delta_dist.x;
		}
		if (ray_dir.y < 0) {
			step_y = -1;
			side_dist.y = (g->player->coord.y - cell_y) * delta_dist.y;
		} else {
			step_y = 1;
			side_dist.y = (cell_y + 1.0 - g->player->coord.y) * delta_dist.y;
		}

		// DDA algorithm loop
		hit = 0; // Was a wall hit?
		while (!hit) {
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
			// Check if ray has hit a wall
			printf("%d, %d, %d\n", cell_x, cell_y, side);
			printf("%c\n", g->map->map[cell_y - 1][cell_x - 1]);
			if (g->map->map[cell_y][cell_x] == 1)
				hit = 1;
		}

		// Calculate distance projected on camera direction
		if (!side)
			wall_dist = (cell_x - g->player->coord.x + (1 - step_x) / 2) / ray_dir.x;
		else
			wall_dist = (cell_y - g->player->coord.y + (1 - step_y) / 2) / ray_dir.y;

		// Calculate height of line to draw on screen
		height = (int)(HEIGHT / wall_dist);

		// Calculate lowest and highest pixel to fill in current stripe
		int drawStart = -height / 2 + HEIGHT / 2;
		if(drawStart < 0) drawStart = 0;
		int drawEnd = height / 2 + HEIGHT / 2;
		if(drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

		// Draw the vertical line for this column
		for (int y = 0; y < HEIGHT; y++) {
			if (y >= drawStart && y <= drawEnd) {
				if (side == 1) printf("|"); // EW wall
				else printf("-");            // NS wall
			} else {
				printf(" "); // Space for empty space
			}
		}
		printf("\n");
	}
}

