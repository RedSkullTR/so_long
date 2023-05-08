/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:41:52 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/08 20:27:24 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_valid_map_error(void)
{
	ft_printf("Error\n Not a valid map!\n");
	exit(1);
}

int	valid_map(t_arg *arg)
{
	if (control_path(arg))
	{
		ft_printf("Error\n Map Not Working");
		return (1);
	}
	if (arg->c_count == 0)
	{
		perror("The number of collectible is wrong!!\n");
		return (1);
	}
	return (0);
}
