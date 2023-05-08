/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:53:10 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/08 21:20:02 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_wh(t_arg *arg)
{
	int	i;

	i = 0;
	control_line(arg);
	while (arg->map[0][i] != '\n')
	{
		i++;
	}
	arg->width = i;
}

void	count_collect(t_arg *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
				data->c_count++;
			j++;
		}
		i++;
	}
}

void	control_line(t_arg *arg)
{
	if (arg->map_total_byte <= 0 || arg->line_count <= 0)
	{
		perror("Map Read Error");
		exit(0);
	}
}

void	line_len(t_arg *arg, char *str)
{
	int		fd;
	int		len;
	char	c;

	fd = try_open(arg, str);
	len = 0;
	arg->map_total_byte = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (c == '\n')
			len++;
		arg->map_total_byte++;
	}
	close(fd);
	len++;
	arg->map = malloc(sizeof(char *) * len + 1);
	if (!arg->map)
		return ;
	arg->map[len + 1] = NULL;
	arg->line_count = len;
	arg->high = len;
}

void	read_map(t_arg *arg, char *str)
{
	int	fd;
	int	i;

	line_len(arg, str);
	if (arg-> line_count <= 0 || !(arg->map))
	{
		arg->map = NULL;
		return ;
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(arg->map);
		return ;
	}
	i = 0;
	arg->map[i] = get_next_line(fd);
	while (arg->map[i])
	{
		i++;
		arg->map[i] = get_next_line(fd);
	}
	map_wh(arg);
	close(fd);
}
