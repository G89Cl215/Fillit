/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_resolution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baavril <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:51:18 by baavril           #+#    #+#             */
/*   Updated: 2018/12/02 17:46:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_resolve(unsigned short **map, unsigned short **tab)
{
//	t_list *mapper;
	unsigned long *new_tab;
//	unsigned int *coor_tab;
	int count;
	int map_size;

	map_size = 2;
	i = 0;
	new_tab = ft_tetro_long(**tab);
	if (**tab == 0)
		return (TRUE);
	while (i < map_size)
	{
		count = -1;
		while ((new_tab & (long)map[i]) && ++count < map_size)
			new_tab >> 1;
		if (!(new_tab & map))
		{
			map |= new_tab;
			//stock coord
			if (ft_resolve(map, tab + 1, i) == TRUE)
				return (TRUE);
		}
		i++;
		new_tab << count;
	}
	return (ft_resolve(map + 1, tab, size, i);
}	
