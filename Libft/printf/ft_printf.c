/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:22 by claghrab          #+#    #+#             */
/*   Updated: 2024/12/04 22:39:28 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list arg;
    t_op    opr[10];
    int     i;
    int     written;
    int     count;

    if (!format)
        return (-1);
    i = 0;
    written = 0;
    op(&opr);
    va_start(arg, format);
    while (format[i])
    {
        if (format[i] == '%')
            count = which_opr(opr, format[++i], arg);
        else
            count = write(1, &format[i], 1);
        if (count == -1)
            return(va_end(arg), -1);
        written += count;
        i++;
    }
    return (va_end(arg), written);
}
