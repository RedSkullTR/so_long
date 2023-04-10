/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:12:41 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/06 03:11:09 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (!(str[i] == '\0' || str[i] == '\n'))
		i++;
	if (str[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	if (str[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_save(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	i = 0;
	j = 0;
	len = ft_strlen(str) + 1;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	i++;
	new_line = malloc(sizeof(char) * (len - i));
	if (!new_line)
		return (NULL);
	while (str[i] != '\0')
		new_line[j++] = str[i++];
	new_line[j] = '\0';
	free(str);
	return (new_line);
}

char	*read_and_copy(int fd, char *str)
{
	int		i;
	char	*copy;

	copy = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!copy)
		return (NULL);
	i = 1;
	while (!find_new_line(str))
	{
		i = read(fd, copy, BUFFER_SIZE);
		if (i == 0)
			break ;
		if (i == -1)
		{
			free(copy);
			return (NULL);
		}
		copy[i] = '\0';
		str = ft_strjoin(str, copy);
	}
	free(copy);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_copy(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_line(buffer);
	buffer = get_save(buffer);
	if (!*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
