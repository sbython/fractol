/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:43:14 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 10:05:24 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int calculette( t_comp c, int iter, t_comp z)
{
    int i;
    i = 0;

    while ((z.i * z.i + z.r * z.r <= 4) && i < iter)
    {
        z = sumcop(power2(z),c);
        i++;
    }
        
    return (i);
}
void draw_fractal(t_win *win)
{
    t_comp com;
    int     i;
    t_comp c;
    int j;
    com.i = -1;
    win->img = mlx_new_image(win->mlx, WIDTH, HIEGHT);
    win->imgaddr = mlx_get_data_addr(win->img, &win->poit, &win->len,
								&win->endian);
    j = map(0 , (double)0xFFF000, win->maxiter,2) -  map(0 , (double)0xFFF000, win->maxiter,1); 
    while (com.i++ < HIEGHT)
    {
       com.r = -1;
        while (com.r++ < WIDTH)
        {
            c.i = map(win->miny , win->maxy, HIEGHT,com.i) * win->zoom + win->shifty;
            c.r = map(win->minx , win->maxx, WIDTH,com.r) * win->zoom + win->shiftx;
            i  = calculette( c, win->maxiter, win->z);
            if(i != win->maxiter )
                put_c_img(win, com.r, com.i, i * j);
        }
    }
    mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
}

void bonus(void)
{
    t_win win;
    // t_comp z;
    initwin(&win, "Mandelbrot");
    win.name = 0;
    draw_fractal(&win);
    mlx_mouse_hook(win.win, mouse_hook, &win);
    mlx_key_hook(win.win, key_hook, &win);
    mlx_hook(win.win, 17, 0, close_window, &win);
    mlx_loop(win.mlx);
}
