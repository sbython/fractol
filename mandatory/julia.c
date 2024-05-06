/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:41:50 by msbai             #+#    #+#             */
/*   Updated: 2024/05/06 21:33:58 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_comp	mapcz(t_win *win, t_comp com)
{
	t_comp	z;

	z.i = map(win->miny, win->maxy, HIEGHT, com.i) * win->zoom + win->shifty;
	z.r = map(win->minx, win->maxx, WIDTH, com.r) * win->zoom + win->shiftx;
	return (z);
}

void	zoom(int keycode, t_win *win)
{
	if (keycode == 5)
	{
		win->zoom *= 1.15;
		if (win->maxiter * 0.85 > 30)
			win->maxiter -= 1;
	}
	else if (keycode == 4)
	{
		win->zoom *= 0.85;
		win->maxiter += 1;
	}
}

void	draw_julai(t_win *win)
{
	t_comp	com;
	int		i;
	t_comp	c;
	t_comp	z;

	c = win->c;
	com.i = -1;
	win->img = mlx_new_image(win->mlx, WIDTH, HIEGHT);
	win->imgaddr = mlx_get_data_addr(win->img, &win->poit, &win->len,
			&win->endian);
	while (com.i++ < HIEGHT)
	{
		com.r = -1;
		while (com.r++ < WIDTH)
		{
			z = mapcz(win, com);
			i = calculette(c, win->maxiter, z);
			if (i != win->maxiter)
				put_c_img(win, com.r, com.i, (i * 250 << 3) + ((i * 250
							/ win->maxiter) << 5));
		}
	}
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void	julia(char *r, char *i)
{
	t_win	win;

	win.c.i = atlb(i);
	win.c.r = atlb(r);
	initwin(&win, "Julia");
	win.name = 1;
	draw_julai(&win);
	mlx_mouse_hook(win.win, mouse_hook, &win);
	mlx_key_hook(win.win, key_hook, &win);
	mlx_hook(win.win, 17, 0, close_window, &win);
	mlx_loop(win.mlx);
}
