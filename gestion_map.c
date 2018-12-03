/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:10:04 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 19:40:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_ul	ft_line_mask(int size_map)
{
	return (ft_pow(2, size_map) - 1);
}

int		ft_map_size_min(int size)
{
	int		res;

	size *= 4;
	res = 2;
	while (res * res < size)
		res++;
	return (res);
}

t_us	*ft_gen_map(int size_map)
{
	t_us	*map;
	int		i;

	i = -1;
	if (!(map = (t_us*)malloc(sizeof(*map) * 16)))
		return (NULL);
	while (++i < size_map)
		map[i] = ~((t_us)ft_line_mask(size_map));
	while (i < 16)
		map[i++] = ~0;
	return (map);
}
