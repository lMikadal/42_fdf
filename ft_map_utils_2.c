/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:21:09 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/27 12:21:11 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_pixel(t_list *lst)
{
	int	s_x;
	int	s_y;
	int	x;
	int	y;
	int	count;

	y = -1;
	s_y = lst->start_y;
	count = 0;
	while (++y < lst->y)
	{
		x = -1;
		s_x = lst->start_x;
		while (++x < lst->x)
		{
			lst->point[count][0] = s_x;
			lst->point[count][1] = s_y;
			count++;
			s_x += lst->dis_x;
		}
		s_y += lst->dis_y;
	}
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

void	ft_write(t_list *lst)
{
	int	i;

	lst->img->img = mlx_new_image(lst->img->mlx, HORIZON, VERTICAL);
	lst->img->addr = mlx_get_data_addr(lst->img->img, &lst->img->bits, \
								&lst->img->line, &lst->img->endian);
	i = -1;
	while (++i < lst->sum)
	{
		if (i % lst->x < lst->x - 1)
			ft_write_line_horizon(lst, i);
		if (i + lst->x < lst->sum)
			ft_write_line_vertical(lst, i);
	}
	mlx_put_image_to_window(lst->img->mlx, lst->img->mlx_win, \
								lst->img->img, 0, 0);
}
