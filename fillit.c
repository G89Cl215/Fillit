/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:22:41 by baavril           #+#    #+#             */
/*   Updated: 2018/12/03 22:31:03 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_get_next_tetro(int fd, t_us **tab)
{
	char			*tetro;
	char			*line;
	int				i;
	static int		size = 0;

	i = -1;
	tetro = ft_memalloc(1);
	while (++i < 4)
	{
		if (!get_next_line(fd, &line) && !i)
			return (ft_free_var(NULL, &tetro, &line));
		if (!(ft_check_errors(&line)))
			return (ft_free_var(tab, &tetro, &line));
		ft_strappend(&tetro, &line);
	}
	get_next_line(fd, &line);
	if (*line)
	{
		ft_print_errors(2);
		return (ft_free_var(tab, &tetro, &line));
	}
	if (!(ft_conv_tetro(tetro, tab, &size)))
		return (ft_free_var(tab, &tetro, &line));
	ft_free_var(NULL, &tetro, &line);
	return (1);
}

t_us	*ft_tab_tetro(int fd)
{
	t_us	*tab;
	t_us	*temp;
	int		size;

	size = 0;
	if (!(temp = (t_us*)ft_memalloc(sizeof(*tab) * 26)))
		return (NULL);
	while (ft_get_next_tetro(fd, &temp))
		size++;
	if (!(tab = (t_us*)ft_memalloc(sizeof(*tab) * (size + 1))))
		return (NULL);
	tab[size] = 0;
	while (size--)
		tab[size] = temp[size];
	free(temp);
	return (tab);
}

int		main(int ac, char **av)
{
	t_us	*tab;
	int		fd;
	char	*coord;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		tab = ft_tab_tetro(fd);
		close(fd);
		coord = ft_resolve(&tab);
		ft_affichage(coord, tab);
		ft_memdel((void**)&coord);
	}
	return (0);
}
