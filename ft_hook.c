/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:56:17 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/27 12:56:18 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_re(t_list *lst)
{
	mlx_destroy_image(lst->img->mlx, lst->img->img);
	ft_set_pixel(lst);
	ft_write(lst);
}

int	ft_close(t_list *lst)
{
	mlx_destroy_window(lst->img->mlx, lst->img->mlx_win);
	mlx_destroy_image(lst->img->mlx, lst->img->img);
	ft_free_point(lst);
	free(lst->img);
	exit (0);
	return (0);
}

static void	ft_esc(t_list *lst)
{
	mlx_destroy_window(lst->img->mlx, lst->img->mlx_win);
	mlx_destroy_image(lst->img->mlx, lst->img->img);
	ft_free_point(lst);
	free(lst->img);
	exit (0);
}

int	ft_key_hook(int key, t_list *lst)
{
	if (key == ESC)
		ft_esc(lst);
	else if (key == UP)
		lst->start_y -= TRAN;
	else if (key == DOWN)
		lst->start_y += TRAN;
	else if (key == LEFT)
		lst->start_x -= TRAN;
	else if (key == RIGHT)
		lst->start_x += TRAN;
	ft_re(lst);
	return (0);
}

int	ft_mouse_hook(int key, int x, int y, t_list *lst)
{
	(void)x;
	(void)y;
	if (key == ZOOMIN)
	{
		lst->dis_x += ZOOM;
		lst->dis_y += ZOOM;
		ft_loop(lst, 1);
	}
	else if (key == ZOOMOUT && lst->dis_x > 0)
	{
		lst->dis_x -= ZOOM;
		lst->dis_y -= ZOOM;
		ft_loop(lst, 2);
	}
	ft_re(lst);
	return (0);
}
