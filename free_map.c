/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:11:36 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/11 00:17:22 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->line_count)
	{
		free(arg->map[i]);
		i++;
	}
	free(arg->map);
}

int	ft_exit(t_arg *arg)
{
	mlx_clear_window(arg->mlx, arg->mlx_win);
	mlx_destroy_image(arg->mlx, arg->img_back);
	mlx_destroy_image(arg->mlx, arg->img_wall);
	mlx_destroy_image(arg->mlx, arg->img_ply);
	mlx_destroy_image(arg->mlx, arg->img_hamb);
	free_map(arg);
	ft_printf("WON!!");
	exit(0);
	return (0);
}
