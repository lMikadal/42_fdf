/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:04:28 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/27 12:04:36 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line) + (x * (img->bits / 8)));
	*(unsigned int *)dst = color;
}

int	ft_chk_color(t_list *lst, int i, int in)
{
	if (lst->point[i][3] == 16777215)
		return ((int)lst->point[in][3]);
	else
		return ((int)lst->point[i][3]);
}

void	ft_write_line_horizon(t_list *lst, int i)
{
	int		color;
	double	move;
	double	z;
	t_point	p;

	color = ft_chk_color(lst, i, i + 1);
	move = 1;
	z = ft_chk_z(lst, 1, i, lst->dis_x);
	if (lst->point[i][2] > lst->point[i + 1][2])
		z *= -1;
	while (move <= lst->dis_x)
	{
		if (lst->point[i][2] != lst->point[i + 1][2])
		{
			p = ft_rotate(lst->point[i][0] + move, lst->point[i][1], \
				lst->point[i][2] + (z * move), lst);
		}
		else
			p = ft_rotate(lst->point[i][0] + move, lst->point[i][1], z, lst);
		if (p.x >= 0 && p.x < HORIZON && p.y >= 0 && p.y < VERTICAL)
			ft_mlx_pixel_put(lst->img, p.x, p.y, color);
		move++;
	}
}

void	ft_write_line_vertical(t_list *lst, int i)
{
	int		color;
	double	move;
	double	z;
	t_point	p;

	color = ft_chk_color(lst, i, i + lst->x);
	move = 1;
	z = ft_chk_z(lst, lst->x, i, lst->dis_y);
	if (lst->point[i][2] > lst->point[i + lst->x][2])
		z *= -1;
	while (move <= lst->dis_y)
	{
		if (lst->point[i][2] != lst->point[i + lst->x][2])
		{
			p = ft_rotate(lst->point[i][0], lst->point[i][1] + move, \
				lst->point[i][2] + (z * move), lst);
		}
		else
			p = ft_rotate(lst->point[i][0], lst->point[i][1] + move, z, lst);
		if (p.x >= 0 && p.x < HORIZON && p.y >= 0 && p.y < VERTICAL)
			ft_mlx_pixel_put(lst->img, p.x, p.y, color);
		move++;
	}
}

void	ft_write_map(t_list *lst, char *name)
{
	t_point	p;
	t_point	p_n;

	lst->img->mlx = mlx_init();
	lst->img->mlx_win = mlx_new_window(lst->img->mlx, HORIZON, VERTICAL, name);
	ft_write(lst);
	mlx_key_hook(lst->img->mlx_win, ft_key_hook, lst);
	mlx_mouse_hook(lst->img->mlx_win, ft_mouse_hook, lst);
	mlx_hook(lst->img->mlx_win, 17, 0L, ft_close, lst);
	mlx_loop(lst->img->mlx);
}
