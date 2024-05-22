/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:47:26 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/22 17:10:09 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->text_files[i])
		{
			free(map->text_files[i]);
			map->text_files[i] = NULL;
		}
		i++;
	}
	if (map->m)
		free_array((void **)map->m, -1);
	ft_close(&map->fd);
}

void	free_game(t_game *g)
{
	if (g->map)
		free_map(g->map);
}

void	free_images(t_game *g)
{
	int	ctr;

	ctr = -1;
	while (++ctr < 7)
	{
		mlx_destroy_image(g->win->mlx, g->texts[ctr]->mlx_img);
		free(g->texts[ctr]);
	}
	if (g->map->n_kim > 0)
	{
		ctr = -1;
		while (++ctr < 5)
		{
			mlx_destroy_image(g->win->mlx, g->sm.flash[ctr]->mlx_img);
			free(g->sm.flash[ctr]);
		}
		mlx_destroy_image(g->win->mlx, g->sm.img->mlx_img);
		free(g->sm.img);
	}
	mlx_destroy_image(g->win->mlx, g->cam_overlay->mlx_img);
	free(g->cam_overlay);
	mlx_destroy_image(g->win->mlx, g->hint->mlx_img);
	free(g->hint);
	mlx_destroy_image(g->win->mlx, g->frame->mlx_img);
	free(g->frame);
}
