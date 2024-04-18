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

void	handle_error(char *err_msg, int err_code, t_map *map, void *game)
{
	if (err_msg)
		ft_putstr_fd(err_msg, STDERR_FILENO);
	if (map)
		free(map);
	if (game)
		free(game);
	exit(err_code);
}
