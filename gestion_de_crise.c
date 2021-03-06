/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:02:52 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/09 11:46:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_free_var(t_us **tab, char **tetro, char **line)
{
	ft_memdel((void**)tetro);
	ft_memdel((void**)line);
	if (tab)
	{
		ft_putendl("error");
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
