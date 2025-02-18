/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:39:36 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/18 14:43:19 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct t_op
{
	char		format;
	int			(*f)(va_list);
}	t_op;

int		count(int n);
int		mod(va_list arg);
char	*ft_intoa(int n);
int		ft_printf(const char *format, ...);
char	*ft_dup(const char *str);
void	op(t_op (*arr)[10]);
int		ft_putnbr(va_list arg);
int		put_x_lower(va_list arg);
int		put_x_upper(va_list arg);
int		put_p(va_list arg);
int		put_u(va_list arg);
int		print_reverse(char *str, int i);
int		ft_putstr(va_list arg);
int		ft_putchar(va_list arg);
size_t	ft_len(const char *str);
int		which_opr(t_op arr[10], char format, va_list arg);

#endif
