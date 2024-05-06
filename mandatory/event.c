/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 03:46:10 by msbai             #+#    #+#             */
/*   Updated: 2024/05/06 12:57:30 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	mouve(int keycode, t_win *win)
{
	if (keycode == 65362)
		win->shifty += 0.5 * win->zoom;
	else if (keycode == 65364)
		win->shifty -= 0.5 * win->zoom;
	else if (keycode == 65361)
		win->shiftx -= 0.5 * win->zoom;
	else if (keycode == 65363)
		win->shiftx += 0.5 * win->zoom;
	else if (keycode == 65451)
		win->maxiter += 10;
	else if (keycode == 65453)
		win->maxiter -= 10;
	else if (keycode == 'q' || keycode == 'Q' || keycode == 65307)
		exit_win(win);
}

int	close_window(t_win *win)
{
	exit_win(win);
	return (0);
}

void	exit_win(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_image(win->mlx, win->img);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
}
