/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:06:12 by aeroglu           #+#    #+#             */
/*   Updated: 2022/07/29 04:32:58 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = ft_nlen(n);
	nb = n;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	str[len--] = '\0';
	while (nb)
	{
		str[len--] = nb % 10 + 48;
		nb /= 10;
	}
	ft_putstr(str);
	free(str);
	return (ft_nlen(n));
}

int	ft_printunbr(unsigned int n)
{
	int	pnum;

	pnum = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (n >= 10)
		pnum += ft_printunbr(n / 10);
	pnum += ft_putchar("0123456789"[n % 10]);
	return (pnum);
}
