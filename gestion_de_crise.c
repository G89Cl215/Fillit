/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_de_crise.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 22:02:52 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 22:50:22 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestion_de_crise.h"

void	ft_print_errors(int n)
{
	if (n == 1)
		ft_putstr("Length is invalid\n");
	if (n == 2)
		ft_putstr("The map is invalid\n");
}

int		ft_free_var(unsigned short **tab, char **tetro)
{
	ft_memdel((void**)tab);
	ft_memdel((void**)tetro);
	return (0);
}
