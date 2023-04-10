/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:18:32 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/09 06:16:23 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_element_check(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x] != '\0' && arg->map[y][x] != '\n')
		{
			if (ft_strchr(MAP_CHAR, arg->map[y][x]))
				x++;
			else
			{
				ft_printf("%c ->", arg->map[y][x]);
				perror(" invalid character!!\n");
				return (1);
			}
		}
		y++;
	}
	return (0);
}

int	rectangle_check(t_arg *arg)
{
	int	len;
	int	x;
	int	y;

	len = ft_strlen(arg->map[0]);
	y = 0;
	while (y < arg->line_count)
	{
		x = 0;
		while (arg->map[y] && arg->map[y][x] != '\n' \
			&& x < (int)(ft_strlen(arg->map[y])))
			x++;
		if (x != len - 1)
		{
			ft_printf("%dth line:", y + 1);
			perror("Rectangle error\n");
			return (1);
		}
		y++;
	}
	return (0);
}

int	wall_check(t_arg *arg)
{
	int	x;
	int	y;

	y = 0;
	while (arg->map[y])
	{
		x = 0;
		while (arg->map[y][x] && arg->map[y][x] != '\n')
		{
			if (((y == 0 || y == arg->line_count - 1) || (x == 0
						|| (size_t)x == ft_strlen(arg->map[y]) - 2))
				&& arg->map[y][x] != '1')
			{
				ft_printf("%dth line %dth character => %c ", y + 1, x + 1, \
						arg->map[y][x]);
				perror("WALL ERROR!!\n");
				return (1);
			}
			else
				x++;
		}
		y++;
	}
	return (0);
}

int	map_check(t_arg *arg, char *str)
{
	int	i;

	i = 0;
	read_map(arg, str);
	if (!(arg->map))
	{
		perror("file could not be read!!\n");
		return (1);
	}
	if (rectangle_check(arg) || map_element_check(arg)
		|| numb_of_element(arg) || wall_check(arg) || valid_map(arg))
	{
		free_map(arg);
		return (1);
	}
	free_map(arg);
	return (0);
}
