/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:51:00 by evan-ite          #+#    #+#             */
/*   Updated: 2024/04/18 12:56:37 by evan-ite         ###   ########.fr       */
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

void	free_game(t_game *game)
{
	if (game->map)
		free_map(game->map);
	// mlx_destroy_image(game->win->mlx, game->texts[0]->mlx_img);
	// mlx_destroy_image(game->win->mlx, game->texts[2]->mlx_img);
	// mlx_destroy_image(game->win->mlx, game->texts[1]->mlx_img);
	// mlx_destroy_image(game->win->mlx, game->texts[3]->mlx_img);
	// free(game);
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

int	on_end(t_game *g)
{
	free_game(g);
	free_images(g);
	mlx_destroy_window(g->win->mlx, g->win->win);
	mlx_destroy_display(g->win->mlx);
	free(g->player);
	free(g->win->mlx);
	exit(0);
}

void	handle_error(char *err_msg, int err_code, t_map *map, void *game)
{
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	if (map)
		free_map(map);
	if (game)
		free_game(game);
	exit(err_code);
}
