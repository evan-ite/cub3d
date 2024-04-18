/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evan-ite <evan-ite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:18:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/18 16:34:39 by evan-ite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

# include "structs.h"

void	init_map(t_map *map);
char	*extract_path(char *str);
int		extract_color(char *str);

// parsing
int		parsing(int argc, char **argv, t_map *map);

// visualization
int		start_game(t_map *map);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);

#endif
