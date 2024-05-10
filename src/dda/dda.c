#include "../../includes/cub3d.h"

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
	float	intersection_x;
	float	intersection_y;

	ctr = -1;
	plane = perp_vec(g->player->view);
	width_ratio = FOV / WIDTH;

	// Perform DDA for each column of the screen
	while (++ctr < WIDTH)
	{
		// Calculate ray direction
		cam.x = ((2 * ctr / (float) WIDTH) - 1) * FOV; // x-coordinate in camera space
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
			intersection_y = g->player->coord.y + wall_dist * ray_dir.y;
		}
		else
		{
			if (ray_dir.y)
				wall_dist = (cell_y - g->player->coord.y + (1 - step_y) / 2) / ray_dir.y;
			else
				wall_dist = INFINITY; // Handle division by zero case
			intersection_x = g->player->coord.x + wall_dist * ray_dir.x;

		}
		// Calculate fractional values for texture sampling
		float width_ratio;
		if (!side)
			width_ratio = intersection_y - cell_y; // Fractional distance along the y-axis
		else
			width_ratio = intersection_x - (float) cell_x; // Fractional distance along the x-axis

		// Calculate height of line to draw on screen
		// printfd("int_x %f int_y %f fract val %f\n",intersection_x, intersection_y, width_ratio);
		height = (int)(HEIGHT / wall_dist);
		if (!side && step_x < 0)
			draw_line(height, ctr, width_ratio, 0, g);
		if (!side && step_x > 0)
			draw_line(height, ctr, width_ratio, 1, g);
		if (side && step_y < 0)
			draw_line(height, ctr, width_ratio, 2, g);
		if (side && step_y > 0)
			draw_line(height, ctr, width_ratio, 3, g);
		// int	draw_line(int height, int col, float width_ratio, int dir, t_game *g)
	}
}
