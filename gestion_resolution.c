/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:51:18 by baavril           #+#    #+#             */
/*   Updated: 2018/12/02 18:30:44 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

unsigned short	*ft_resolve(unsigned short **tab)
{
	int				map_size;
	unsigned short	*map;
	
	map_size = 2;
	map = ft_gen_map(map_size);
	while (!(ft_resolve_map(&map, tab, map_size)))
		map = ft_gen_map(++map_size);
	return (map);
}

int		ft_resolve_map(unsigned short **map, unsigned short **tab, int map_size)
{
	unsigned long	tetro;
//	unsigned int *coor_tab;
	int				count;
	int				i;

	i = 0;
	tetro = ft_tetro_long(**tab);
	if (**tab == 0)
		return (1);
	while (i < map_size)
	{
		count = -1;
		while ((tetro & (long)((*map)[i])) && ++count < map_size)
			tetro <<= 1;
		if (!(tetro & (long)((*map)[i])))
		{
			(long)((*map)[i]) |= tetro;
			//stock coord >>GOES HERE<<
			if (ft_resolve_map(map, &(tab[1]), map_size))
				return (1);
		}
		i++;
		tetro >>= count;
	}
	return (0);
}	
