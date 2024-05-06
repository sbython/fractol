/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:14:40 by msbai             #+#    #+#             */
/*   Updated: 2024/05/06 21:33:11 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define WIDTH 800
# define HIEGHT 800

typedef struct s_comp
{
	double	r;
	double	i;
}			t_comp;

typedef struct s_win
{
	int		name;
	void	*mlx;
	void	*win;
	void	*img;
	char	*imgaddr;
	int		len;
	int		poit;
	int		endian;
	double	zoom;
	double	minx;
	double	maxx;
	double	miny;
	double	maxy;
	double	shiftx;
	double	shifty;
	double	x;
	double	y;
	int		maxiter;
	t_comp	z;
	t_comp	c;
}			t_win;

// tools
int			ft_strcmp(char *str, char *str1, int len);
int			ft_putstr(char *str, int fd);
double		map(double min, double max, double maxwh, double p);
t_comp		sumcop(t_comp z, t_comp c);
t_comp		power2(t_comp z);
void		put_c_img(t_win *data, int x, int y, int color);
int			mouse_hook(int keycode, int x, int y, t_win *win);
int			key_hook(int keycode, t_win *win);
void		initwin(t_win *win, char *name);
int			calculette(t_comp c, int iter, t_comp z);
double		atlb(char *str);
double		cal(int i, double nb, char *str);
int			is_valid(char *av);
size_t		ft_strlen(char *str);
t_comp		mapcz(t_win *win, t_comp com);
void		zoom(int keycode, t_win *win);

//event
void		mouve(int keycode, t_win *win);
void		exit_win(t_win *win);
int			close_window(t_win *win);
//mandelbrot
void		mandelbrot(void);
void		draw_fractal(t_win *win);

//julia
void		julia(char *r, char *i);
void		draw_julai(t_win *win);
//libft function
int			ft_putchr(int c);
void		ft_putnbr(int n);
#endif