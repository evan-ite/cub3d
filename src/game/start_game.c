/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:58:49 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/08 17:30:43 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	next_frame(t_game *game)
{
	void*	win;
	void*	mlx;

	win = game->win->win;
	mlx = game->win->mlx;
	move(game);
	draw_frame(game);
	mlx_put_image_to_window(mlx, win, game->frame->mlx_img, 0, 0);
	// mini_map(game);
	game->tick++;
	return (0);
}

static int	on_end(t_game *g)
{
	// free_game(g);
	(void) g;
	exit(0);
}

int	start_game(t_game *game)
{
	void*	win;
	void*	mlx;

	game->tick = 0;
	win = game->win->win;
	mlx = game->win->mlx;
	init_player(game);
	init_textures(game);
	init_frame(game);
	mlx_mouse_hide(mlx, win);
	mlx_mouse_move(mlx, win, WIDTH/2, HEIGHT/2);
	mlx_hook(win, KeyPress, KeyPressMask, &key_on, game);
	mlx_hook(win, KeyRelease, KeyReleaseMask, &key_off, game);
	mlx_hook(win, MotionNotify, PointerMotionMask, &mouse_move, game);
	mlx_hook(win, DestroyNotify, StructureNotifyMask, &on_end, game);
	mlx_loop_hook(mlx, next_frame, game);
	mlx_loop(mlx);
	return (1);
}


// #include <X11/X.h>

// int	handle_keypress(int keysym, t_data *data)
// {
//     if (keysym == XK_Escape)
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);

//     printf("Keypress: %d\n", keysym);
//     return (0);
// }

// int	handle_keyrelease(int keysym, void *data)
// {
//     printf("Keyrelease: %d\n", keysym);
//     return (0);
// }

// int	main(void)
// {
//     t_data	data;

//     data.mlx_ptr = mlx_init();
//     if (data.mlx_ptr == NULL)
//         return (MLX_ERROR);
//     data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
//     if (data.win_ptr == NULL)
//     {
//         free(data.win_ptr);
//         return (MLX_ERROR);
//     }

//     /* Setup hooks */
//     mlx_loop_hook(data.mlx_ptr, &handle_no_event, &data);
//     mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); /* ADDED */
//     mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data); /* CHANGED */

//     mlx_loop(data.mlx_ptr);

//     /* we will exit the loop if there's no window left, and execute this code */
//     mlx_destroy_display(data.mlx_ptr);
//     free(data.mlx_ptr);
// }
