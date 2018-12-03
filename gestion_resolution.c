/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:51:18 by baavril           #+#    #+#             */
/*   Updated: 2018/12/03 15:47:05 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// >>>>>TEST<<<<<<
/*void		ft_putnbr_base_Ulong(unsigned long i, char *base)
{
	size_t			j;

	j = ft_strlen(base);
	if (i >= j)
		ft_putnbr_base_long(i / j, base);
	ft_putchar(base[i % j]);
}
*/

ushort	*ft_resolve(ushort **tab)
{
	int		map_size;
	int		i;
	ushort	*map;

	i = 0;
	while ((*tab)[i])
		i++;
	map_size = ft_map_size_min(i);
	map = ft_gen_map(map_size);
	while (!(i = ft_resolve_map(&map, *tab, map_size)))
	{
		ft_putendl("+");
		map = ft_gen_map(++map_size);
	}
	return (map);
}

int		ft_resolve_map(ushort **map, ushort *tab, int map_size)
{
	ulong	tetro;
	int		count;
	int		i;

	i = -1;
	if (*tab == 0)
		return (1);
	tetro = ft_tetro_long(*tab);
/*	ft_putnbr(*tab);
	ft_putchar('\n');
	ft_putnbr(tab[1]);
	ft_putchar('\n');
	ft_putnbr_base_Ulong(tetro, "01");*/
	while (++i < map_size)
	{
		ft_putendl("c");
		count = -1;
		while ((tetro & *((ulong*)&((*map)[i]))) && ++count < map_size)
			tetro <<= 1;
		if (!(tetro & (*((ulong*)&((*map)[i])))))
		{
/*			ft_putendl("PLACAGE DE PIECE");
			ft_putstr("ligne : ");
			ft_putnbr_base_Ulong((*((unsigned long*)&((*map)[i]))), "01");
			ft_putchar('\n');
			ft_putstr("piece :			 ");
			ft_putnbr_base_Ulong(tetro, "01");
			ft_putchar('\n');
			ft_putstr("resultat :			 ");
			ft_putnbr_base_Ulong(tetro & (unsigned long)((*map)[i]), "01");
			ft_putchar('\n');*/
			*((ulong*)&((*map)[i])) |= tetro;
			if (ft_resolve_map(map, &(tab[1]), map_size))
			{
//stock coord >>GOES HERE<<
				return (1);
			}
		}
		tetro >>= count;
	}
	return (0);
}
