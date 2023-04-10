/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:42:23 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/06 03:08:03 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put(t_arg *arg, void *img, int x, int y)
{
	mlx_put_image_to_window(arg->mlx, arg->mlx_win, img, \
	64 * x, 64 * y);
}

int	put_map(t_arg *arg)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (arg->map[y][x])
	{
		if (arg->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		ft_put(arg, arg->img_back, x, y);
		if (arg->map[y][x] == 'P')
			ft_put(arg, arg->img_ply, arg->player_x, arg->player_y);
		if (arg->map[y][x] == '1')
			ft_put(arg, arg->img_wall, x, y);
		if (arg->map[y][x] == 'C')
			ft_put(arg, arg->img_hamb, x, y);
		if (arg->map[y][x] == 'E')
			ft_put(arg, arg->img_exit, x, y);
		x++;
	}
	return (0);
}
