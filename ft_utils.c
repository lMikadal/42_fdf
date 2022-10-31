/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:54:36 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/26 15:54:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_init_lst(t_list *lst)
{
	lst->point = 0;
	lst->y = 0;
	lst->x = 0;
	lst->sum = 0;
	lst->dis_y = 1;
	lst->dis_x = 1;
	lst->start_y = 10;
	lst->start_x = 700;
	lst->ang_x = 0.785;
	lst->ang_y = 0;
	lst->ang_z = 0.785;
	lst->img = 0;
}

double	ft_atoi(char *str)
{
	int			i;
	int			m;
	int			sum;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	m = 1;
	if (str[i] == '-')
		m = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	sum = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sum = (sum * 10) + (str[i] - '0');
		i++;
	}
	return (sum * m);
}

int	ft_power(int base, int power)
{
	int	tmp;

	tmp = base;
	while (power-- > 1)
		tmp *= base;
	return (tmp);
}
