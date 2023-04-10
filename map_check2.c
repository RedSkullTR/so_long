/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:51:04 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/09 06:42:43 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add(t_arg *arg, int x, int y)
{
	arg->player_x = x;
	arg->player_y = y;
}

void	numb_of_element_check(t_arg *arg)
{
	int	x;
	int	y;

	arg->p_count = 0;
	arg->e_count = 0;
	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x])
		{
			if (arg->map[y][x] == 'P')
			{
				add(arg, x, y);
				arg->p_count++;
			}
			if (arg->map[y][x] == 'E')
				arg->e_count++;
			x++;
		}
		y++;
	}
}

int	numb_of_element(t_arg *arg)
{
	numb_of_element_check(arg);
	printf("%d", arg->c_count);
	if (arg->p_count != 1 || arg->e_count != 1)
	{
		perror("The number of elements is wrong!!\n");
		return (1);
	}
	return (0);
}
