/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:15:40 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/08 21:20:23 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	try_open(t_arg *arg, char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("File Couldn't Open");
		ft_exit(arg);
		return (-1);
	}
	return (fd);
}
