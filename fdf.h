/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:08:48 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/08 16:08:50 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "get_next_line/get_next_line.h"

# define HORIZON 1600
# define VERTICAL 900
# define ESC 53
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ZOOM 10
# define ZOOMIN 5
# define ZOOMOUT 4
# define PLUS 24
# define MINUS 27
# define TRAN 20

typedef struct s_img
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits;
	int		line;
	int		endian;
}	t_img;

typedef struct s_list
{
	double	**point;
	int		y;
	int		x;
	int		sum;
	int		dis_y;
	int		dis_x;
	int		start_y;
	int		start_x;
	double	ang_x;
	double	ang_y;
	double	ang_z;
	t_img	*img;
}	t_list;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

int			ft_strlen(char *s);
void		ft_init_lst(t_list *lst);
double		ft_atoi(char *str);
int			ft_power(int base, int power);
void		ft_write_err(char *s);
void		ft_map(t_list *lst, char *name);
void		ft_insert_data(char **tmp, t_list *lst, int	*count);
void		ft_set_pixel(t_list *lst);
int			ft_tolower(int c);
void		ft_write(t_list *lst);
char		**ft_split(char *s, char c);
void		ft_free_2d(char **s);
void		ft_free_point(t_list *lst);
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int			ft_chk_color(t_list *lst, int i, int in);
void		ft_write_line_horizon(t_list *lst, int i);
void		ft_write_line_vertical(t_list *lst, int i);
void		ft_write_map(t_list *lst, char *name);
t_point		ft_rotate(double x, double y, double z, t_list *lst);
double		ft_chk_z(t_list *lst, int next, int i, int dis);
int			ft_close(t_list *lst);
int			ft_key_hook(int key, t_list *lst);
int			ft_mouse_hook(int key, int x, int y, t_list *lst);
void		ft_loop(t_list *lst, int mode);

#endif
