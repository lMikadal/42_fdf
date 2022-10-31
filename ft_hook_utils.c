/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:18:59 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/30 12:19:07 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_loop(t_list *lst, int mode)
{
	int	i;

	i = -1;
	while (++i < lst->sum && mode == 1)
	{
		if (lst->point[i][2] > 0)
			lst->point[i][2] += ZOOM;
		else if (lst->point [i][2] < 0)
			lst->point[i][2] -= ZOOM;
	}
	i = -1;
	while (++i < lst->sum && mode == 2)
	{
		if (lst->point[i][2] > 0)
			lst->point[i][2] -= ZOOM;
		else if (lst->point [i][2] < 0)
			lst->point[i][2] += ZOOM;
	}
}
