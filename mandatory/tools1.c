/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:53:35 by msbai             #+#    #+#             */
/*   Updated: 2024/05/06 21:30:56 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_comp	sumcop(t_comp z, t_comp c)
{
	t_comp	r;

	r.i = z.i + c.i;
	r.r = z.r + c.r;
	return (r);
}

t_comp	power2(t_comp z)
{
	t_comp	r;

	r.i = 2 * z.i * z.r;
	r.r = z.r * z.r - z.i * z.i;
	return (r);
}

int	mouse_hook(int keycode, int x, int y, t_win *win)
{
	if ((keycode == 5) || (keycode == 4))
	{
		win->y = (map(win->miny, win->maxy, HIEGHT, y) * win->zoom
				+ win->shifty);
		win->x = (map(win->minx, win->maxx, WIDTH, x) * win->zoom
				+ win->shiftx);
		zoom(keycode, win);
		win->shifty += win->y - (map(win->miny, win->maxy, HIEGHT, y)
				* win->zoom + win->shifty);
		win->shiftx += win->x - (map(win->minx, win->maxx, WIDTH, x) * win->zoom
				+ win->shiftx);
		mlx_destroy_image(win->mlx, win->img);
		if (win->name == 0)
			draw_fractal(win);
		else if (win->name == 1)
			draw_julai(win);
	}
	return (0);
}

int	key_hook(int keycode, t_win *win)
{
	mouve(keycode, win);
	mlx_destroy_image(win->mlx, win->img);
	if (win->name == 0)
		draw_fractal(win);
	else if (win->name == 1)
		draw_julai(win);
	return (0);
}

void	initwin(t_win *win, char *name)
{
	win->minx = -2;
	win->maxx = 2;
	win->miny = 2;
	win->maxy = -2;
	win->maxiter = 100;
	win->zoom = 1;
	win->shifty = 0;
	win->shiftx = 0;
	win->y = 0;
	win->x = 0;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, WIDTH, HIEGHT, name);
	win->z.i = 0;
	win->z.r = 0;
}
