/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:47:26 by evan-ite          #+#    #+#             */
/*   Updated: 2024/05/21 14:05:41 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while(i < 4)
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
	while(++ctr < 4)
	{
		mlx_destroy_image(g->win->mlx, g->texts[ctr]->mlx_img);
		free(g->texts[ctr]);
	}
	mlx_destroy_image(g->win->mlx, g->dlsr->mlx_img);
	free(g->dlsr);
	mlx_destroy_image(g->win->mlx, g->frame->mlx_img);
	free(g->frame);

}
