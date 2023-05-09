/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:59:41 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/09 03:01:02 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpy_make_map(t_arg *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	data->cpy_map = ft_calloc(sizeof(char *), data->high + 1);
	i = -1;
	while (++i < data->high)
		data->cpy_map[i] = ft_calloc(sizeof(char), data->width + 1);
	while (y < data->high)
	{
		x = 0;
		while (x < data->width)
		{
			data->cpy_map[y][x] = data->map[y][x];
			x++;
		}
		y++;
	}
	count_collect(data);
	data->collect = data->c_count;
}

void	valid_map_punctuation(t_arg *data, int x, int y)
{
	char	*point;

	point = &data->cpy_map[y][x];
	if (*point == 'E')
		data->map_exit_control = 1;
	if (*point != '1' && *point != 'E')
	{
		if (*point == 'C')
			data->collect--;
		*point = '.';
		if (data->cpy_map[y][x + 1] != '1'
		&& data->cpy_map[y][x + 1] != '.')
			valid_map_punctuation(data, x + 1, y);
		if (data->cpy_map[y][x - 1] != '1'
		&& data->cpy_map[y][x - 1] != '.')
			valid_map_punctuation(data, x - 1, y);
		if (data->cpy_map[y + 1][x] != '1'
		&& data->cpy_map[y + 1][x] != '.')
			valid_map_punctuation(data, x, y + 1);
		if (data->cpy_map[y - 1][x] != '1'
		&& data->cpy_map[y - 1][x] != '.')
			valid_map_punctuation(data, x, y - 1);
	}
}

void	collectible_control(t_arg *data)
{
	int	i;

	i = 0;
	if (data->collect != 0)
	{
		while (i < data->high)
		{
			free(data->cpy_map[i]);
			i++;
		}
		invalid_valid_map_error();
	}
}

void	exit_controlll(t_arg *data)
{
	int	i;

	i = 0;
	if (data->map_exit_control == 0)
	{
		while (i < data->high)
		{
			free(data->cpy_map[i]);
			i++;
		}
		invalid_valid_map_error();
	}
}

int	control_path(t_arg *data)
{
	int	result;
	int	i;

	i = 0;
	cpy_make_map(data);
	valid_map_punctuation(data, data->player_x, data->player_y);
	collectible_control(data);
	exit_controlll(data);
	while (i < data->high)
	{
		free(data->cpy_map[i]);
		i++;
	}
	free(data->cpy_map);
	result = 0;
	return (result);
}
