/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:27:24 by aeroglu           #+#    #+#             */
/*   Updated: 2022/08/09 03:35:20 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *first_part, char *to_be_added)
{
	char	*arr;
	int		i;

	i = 0;
	arr = malloc(sizeof(char) * (ft_strlen(first_part)
				+ ft_strlen(to_be_added) + 1));
	if (!arr)
		return (NULL);
	while (first_part && first_part[i])
	{
		arr[i] = first_part[i];
		i++;
	}
	while (to_be_added && *to_be_added)
		arr[i++] = *to_be_added++;
	arr[i] = 0;
	free(first_part);
	return (arr);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	find_new_line(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
