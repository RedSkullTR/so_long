/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 15:25:40 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/09 02:52:55 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_calloc(size_t size, size_t count)
{
	void	*num;

	num = malloc(count * size);
	if (!num)
		return (num);
	ft_bzero(num, size * count);
	return (num);
}
