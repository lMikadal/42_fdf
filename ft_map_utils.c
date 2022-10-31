/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:59:18 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/26 21:59:24 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_chk_color_map(char *s)
{
	int	len;
	int	i;

	len = ft_strlen(s);
	i = -1;
	while (++i < len)
	{
		if (s[i] == ',')
			return (i);
	}
	return (-1);
}

static int	ft_color_util(char c)
{
	int	color[16];
	int	i;
	int	start;

	i = 0;
	start = '0';
	while (start <= '9')
		color[i++] = start++;
	start = 'a';
	while (start <= 'f')
		color[i++] = start++;
	i = 0;
	c = ft_tolower(c);
	while (color[i] != c)
		i++;
	return (i);
}

static int	ft_oct(char *s)
{
	int	i;
	int	color;
	int	j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	color = 0;
	j = 0;
	while (i > 0)
	{
		i--;
		if (i != 0)
			color += ft_color_util(s[j++]) * ft_power(16, i);
		else
			color += ft_color_util(s[j++]);
	}
	return (color);
}

static int	ft_color(char *s)
{
	int	i;

	i = 0;
	while (s[i] != ',')
		i++;
	i++;
	if (s[i] && s[i] != '\n')
	{
		if (s[i] == '0' && (s[i + 1] == 'x' || s[i + 1] == 'X'))
			return (ft_oct(&s[i + 2]));
		else
			return (ft_atoi(&s[i]));
	}
	return (0);
}

void	ft_insert_data(char **tmp, t_list *lst, int	*count)
{
	int	i;

	i = 0;
	while (tmp[i] && tmp[i][0] != '\n')
	{
		lst->point[*count][2] = ft_atoi(tmp[i]);
		if (ft_chk_color_map(tmp[i]) != -1)
			lst->point[*count][3] = ft_color(tmp[i]);
		else
			lst->point[*count][3] = 0xffffff;
		*count += 1;
		i++;
	}
}
