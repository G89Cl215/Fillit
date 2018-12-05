/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:02:52 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/05 17:23:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_print_errors(int n)
{
	(void)n;
	ft_putendl("error");
/*	if (n == 1)
		ft_putstr("Length is invalid\n");
	if (n == 2)
		ft_putstr("The map is invalid\n");
	if (n == 3)
		ft_putstr("Usage : Les tretriminos doivent etre valides (cf regles de \
Tetris). Ils sont decrits, grace au symbole '#' dans des blocs de \
4 lignes de 4 caracteres, separes d'une seule ligne vide");*/
}

int		ft_free_var(t_us **tab, char **tetro, char **line)
{
	ft_memdel((void**)tetro);
	ft_memdel((void**)line);
	if (tab)
	{
		ft_print_errors(0);
		ft_memdel((void**)tab);
		return (-1);
	}
	return (0);
}

int		ft_check_errors(char **line)
{
	int var;

	var = ft_strlen(*line);
	if (var != 4)
		return (0);
	return (1);
}
