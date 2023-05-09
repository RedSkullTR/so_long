/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:40 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/09 02:34:43 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	try_open(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("File Couldn't Open");
		exit(1);
		return (-1);
	}
	return (fd);
}
