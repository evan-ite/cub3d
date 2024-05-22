/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:58 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/22 10:47:58 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static t_img	*init_img(char *path, t_game *g)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		handle_error(ERR_MEM, 127, g->map, g); //which error code?
	img->mlx_img = mlx_xpm_file_to_image(g->win->mlx, path, &(img->x), &(img->y));
	img->addr = mlx_get_data_addr(img->mlx_img, &(img->bpp), &(img->len), &(img->endian));
	return (img);
}

int	init_textures(t_game *g)
{
	int		ctr;

	ctr = -1;
	g->map->text_files[4] = DOOR1;
	g->map->text_files[5] = DOOR2;
	g->map->text_files[6] = DOOR3;
	while (++ctr < 7)
		g->texts[ctr] = init_img(g->map->text_files[ctr], g);
	reverse_texture(g->texts[0]);
	reverse_texture(g->texts[3]);
	g->dlsr = init_img(DSLR, g);
	g->hint = init_img(HINT, g);
	if (g->map->n_kim > 0)
		g->sm.img = init_img(KIM, g);
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
