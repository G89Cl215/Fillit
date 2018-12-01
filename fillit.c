/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:22:41 by baavril           #+#    #+#             */
/*   Updated: 2018/12/01 22:58:32 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestion_tetromino.h"
#include "gestion_map.h"
#include "gestion_de_crise.h"
#include <fcntl.h>
#include <stdio.h>

int		ft_check_errors(char **line)
{
	int var;

	var = ft_strlen(*line);
	if (var != 4)
	{
		ft_memdel((void**)line);
		ft_print_errors(1);
		return (0);
	}
	return (1);
}
/*
   char	*ft_stock_lines(char **lines, char **line)
   {
   char *tmp;

   if (!(tmp = ft_memalloc(17)))
   return (0);
   if (lines == NULL)
   lines = ft_strdup(line);
   else
   tmp = lines;
   lines = ft_strjoinfree(tmp, line);
   }*/

int	ft_get_next_tetro(fd)
{
	char			*line;
	unsigned short	*tab;
	int				i;
	static int		size = 0;
	char			*tetro;

	i = -1;
	if (!(tab = ft_memalloc(sizeof(*tab) * 26)) || !(tetro = ft_memalloc(17)))
		return (ft_free_var(&tab, &tetro));
	while (++i < 4)
	{
		get_next_line(fd, &line);
		//		ft_putendl(line);
		if (!(ft_check_errors(&line)))
			return (ft_free_var(&tab, &tetro));
		ft_strappend(&tetro, &line);
	}
	get_next_line(fd, &line);
	//	ft_putendl(line);
	if (*line)
	{
		ft_print_errors(2);
		free(line);
		return (ft_free_var(&tab, &tetro));
	}
	if (!(ft_conv_tetro(tetro, &tab, &size)))
		return (ft_free_var(&tab, &tetro));
	ft_memdel((void**)&tetro);
	return (1);
}

int		main(int ac, char **av)
{
	int fd = 0;
	//	char *line;
	int i = 0;

	if (ac > 1)
	{
		fd = open(av[1], O_RDONLY);
		while (i < 8)
		{
			ft_get_next_tetro(fd);
			i++;
		}
	}
	(void)fd;
	//	free(line);
	close(fd);
}
