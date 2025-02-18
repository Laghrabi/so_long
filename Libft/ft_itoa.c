/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claghrab <claghrab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:59:39 by claghrab          #+#    #+#             */
/*   Updated: 2025/02/11 18:46:06 by claghrab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = count(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[len] = '\0';
	len--;
	while (n)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa_buff(char *buff, int n)
{
	unsigned int	m;
	int				i;

	i = 0;
	if (n == 0)
	{
		ft_strlcpy(buff, "0", 2);
		return (buff);
	}
	if (n < 0)
	{
		buff[i++] = '-';
		n = (unsigned int)-n;
	}
	m = 1;
	while (n / m >= 10)
		m *= 10;
	while (m >= 1)
	{
		buff[i++] = ((n / m) % 10) + '0';
		m /= 10;
	}
	buff[i] = '\0';
	return (buff);
}
