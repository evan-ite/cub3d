/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:58 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/06/03 15:57:54 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_img	*init_img(char *path, t_game *g)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		handle_error(ERR_MEM, 1, g->map, g);
	img->mlx_img = mlx_xpm_file_to_image(g->win->mlx, \
					path, &(img->x), &(img->y));
	img->addr = mlx_get_data_addr(img->mlx_img, \
				&(img->bpp), &(img->len), &(img->endian));
	return (img);
}

int	init_textures(t_game *g)
{
	int		ctr;

	ctr = -1;
	g->map->text_files[4] = DOOR1;
	while (++ctr < 5)
		g->texts[ctr] = init_img(g->map->text_files[ctr], g);
	reverse_texture(g->texts[0]);
	reverse_texture(g->texts[3]);
	g->cam_overlay = init_img(DSLR, g);
	g->hint = init_img(HINT, g);

	if (g->map->n_kim > 0)
	{
		g->sp_data.img = init_img(KIM, g);
		g->sp_data.flash[0] = init_img("textures/flash1.xpm", g);
		g->sp_data.flash[1] = init_img("textures/flash2.xpm", g);
		g->sp_data.flash[2] = init_img("textures/flash3.xpm", g);
		g->sp_data.flash[3] = init_img("textures/flash4.xpm", g);
		g->sp_data.flash[4] = init_img("textures/flash5.xpm", g);
	}
	return (1);
}

int	init_frame(t_game *g)
{
	t_img	*f;
	void	*mlx;

	mlx = g->win->mlx;
	f = malloc(sizeof(t_img));
	f->mlx_img = mlx_new_image(mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->mlx_img, &(f->bpp), &(f->len), &(f->endian));
	ft_memset(f->addr, 0, (f->len * HEIGHT));
	fill_bg(f, g->map->c, g->map->f);
	g->frame = f;
	return (1);
}

static void	init_moves(t_game *g)
{
	g->plyr->move[0] = 0;
	g->plyr->move[1] = 0;
	g->plyr->move[2] = 0;
	g->plyr->move[3] = 0;
	g->plyr->move[4] = 0;
	g->plyr->move[5] = 0;
	g->plyr->interact = 0;
	g->plyr->take_pic[0] = 0;
	g->plyr->take_pic[1] = 0;
	g->plyr->take_pic[2] = 0;
	set_coordf(0, 0, &(g->plyr->crd));
	set_coordf(0, 0, &(g->plyr->view));
}

int	init_player(t_game *g)
{
	g->plyr = malloc(sizeof(t_player));
	init_moves(g);
	while (g->map->m[(int) g->plyr->crd.y])
	{
		g->plyr->crd.x = 0;
		while (g->map->m[(int) g->plyr->crd.y][(int) g->plyr->crd.x])
		{
			if (g->map->m[(int) g->plyr->crd.y][(int) g->plyr->crd.x] == 'N')
				set_coordf(0, -1, &g->plyr->view);
			if (g->map->m[(int) g->plyr->crd.y][(int) g->plyr->crd.x] == 'E')
				set_coordf(1, 0, &g->plyr->view);
			if (g->map->m[(int) g->plyr->crd.y][(int) g->plyr->crd.x] == 'S')
				set_coordf(0, 1, &g->plyr->view);
			if (g->map->m[(int) g->plyr->crd.y][(int) g->plyr->crd.x] == 'W')
				set_coordf(-1, 0, &g->plyr->view);
			if (g->plyr->view.x != 0 || g->plyr->view.y != 0)
				return (set_coordf(0.5 + g->plyr->crd.x, 0.5 + g->plyr->crd.y, \
				&(g->plyr->crd)), 1);
			g->plyr->crd.x++;
		}
		g->plyr->crd.y++;
	}
	return (0);
}
