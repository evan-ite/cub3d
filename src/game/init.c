/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:00:58 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/24 16:03:54 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// char * mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
int	init_textures(t_game *g)
{
	void	*ptr;
	int		x;
	int		y;
	int		ctr;

	x = TEX_X;
	y = TEX_Y;
	ctr = -1;
	while (++ctr < 4)
	{
		ptr = mlx_xpm_file_to_image(g->win->mlx, g->map->text_files[ctr], &x, &y);
		g->texts[ctr] = malloc(sizeof(t_img));
		g->texts[ctr]->addr = mlx_get_data_addr(ptr, &(g->texts[ctr]->bpp), &(g->texts[ctr]->len), &(g->texts[ctr]->endian));
		free(ptr);
	}
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
	ft_memset(f->addr, 0, (f->len * HEIGHT));
	fill_bg(f, g->map->c, g->map->f);
	g->frame = f;
	return (1); // meaningfull error handling tbi
}
