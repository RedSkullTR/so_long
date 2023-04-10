/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 03:19:39 by aeroglu           #+#    #+#             */
/*   Updated: 2023/04/11 02:40:15 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	xpm_creator(t_arg *arg)
{
	int	x;
	int	y;

	arg->img_back = mlx_xpm_file_to_image(arg->mlx, "./img/ground.xpm", &x, &y);
	arg->img_hamb = mlx_xpm_file_to_image(arg->mlx, "./img/hamb.xpm", &x, &y);
	arg->img_exit = mlx_xpm_file_to_image(arg->mlx, "./img/door.xpm", &x, &y);
	arg->img_wall = mlx_xpm_file_to_image(arg->mlx, "./img/wall.xpm", &x, &y);
	arg->img_ply = mlx_xpm_file_to_image(arg->mlx, "./img/pd.xpm", &x, &y);
	if (!arg->img_back || !arg->img_hamb || !arg->img_wall
		|| !arg->img_exit || !arg->img_ply)
		return (1);
	return (0);
}

void	ft_map_mani(t_arg *arg, int x, int y, int key)
{
	if (arg->map[y][x] != '1' && arg->map[y][x] != 'E' &&
		(key == 13 || key == 1 || key == 2 || key == 0))
	{
		ft_printf("Action=>%d\n", ++arg->p_count);
		if (arg->map[y][x] == 'C')
			arg->c_count--;
		arg->map[arg->player_y][arg->player_x] = '0';
		arg->map[y][x] = 'P';
		arg->player_x = x;
		arg->player_y = y;
	}
	else if (!arg->c_count && arg->map[y][x] == 'E')
	{
		ft_printf("Action=>%d\n", ++arg->p_count);
		ft_exit(arg);
	}
}

void	set_player_img(int key, int *x, int *y, t_arg *arg)
{
	int	w;
	int	h;

	if (key == 13)
	{
		*y = *y - 1;
		arg->img_ply = mlx_xpm_file_to_image(arg->mlx, "./img/pu.xpm", &w, &h);
	}
	else if (key == 1)
	{
		*y = *y + 1;
		arg->img_ply = mlx_xpm_file_to_image(arg->mlx, "./img/pd.xpm", &w, &h);
	}
	else if (key == 2)
	{
		*x = *x + 1;
		arg->img_ply = mlx_xpm_file_to_image(arg->mlx, "./img/pr.xpm", &w, &h);
	}
	else if (key == 0)
	{
		*x = *x - 1;
		arg->img_ply = mlx_xpm_file_to_image(arg->mlx, "./img/pl.xpm", &w, &h);
	}
}

int	ft_action(int key, t_arg *arg)
{
	int		x;
	int		y;
	char	*str;

	x = arg->player_x;
	y = arg->player_y;
	if (key == 53)
		ft_exit(arg);

	set_player_img(key, &x, &y, arg);
	mlx_clear_window(arg->mlx, arg->mlx_win);
	ft_map_mani(arg, x, y, key);
	put_map(arg);
	str = ft_itoa(arg->p_count);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, str);
	free(str);
	return (0);
}

int	map_init(t_arg *arg, char *str)
{
	read_map(arg, str);
	arg->p_count = 0;
	arg->mlx = mlx_init();
	arg->mlx_win = mlx_new_window(arg->mlx, 64 * (ft_strlen(arg->map[0]) - 1) \
			, 64 * arg->line_count, "SO_LONG");
	if (!arg->mlx || !arg->mlx_win || xpm_creator(arg))
	{
		perror("mlx failed!!\n");
		return (1);
	}
	put_map(arg);
	mlx_string_put(arg->mlx, arg->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(arg->mlx_win, 2, 1L << 2, ft_action, arg);
	mlx_hook(arg->mlx_win, 17, 1L << 2, ft_exit, arg);
	mlx_loop(arg->mlx);
	return (0);
}
