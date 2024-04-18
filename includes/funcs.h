/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:18:06 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/04/18 16:19:32 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCS_H
# define FUNCS_H

void	init_map(t_map *map);
int		extract_path(char **dest, char *str);
int		extract_colors(char *str);

// parsing
int		parsing(int argc, char **argv, t_map *map);

// visualization
int		start_game(t_map *map);

// utils
void	handle_error(char *err_msg, int err_code, t_map *map, void *game);

#endif
