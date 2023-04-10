/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:19:59 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/04 06:03:57 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_arg		arg;

	if (ac == 2)
	{
		if (ber_check(av[1]) || map_check(&arg, av[1]))
			return (1);
		if (map_init(&arg, av[1]))
			return (1);
	}
	else
	{
		perror("ERROR: missing arg!!!\n");
		return (1);
	}
	return (0);
}
