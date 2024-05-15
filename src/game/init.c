/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:58 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/15 11:44:15 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// char * mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
int	init_textures(t_game *g)
{
	int		x;
	int		y;
	int		ctr;

	ctr = -1;
	while (++ctr < 4)
	{
		g->texts[ctr] = malloc(sizeof(t_img));
		g->texts[ctr]->mlx_img = mlx_xpm_file_to_image(g->win->mlx, g->map->text_files[ctr], &x, &y);
		g->texts[ctr]->addr = mlx_get_data_addr(g->texts[ctr]->mlx_img, &(g->texts[ctr]->bpp), \
		&(g->texts[ctr]->len), &(g->texts[ctr]->endian));
		if (ctr == 0 || ctr == 3)
			reverse_texture(g->texts[ctr]);
	}
	g->dlsr = malloc(sizeof(t_img));
	g->dlsr->mlx_img = mlx_xpm_file_to_image(g->win->mlx, DSLR, &x, &y);
	g->dlsr->addr = mlx_get_data_addr(g->dlsr->mlx_img, &(g->dlsr->bpp), &(g->dlsr->len), &(g->dlsr->endian));
	return (1); // meaningfull error handling tbi
}

int	init_frame(t_game *g)
{
	t_img	*f;
	void	*mlx;

	mlx = g->win->mlx;
	f = malloc(sizeof(t_img));
	f->mlx_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->mlx_img, &(f->bpp), &(f->len), &(f->endian));
	ft_memset(f->addr, 0, (f->len * HEIGHT)); // not necessary?
	fill_bg(f, g->map->c, g->map->f);
	g->frame = f;
	return (1); // meaningfull error handling tbi
}

static void	init_moves(t_game *g)
{
	g->player->move[0] = 0;
	g->player->move[1] = 0;
	g->player->move[2] = 0;
	g->player->move[3] = 0;
	g->player->move[4] = 0;
	g->player->move[5] = 0;
}

int	init_player(t_game *g)
{
	g->player = malloc(sizeof(t_player));
	set_coordf(0, 0, &(g->player->coord));
	set_coordf(0, 0, &(g->player->view));
	init_moves(g);
	while (g->map->m[(int) g->player->coord.y])
	{
		g->player->coord.x = 0;
		while (g->map->m[(int) g->player->coord.y][(int) g->player->coord.x])
		{
			if (g->map->m[(int) g->player->coord.y][(int) g->player->coord.x] == 'N')
				set_coordf(0, -1, &g->player->view);
			if (g->map->m[(int) g->player->coord.y][(int) g->player->coord.x] == 'E')
				set_coordf(1, 0, &g->player->view);
			if (g->map->m[(int) g->player->coord.y][(int) g->player->coord.x] == 'S')
				set_coordf(0, 1, &g->player->view);
			if (g->map->m[(int) g->player->coord.y][(int) g->player->coord.x] == 'W')
				set_coordf(-1, 0, &g->player->view);
			if (g->player->view.x != 0 || g->player->view.y != 0)
				return (1);
			g->player->coord.x++;
		}
		g->player->coord.y++;
	}
	return (0);
}
