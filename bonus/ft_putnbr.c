/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 02:35:02 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 09:29:47 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int ft_putchr (int c)
{
    return write(1,&c,1);
}
void	ft_putnbr(int n)
{
	long nb;

    nb = n;
    if (nb < 0)
    {
        nb = -nb;
        ft_putchr('-');
    }
    if(nb > 9)
    {
       ft_putnbr(nb / 10);
       ft_putnbr(nb % 10); 
    }
    else 
        ft_putchr('0' + nb);
}
