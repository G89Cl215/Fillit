/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:10:04 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 19:10:43 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestion_map.h"

unsigned long long	ft_line_mask(int size_map)
{
	return (ft_pow(2, size_map) - 1);
}

unsigned long long	ft_column_mask(int size_map)
{
	int					i;
	unsigned long long 	res;

	i = size_map;
	res = 1;
	while(--i)
	{
		res <<= size_map;
		res++;
	}
	return (res);
}
