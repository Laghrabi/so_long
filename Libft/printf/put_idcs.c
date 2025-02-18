/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_idcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:25:02 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/18 16:02:45 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_len(str)));
}

int	mod(va_list arg)
{
	(void)arg;
	return (write(1, "%", 1));
}

int	ft_putnbr(va_list arg)
{
	char	*ascii;
	int		written;

	ascii = ft_intoa(va_arg(arg, int));
	written = write(1, ascii, ft_len(ascii));
	if (ascii)
		free(ascii);
	return (written);
}

int	ft_putchar(va_list arg)
{
	char	c;

	c = va_arg(arg, int);
	return (write(1, &c, 1));
}
