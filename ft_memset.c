/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:24:51 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/07 15:25:15 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*wq;
	size_t			dll;

	dll = 0;
	wq = (unsigned char *)b;
	while (dll < len)
	{
		wq[dll++] = c;
	}
	return (wq);
}
