/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:10:04 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 21:56:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gestion_map.h"

unsigned short	ft_line_mask(int size_map)
{
	return (ft_pow(2, size_map) - 1);
}
/*
unsigned long long	ft_column_mask(int size_map)
{
	int					i;
	unsigned long long 	res;

	i = size_map;
	res = 1;
	while (--i)
	{
		res <<= size_map;
		res++;
	}
	return (res);
}
*/
unsigned short		*ft_gen_map(int size_map)
{
	unsigned short	*map;
	int				i;

	i = -1;
	if (!(map = (unsigned short*)malloc(sizeof(*map) * 16)))
		return (NULL);
	while (++i < size_map)
		map[i] = ~(ft_line_mask(size_map));
	while (i < 16)
		map[i++] = ~0;
	return (map);
}
