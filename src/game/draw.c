/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:38:20 by jstrozyk          #+#    #+#             */
/*   Updated: 2024/05/08 17:51:09 by jstrozyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_bg(t_img *frame, int c, int f)
{
	int		ctr;
	char	*px;

	ctr = 0;
	px = frame->addr;
	while(ctr < (frame->len * HEIGHT))
	{
		if (ctr < (frame->len * HEIGHT/2))
			*(int *)(px) = c;
		else
			*(int *)(px) = f;
		px += frame->bpp/8;
		ctr += frame->bpp/8;
	}
	return (1); // meaningfull error handling tbi
}

int	draw_frame(t_game *g)
{
	t_img	*text;
	t_coord	get;
	t_coord	set;

	text = g->texts[0];
	set.x = 250;
	get.x = 0;

	while(get.x < TEX_X)
	{
		get.y = 0;
		set.y = 250;
		while(get.y < TEX_Y)
		{
			set_px(&set, get_px(&get, text, 1), g);
			get.y++;
			set.y++;

		}
		get.x++;
		set.x++;
	}
	fill_bg(g->frame, g->map->c, g->map->f);
	raycast(g);
	return (1); // meaningfull error handling tbi
}

static int	get_color(int x, int y, int dir, t_game *g)
{
	t_coord	px;

	px.x = x;
	px.y = y;
	return (get_px(&px, g->texts[dir], 0));
}

int	draw_line(int height, int col, float width_ratio, int dir, t_game *g)
{
	t_coord	px;
	t_coord	tx;
	int		ctr;
	int		color;
	float	height_ratio;

	ctr = -1;
	height_ratio = (float)TEX_Y / height;
	px.y = (HEIGHT - height) / 2;
	px.x = (int) col;
	tx.x = (int)(width_ratio * TEX_Y);
	// printf("tx x %f, height_ratio %f, heihght %d \n", tx.x, height_ratio, height);
	printf("col %d \n", col);
	while (++ctr <= height)
	{
		tx.y = (int)(ctr * height_ratio);
		tx.y = ft_clamp(tx.y, 0, TEX_Y - 1);
		tx.x = ft_clamp(tx.x, 0, TEX_Y - 1);
		color = get_color(tx.x, tx.y, dir, g);
		// printf("tx x %f, tx y %f, ctr %d, px x %f, px y %f\n", tx.x, tx.y, ctr, px.x, px.y);
		tx.x = ft_clamp(tx.x, 0, WIDTH -1);
		tx.y = ft_clamp(tx.y, 0, HEIGHT - 1);

		set_px(&px, color, g);
		px.y++;
	}
	printfd("end loop\n");
	return (1); // meaningfull error handling tbi
}
