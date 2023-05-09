/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeroglu <aeroglu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:39:45 by aeroglu           #+#    #+#             */
/*   Updated: 2023/05/09 02:29:55 by aeroglu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./get_next_line/get_next_line.h"

# include "./mlx/mlx.h"
# include "./ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# define MAP_CHAR "01ECP"

typedef struct s_arg
{
	char	**map;
	char	**cpy_map;
	void	*mlx;
	void	*mlx_win;
	void	*img_back;
	void	*img_wall;
	void	*img_hamb;
	void	*img_ply;
	void	*img_exit;
	int		width;
	int		high;
	int		line_count;
	int		p_count;
	int		c_count;
	int		collect;
	int		e_count;
	int		exit_count;
	int		player_x;
	int		player_y;
	int		map_exit_control;
	int		map_total_byte;
	int		x;
	int		y;
}			t_arg;

int		ber_check(char *str);
int		valid_map(t_arg *arg);
int		ft_exit(t_arg *arg);
int		numb_of_element(t_arg *arg);
int		map_element_check(t_arg *arg);
int		rectangle_check(t_arg *arg);
int		wall_check(t_arg *arg);
int		map_check(t_arg *arg, char *str);
int		xpm_creator(t_arg *arg);
int		put_map(t_arg *arg);
int		ft_action(int key, t_arg *arg);
int		ft_intlen(int n);
int		map_init(t_arg *arg, char *str);
int		try_open(char *str);
void	exit_controlll(t_arg *data);
void	collectible_control(t_arg *data);
void	control_line(t_arg *arg);
void	count_collect(t_arg *data);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t size, size_t count);
void	ft_bzero(void *s, size_t n);
void	invalid_valid_map_error(void);
char	*ft_strchr(const char *s, int c);
char	*ft_itoa(int n);
void	set_player_img(int key, int *x, int *y, t_arg *arg);
void	ft_map_mani(t_arg *arg, int x, int y, int key);
void	ft_put(t_arg *arg, void *img, int x, int y);
void	line_len(t_arg *arg, char *str);
void	read_map(t_arg *arg, char *str);
void	point_change(char **map);
void	change_map(t_arg *arg, int x, int y);
void	free_map(t_arg *arg);
void	add(t_arg *arg, int x, int y);
void	numb_of_element_check(t_arg *arg);
int		control_path(t_arg *data);

#endif
