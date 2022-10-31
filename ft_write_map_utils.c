/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:51:50 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/27 14:51:52 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_rotate_z(t_point *p, double angle)
{
	double	sin_ang;
	double	cos_ang;
	double	x;
	double	y;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	x = p->x;
	y = p->y;
	p->x = x * cos_ang - y * sin_ang;
	p->y = y * cos_ang + x * sin_ang;
}

static void	ft_rotate_y(t_point *p, double angle)
{
	double	sin_ang;
	double	cos_ang;
	double	x;
	double	z;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	x = p->x;
	z = p->z;
	p->x = x * cos_ang + z * sin_ang;
	p->z = z * cos_ang - x * sin_ang;
}

static void	ft_rotate_x(t_point *p, double angle)
{
	double	sin_ang;
	double	cos_ang;
	double	y;
	double	z;

	sin_ang = sin(angle);
	cos_ang = cos(angle);
	y = p->y;
	z = p->z;
	p->y = y * cos_ang - z * sin_ang;
	p->z = z * cos_ang + y * sin_ang;
}

t_point	ft_rotate(double x, double y, double z, t_list *lst)
{
	t_point	p;

	p.x = x;
	p.y = y;
	p.z = z;
	ft_rotate_z(&p, lst->ang_z);
	ft_rotate_y(&p, lst->ang_y);
	ft_rotate_x(&p, lst->ang_x);
	return (p);
}

double	ft_chk_z(t_list *lst, int next, int i, int dis)
{
	double	tmp;

	tmp = 0;
	if (lst->point[i][2] != lst->point[i + next][2])
	{
		if ((lst->point[i][2] > 0 && lst->point[i + next][2] > 0) || \
		(lst->point[i][2] < 0 && lst->point[i + next][2] < 0))
		{
			tmp = fabs(lst->point[i][2] - lst->point[i + next][2]) \
			/ (double)dis;
		}
		else
		{
			tmp = (fabs(lst->point[i][2]) + fabs(lst->point[i + next][2])) \
			/ (double)dis;
		}
	}
	else
		tmp = lst->point[i][2];
	return (tmp);
}
