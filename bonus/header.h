/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:14:40 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 15:10:57 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_h
# define HEADER_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>
# define WIDTH 800
# define HIEGHT 800

typedef struct s_comp
{
    double r;
    double i;
}t_comp;


typedef struct s_win
{
    int name;
    void    *mlx;
    void    *win;
    void    *img;
    char    *imgaddr;
    int     len;
    int     poit;
    int     endian;
    double zoom;
    double minx;
    double maxx;
    double miny;
    double maxy;
    double shiftx;
    double shifty;
    double x;
    double y;
    int     maxiter;
    t_comp z;
    t_comp c;
}t_win;


// tools
int ft_strcmp(char *str, char *str1, int len);
int ft_putstr(char *str , int fd);
double map (double min, double max, double maxwh, double p);
t_comp sumcop(t_comp z,  t_comp c);
t_comp power2(t_comp z);
void	put_c_img(t_win *data, int x, int y, int color);
int	mouse_hook(int keycode,int x, int y, t_win *win);
int	key_hook(int keycode, t_win *win);
void initwin(t_win *win , char *name);
int calculette( t_comp c, int iter, t_comp z);
double atlb(char *str, int i);

//event
void mouve(int keycode, t_win *win);
void exit_win(t_win *win);
int close_window(t_win *win);
//mandelbrot
void bonus(void);
void draw_fractal(t_win *win);

//libft function
int ft_putchr (int c);
void	ft_putnbr(int n);
#endif