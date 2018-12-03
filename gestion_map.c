/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:10:04 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 15:42:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

ulong	ft_line_mask(int size_map)
{
	return (ft_pow(2, size_map) - 1);
}

int				ft_map_size_min(int size)
{
	int		res;

	size *= 4;
	res = 2;
	while (res * res < size)
		res++;
	return (res);
}

ushort	*ft_gen_map(int size_map)
{
	ushort	*map;
	int		i;

	i = -1;
	if (!(map = (ushort*)malloc(sizeof(*map) * 16)))
		return (NULL);
	while (++i < size_map)
		map[i] = ~((ushort)ft_line_mask(size_map));
	while (i < 16)
		map[i++] = ~0;
	return (map);
}
