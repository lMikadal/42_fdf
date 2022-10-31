/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:23:16 by pmikada           #+#    #+#             */
/*   Updated: 2022/07/12 00:28:19 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut(t_buff *b)
{
	char	*m;
	int		diff;
	int		len_nl;
	int		i;

	len_nl = ft_strlen_nl(b->temp_buff);
	if (len_nl == -1)
		len_nl = ft_strlen_g(b->temp_buff);
	diff = ft_strlen_g(b->temp_buff) - len_nl;
	m = (char *)malloc((diff * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < diff)
		m[i++] = b->temp_buff[len_nl++];
	m[i] = '\0';
	free(b->temp_buff);
	if (m[0] == '\0')
	{
		free(m);
		return (NULL);
	}
	return (m);
}

void	ft_re_buff(char **r_buff, t_buff *b)
{
	*r_buff = ft_strdup(b->temp_buff);
	b->temp_buff = ft_cut(b);
}

char	*get_next_line(int fd)
{
	static t_buff	b;
	char			*r_buff;
	int				r_read;

	if (fd < 0 || BUF_SIZE < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	r_read = 1;
	r_buff = NULL;
	b.buff = (char *)malloc((BUF_SIZE * sizeof(char)) + 1);
	if (b.buff == NULL)
		return (NULL);
	while (r_read > 0)
	{
		r_read = read(fd, b.buff, BUF_SIZE);
		b.buff[r_read] = '\0';
		if (r_read == 0)
			break ;
		b.temp_buff = ft_strjoin(b.temp_buff, b.buff);
		if (ft_strlen_nl(b.temp_buff) != -1)
			break ;
	}
	if (b.temp_buff != NULL)
		ft_re_buff(&r_buff, &b);
	free(b.buff);
	return (r_buff);
}
