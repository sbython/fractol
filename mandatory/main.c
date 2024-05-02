/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:31:22 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 09:01:26 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    if(ac  ==  2 && !ft_strcmp("mandelbrot", av[1], 9))
    {
        mandelbrot();
    }
    else if (ac  ==  4 && !ft_strcmp("julia", av[1], 6))
    {
        if (is_valid(av[2]) && is_valid(av[3]))
            julia(av[2], av[3]);
        else
            ft_putstr("real or i is not valid\n",2);
    }
    else
    {
        ft_putstr("error input:\n\
        for mandelbrot: ./fractal mandelbrot \n\
        for julia : ./fractal julia <real> <i>\n", 2);
    }
}
