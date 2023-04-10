/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:19:46 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/04 06:27:23 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	if (str[len - 4] == '.' && str[len - 3] == 'b' && str[len - 2] == 'e'
		&& str[len - 1] == 'r')
	{
		return (0);
	}
	perror("file extension should be '.ber'\n");
	return (1);
}
