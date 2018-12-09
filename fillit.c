/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:22:41 by baavril           #+#    #+#             */
/*   Updated: 2018/12/09 12:05:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <fcntl.h>

int		ft_get_next_tetro(int fd, t_us **tab, int flag)
{
	char			*tetro;
	char			*line;
	int				i;
	static int		size = 0;

	i = -1;
	tetro = ft_memalloc(1);
	if (flag == 1)
	{
		if (!(get_next_line(fd, &line)))
			return (ft_free_var(NULL, &tetro, &line));
		if (*line)
			return (ft_free_var(tab, &tetro, &line));
		free(line);
	}
	while (++i < 4)
	{
		if (!get_next_line(fd, &line) || !(ft_check_errors(&line)))
			return (ft_free_var(tab, &tetro, &line));
		ft_strappend(&tetro, &line);
	}
	if (!(ft_conv_tetro(tetro, tab, &size)))
		return (ft_free_var(tab, &tetro, &line));
	ft_free_var(NULL, &tetro, &line);
	return (1);
}

t_us	**ft_tab_tetro(int fd)
{
	t_us	**tab;
	t_us	*temp;
	int		size;
	int		i;

	size = 1;
	if (!(temp = (t_us*)ft_memalloc(sizeof(*tab) * 26)))
		return (NULL);
	if (ft_get_next_tetro(fd, &temp, 0) != 1)
		return (NULL);
	while ((i = ft_get_next_tetro(fd, &temp, 1)) && i != -1)
		size++;
	if (i == -1 || !(tab = (t_us**)malloc(sizeof(t_us**)))
				|| !(*tab = (t_us*)malloc(sizeof(t_us) * (size + 1))))
		return (NULL);
	(*tab)[size] = 0;
	while (size--)
		(*tab)[size] = temp[size];
	free(temp);
	return (tab);
}

int		main(int ac, char **av)
{
	t_us	**tab;
	int		fd;
	char	*coord;

	if (ac == 2)
	{
		if (((fd = open(av[1], O_RDONLY)) < 0))
		{
			ft_putendl("error");
			return (0);
		}
		if ((tab = ft_tab_tetro(fd)))
		{
			coord = ft_resolve(tab);
			ft_affichage(coord, *tab);
			ft_memdel((void**)&coord);
			free(*tab);
			free(tab);
		}
		close(fd);
	}
	else
		ft_putendl("usage : ./fillit source_file");
	return (0);
}
