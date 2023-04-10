/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 04:02:55 by aeroglu           #+#    #+#             */
/*   Updated: 2022/07/29 04:34:34 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printx(unsigned int n, char c)
{
	int	pnum;

	pnum = 0;
	if (n == 0)
	{
		ft_putstr("0");
		return (1);
	}
	if (n >= 16)
		pnum += ft_printx(n / 16, c);
	if (c == 'x')
		pnum += ft_putchar("0123456789abcdef"[n % 16]);
	else
		pnum += ft_putchar("0123456789ABCDEF"[n % 16]);
	return (pnum);
}
