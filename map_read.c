/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 00:53:10 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/04 01:07:17 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	line_len(t_arg *arg, char *str)
{
	int		fd;
	int		len;
	char	c;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		arg->line_count = 0;
		return ;
	}
	len = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			len++;
	}
	close(fd);
	len++;
	arg->map = malloc(sizeof(char *) * len + 1);
	if (!arg->map)
		return ;
	arg->map[len + 1] = NULL;
	arg->line_count = len;
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
	close(fd);
}
