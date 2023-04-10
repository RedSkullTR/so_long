/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 02:41:52 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/10 20:54:36 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collectable_control(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'C' && arg->map[i][j] != '.')
			{
				ft_printf("Unreachable coin. Coordinate : y = %d, \
                    x = %d", i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	unreachable_exit_control(t_arg *arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg->map[i])
	{
		j = 0;
		while (arg->map[i][j])
		{
			if (arg->map[i][j] == 'E' && arg->map[i][j] != '.')
			{
				ft_printf("Unreachable exit. Coordinate : y = %d, \
                    x = %d", i, j);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	valid_map(t_arg *arg)
{
	recursive_control(arg, arg->player_y, arg->player_x);
	printf("\n%d\n", arg->c_count);
	collectable_control(arg);
	unreachable_exit_control(arg);
	if (arg->c_count == 0)
	{
		perror("The number of collectible is wrong!!\n");
		return (1);
	}
	return (0);
}
