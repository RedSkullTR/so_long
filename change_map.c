/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:59:41 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/09 06:42:27 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_control(t_arg *arg, int y, int x)
{
	if (arg->map[y + 1][x] != '.' &&
		arg->map[y + 1][x] != '1')
	{
		y++;
		if (arg->map[y][x] == 'E')
			arg->e_count++;
		if (arg->map[y][x] == 'C')
			arg->c_count++;
		arg->map[y][x] = '.';
		recursive_control(arg, y, x);
		y--;
	}
}

void	second_control(t_arg *arg, int y, int x)
{
	if (arg->map[y][x + 1] != '.' &&
		arg->map[y][x + 1] != '1')
	{
		x++;
		if (arg->map[y][x] == 'E')
			arg->e_count++;
		if (arg->map[y][x] == 'C')
			arg->c_count++;
		arg->map[y][x] = '.';
		recursive_control(arg, y, x);
		x--;
	}
}

void	third_control(t_arg *arg, int y, int x)
{
	if (arg->map[y - 1][x] != '.' &&
		arg->map[y - 1][x] != '1')
	{
		y--;
		if (arg->map[y][x] == 'E')
			arg->e_count++;
		if (arg->map[y][x] == 'C')
			arg->c_count++;
		arg->map[y][x] = '.';
		recursive_control(arg, y, x);
		y++;
	}
}

void	fourth_control(t_arg *arg, int y, int x)
{
	if (arg->map[y][x - 1] != '.' &&
		arg->map[y][x - 1] != '1')
	{
		x--;
		if (arg->map[y][x] == 'E')
			arg->e_count++;
		if (arg->map[y][x] == 'C')
			arg->c_count++;
		arg->map[y][x] = '.';
		recursive_control(arg, y, x);
		x++;
	}
}

void	recursive_control(t_arg *arg, int y, int x)
{
	start_control(arg, y, x);
	second_control(arg, y, x);
	third_control(arg, y, x);
	fourth_control(arg, y, x);
}
