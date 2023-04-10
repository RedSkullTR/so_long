/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 16:08:08 by aeroglu           #+#    #+#             */
/*   Updated: 2022/07/29 04:36:37 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	format(char c, va_list arg)
{
	int	pnum;

	pnum = 0;
	if (c == 'c')
		pnum += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		pnum += ft_putstr(va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		pnum += ft_putnbr(va_arg(arg, int));
	else if (c == '%')
		pnum += write(1, "%", 1);
	else if (c == 'p')
	{
		pnum += ft_putstr("0x");
		pnum += ft_printpointer(va_arg(arg, unsigned long int));
	}
	else if (c == 'u')
		pnum += ft_printunbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		pnum += ft_printx(va_arg(arg, int), c);
	return (pnum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		pnum;
	va_list	arg;

	pnum = 0;
	i = 0;
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			pnum += format(str[++i], arg);
			i++;
		}
		else
			pnum += ft_putchar(str[i++]);
	}
	return (pnum);
}
