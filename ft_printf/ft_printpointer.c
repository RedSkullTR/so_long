/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 01:36:56 by aeroglu           #+#    #+#             */
/*   Updated: 2022/07/29 04:16:23 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long int n)
{
	int	pnum;

	pnum = 0;
	if (n >= 16)
		pnum += ft_printpointer(n / 16);
	pnum += ft_putchar("0123456789abcdef"[n % 16]);
	return (pnum);
}
