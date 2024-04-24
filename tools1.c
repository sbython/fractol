/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msbai <msbai@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 02:53:35 by msbai             #+#    #+#             */
/*   Updated: 2024/04/24 08:19:26 by msbai            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_comp sumcop(t_comp z,  t_comp c)
{
    t_comp r;

    r.i = z.i + c.i;
    r.r = z.r + c.r;
    return (r);
}
t_comp power2(t_comp z)
{
    t_comp r;

    r.i = 2 * z.i * z.r;
    r.r =  z.r * z.r - z.i * z.i;
    return (r);
}
int	key_hook(int keycode, t_win *win)
{
    (void) win;
    return keycode;
}