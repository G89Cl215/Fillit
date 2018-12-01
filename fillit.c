/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:22:41 by baavril           #+#    #+#             */
/*   Updated: 2018/12/01 23:40:17 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_next_tetro(int fd, unsigned short **tab)
{
	char			*tetro;
	char			*line;
	int				i;
	static int		size = 0;

	i = -1;
	tetro = ft_memalloc(1);
	while (++i < 4)
	{
		get_next_line(fd, &line);
		if (!(ft_check_errors(&line)))
			return (ft_free_var(tab, &tetro, line));
		ft_strappend(&tetro, &line);
	}
	get_next_line(fd, &line);
	if (*line)
	{
		ft_print_errors(2);
		return (ft_free_var(tab, &tetro, line));
	}
	if (!(ft_conv_tetro(tetro, tab, &size)))
		return (ft_free_var(tab, &tetro, line));
	ft_free_var(NULL, &tetro, &line)
	return (size);
}

int		main(int ac, char **av)
{
	unsigned short	*tab;
	int				i = 0;
	int				fd = 0;

	if (!(tab = ft_memalloc(sizeof(*tab) * 26)))
		return (0);
	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (i < 8)
		{
			ft_get_next_tetro(fd, &tab);
			i++;
		}
	}
	(void)fd;
	//	free(line);
	close(fd);
}
