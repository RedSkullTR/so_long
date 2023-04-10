/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:33:48 by aeroglu           #+#    #+#             */
/*   Updated: 2022/07/29 04:07:57 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	format(char c, va_list arg);
int	ft_printf(const char *str, ...);
int	ft_putnbr(int n);
int	ft_printpointer(unsigned long int n);
int	ft_printunbr(unsigned int n);
int	ft_printx(unsigned int n, char c);

#endif
