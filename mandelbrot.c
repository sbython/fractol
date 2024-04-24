/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:43:14 by msbai             #+#    #+#             */
/*   Updated: 2024/04/24 07:56:51 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int calculette( t_comp c, int iter)
{
    int i;
    t_comp z;
    i = 0;
    z.i = 0.0;
    z.r = 0.0;
    while ((z.i * z.i + z.r * z.r <= 4) && i < iter)
    {
        z = sumcop(power2(z),c);
        i++;
    }
    return (i);
}
static void draw_mand(t_win *win, control con)
{
    t_comp com;
    int     i;
    t_comp c;
   com.i = 0;
   com.r = 0;

    while (com.i < HIEGHT)
    {
       com.r = 0;
        while (com.r < WIDTH)
        {
            c.i = map(con.max , con.min, HIEGHT,com.i, con);
            c.r = map(con.min , con.max, WIDTH,com.r, con);
            i  = calculette( c, con.maxiter);
            if(i != con.maxiter)
                put_c_img(win, com.r, com.i, map (0x000000, 0xFFFFFF, con.maxiter, i, con));
                // mlx_pixel_put ( win->mlx, win->img, com.r, com.i, map (0x000000, 0xFFFFFF, con.maxiter, i, con) );
           com.r++;
        }
       com.i++;
    }
    
}
void mandelbrot(void)
{
    t_win win;
    control con;
    t_vars vars;
    
    con.min = -2;
    con.max = 2;
    con.maxiter = 200;
    con.zoom = 1;
    win.mlx = mlx_init();
    win.win = mlx_new_window(win.mlx, WIDTH, HIEGHT, "mandelbrot");
    win.img = mlx_new_image(win.mlx, WIDTH, HIEGHT);
    win.imgaddr = mlx_get_data_addr(win.img, &win.poit, &win.len,
								&win.endian);
    draw_mand(&win, con);//TODO
    // printf("%d", win.endian);
    mlx_put_image_to_window(win.mlx, win.win, win.img, 0, 0);
    vars.mlx = win.mlx;
    vars.win = win.win;
    mlx_key_hook(win.win, key_hook, &win);
    mlx_loop(win.mlx);
}
