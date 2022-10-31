/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:33:19 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/26 20:33:30 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_chk_color_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

static void	ft_count_x(char *text, t_list *lst)
{
	char	**str;
	int		i;

	str = ft_split(text, ' ');
	i = 0;
	while (str[i] && str[i][0] != '\n')
		i++;
	if (lst->y == 0)
		lst->x = i;
	if (lst->x != i)
	{
		ft_free_2d(str);
		ft_write_err("Found wrong line length. Exiting.");
	}
	ft_free_2d(str);
}

static void	ft_check_line(t_list *lst, char *name)
{
	int		fd;
	char	*text;
	int		chk;

	fd = open(name, O_RDWR);
	while (1)
	{
		text = get_next_line(fd);
		if (text == 0)
			break ;
		ft_count_x(text, lst);
		lst->y += 1;
		free(text);
	}
	lst->sum = lst->x * lst->y;
	close(fd);
}

static void	ft_malloc_fd(t_list *lst)
{
	int	i;

	lst->point = (double **)malloc(sizeof(double *) * lst->sum);
	if (lst->point == 0)
		return ;
	i = -1;
	while (++i < lst->sum)
	{
		lst->point[i] = (double *)malloc(sizeof(double) * 4);
		if (lst->point[i] == 0)
			return ;
	}
}

void	ft_map(t_list *lst, char *name)
{
	int		fd;
	char	*tmp_g;
	char	**tmp_s;
	int		count;

	ft_check_line(lst, name);
	fd = open(name, O_RDWR);
	ft_malloc_fd(lst);
	count = 0;
	while (1)
	{
		tmp_g = get_next_line(fd);
		if (tmp_g == 0)
			break ;
		tmp_s = ft_split(tmp_g, ' ');
		free(tmp_g);
		ft_insert_data(tmp_s, lst, &count);
		ft_free_2d(tmp_s);
	}
	close(fd);
	ft_set_pixel(lst);
}
