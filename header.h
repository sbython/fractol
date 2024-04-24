/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:14:40 by msbai             #+#    #+#             */
/*   Updated: 2024/04/24 03:28:07 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_h
# define HEADER_h

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
# define WIDTH 800
# define HIEGHT 800

typedef struct l_comp
{
    double r;
    double i;
}t_comp;

typedef struct l_control
{
    double zoom;
    double min;
    double max;
    int     maxiter;
} control;

typedef struct l_win
{
    void    *mlx;
    void    *win;
    void    *img;
    char    *imgaddr;
    int     len;
    int     poit;
    int     endian;
}t_win;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;
// tools
int ft_strcmp(char *str, char *str1, int len);
int ft_putstr(char *str , int fd);
double map (double min, double max, double maxwh, double p, control con);
t_comp sumcop(t_comp z,  t_comp c);
t_comp power2(t_comp z);
void	put_c_img(t_win *data, int x, int y, int color);
int	key_hook(int keycode, t_win *win);
//mandelbrot
void mandelbrot(void);

//julia
void julia(char * r, char * i);
#endif