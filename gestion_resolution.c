/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:51:18 by baavril           #+#    #+#             */
/*   Updated: 2018/12/03 20:58:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_resolve(t_us **tab)
{
	int		map_size;
	int		i;
	t_us	*map;
	char	*tab_coord;

	i = 0;
	while ((*tab)[i])
		i++;
	map_size = ft_map_size_min(i);
	map = ft_gen_map(map_size);
	if (!(tab_coord = (char*)malloc((2 * i + 1) * sizeof(*tab_coord))))
		return (NULL);
	tab_coord[2 * i + 1] = 127;
	while (!(ft_resolve_map(&map, *tab, map_size, &tab_coord)))
	{
		ft_memdel((void**)&map);
		map = ft_gen_map(++map_size);
	}
	ft_memdel((void**)&map);
	tab_coord[2 * i] = (char)map_size;
/*	i = -1;
	while (tab_coord[++i] != 127)
	{
		ft_putnbr(tab_coord[i]);
		ft_putchar('\n');
	}*/
	return (tab_coord);
}

int		ft_resolve_map(t_us **map, t_us *tab, int map_size, char **coord)
{
	t_ul		tetro;
	int			count;
	int			i;
	static int	tetro_count = 0;

	if ((i = -1) && *tab == 0)
		return (1);
	tetro = ft_tetro_long(*tab);
	while (++i < map_size && (count = -1))
	{
		while (++count < map_size && (tetro & *((t_ul*)&((*map)[i]))))
			tetro <<= 1;
		if (!(tetro & (*((t_ul*)&((*map)[i])))))
		{
			*((t_ul*)&((*map)[i])) |= tetro;
			if (ft_resolve_map(map, &(tab[1]), map_size, coord))
			{
				(*coord)[2 * tetro_count] = count;
				(*coord)[2 * tetro_count++ + 1] = i;
				return (1);
			}
		}
		tetro >>= count;
	}
	return (0);
}
