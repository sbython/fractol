/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:08:47 by msbai             #+#    #+#             */
/*   Updated: 2024/05/02 10:02:32 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int ft_strcmp(char *s1, char *s2, int len)
{
    int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
size_t ft_strlen(char * str)
{
    size_t i;
    
    i = 0;
    while (str[i])
        i++;
    return (i);
}
int ft_putstr(char *str , int fd)
{
    write(fd, str, ft_strlen(str));
    return ft_strlen(str);
}
double map (double min, double max, double maxwh, double p)
{
    return (((p* (max - min)) / maxwh )+ min );
}

void	put_c_img(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->imgaddr + (y * data->len + x * (data->poit / 8));
	*(unsigned int*)dst = color << 8 & 0x00FFFF;
}   