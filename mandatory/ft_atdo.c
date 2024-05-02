/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atdo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 09:53:44 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 15:56:28 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

int is_valid(char *av)
{
    size_t i=0;
    int f = 0;
    if (av[i]== '+'||av[i]== '-')
        av++;
  while(av[i] && (ft_isdigit(av[i]) || (av[i] == '.' && i != 0 && av[i+1])))
    {
        if (av[i]== '.')
            f++;
        if(f == 2 )
            return (0);
        i++;
    }

    return (ft_strlen(av) == i && i != 0);
}
double cal(int i, double nb,char *str, int f)
{
    double expe;
    
    expe = 10;
    while(str[i] && str[i] != '.')
        nb = nb * 10 + str[i++] - '0';
    if (str[i] == '.')
      i++;
    while(str[i])
    {
        nb = nb  + (double)(str[i++] - '0')/ (double)(expe);
        expe *= 10;
    }
    if (((-2.0 > nb || nb > 2.0) && f) || ((-1.5 > nb || nb > 1.5) && !f))
    {
        ft_putstr("maybe warning input\ni => [-1.5, 1.5]\nreal => [-2, 2]\n", 2);
        // exit(1);
    }
    return (nb);
}

double atlb(char *str, int f)
{
    double nb;
    int i;
    double sing;
    
    i = 0;
    sing = 1;
    nb = 0;
    if(str[i] == '-'|| str[i] == '+')
    {
        if(str[i] == '-')
            sing = -1;
        i++;
    }
    nb = cal(i, nb,str, f);
    return (sing * nb);
}
