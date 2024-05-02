/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:31:22 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 10:05:15 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(int ac, char **av)
{
    if(ac  ==  2 && !ft_strcmp("bonus", av[1], 6))
    {
        bonus();
    
    }
    else
    {
        ft_putstr("error input:\n\
                for mandelbrot: ./fractal_bonus bonus \n", 1);
    }
}
