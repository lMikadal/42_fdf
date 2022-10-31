/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 08:58:19 by pmikada           #+#    #+#             */
/*   Updated: 2022/10/19 08:58:22 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_chk_argv(char *av)
{
	int	len;
	int	chk;
	int	fd;

	len = ft_strlen(av);
	chk = 0;
	if (len < 4)
		chk = 1;
	else if (av[len - 1] != 'f' || av[len - 2] != 'd' \
	|| av[len - 3] != 'f' || av[len - 4] != '.')
		chk = 1;
	fd = open(av, O_RDWR);
	if (chk > 0 || fd == -1)
	{
		if (fd == -1)
			close(fd);
		write(2, "No file ", 8);
		ft_write_err(av);
	}
	close(fd);
}

int	main(int ac, char **av)
{
	t_list	lst;

	if (ac == 2)
	{
		ft_chk_argv(av[1]);
		ft_init_lst(&lst);
		ft_map(&lst, av[1]);
		lst.img = (t_img *)malloc(sizeof(t_img));
		if (lst.img == 0)
			return (0);
		ft_write_map(&lst, av[1]);
		ft_free_point(&lst);
		free(lst.img);
	}
	else
		ft_write_err("Usage : ./fdf <filename> [ case_size z_size ]");
	return (0);
}
