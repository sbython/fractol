/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:31:22 by msbai             #+#    #+#             */
/*   Updated: 2024/04/24 01:56:47 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    if(ac  ==  2 && !ft_strcmp("mandelbrot", av[1], 9))
    {
        mandelbrot();//TODO
    }
    else if (ac  ==  4 && !ft_strcmp("julia", av[1], 6))
    {
        julia(av[2], av[3]);//TODO
    }
    else
    {
        ft_putstr("error input:\n\
        for mandelbrot: ./fractal mandelbrot \n\
        for julia : ./fractal julia <real> <i>\n", 1);
    }
}
