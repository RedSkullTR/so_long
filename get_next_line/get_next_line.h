/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:58:06 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/04 06:11:46 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *first_part, char *to_be_added);
size_t	ft_strlen(char *s);
int		find_new_line(char *str);
char	*get_line(char *str);
char	*get_save(char *str);
char	*read_and_copy(int fd, char *str);
char	*get_next_line(int fd);

#endif
