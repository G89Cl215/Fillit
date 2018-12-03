/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_affichage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:40:38 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 22:27:57 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_place_lines(char *str, int map_size)
{
	int i;

	i = 0;
	while (*str)
	{
		if (!((i++ + 1) % map_size))
			*str = '\n';
		str++;
	}
}

void	ft_place_tetro(t_us tetro, char i, char j, char *str)
{
	static int	lettre = 0;
	int			t_ligne;

	while (j--)
		str = ft_memchr(str, '\n', 500) + 1;
	while (tetro)
	{
		str += i;
		t_ligne = 0;
		while (*str && *str != '\n' && t_ligne++ < 4)
		{
			if (1 & tetro)
				*(str) = 'A' + lettre;
			str++;
			tetro >>= 1;
		}
		while (t_ligne++ < 4)
			tetro >>= 1;
		while (*str && *str != '\n')
			str++;
		str++;
	}
	lettre++;
}

void	ft_affichage(char *tab_coord, t_us *tab)
{
	int		i;
	int		j;
	int		map_size;
	char	*str;

	i = 0;
	j = 0;
	while (tab_coord[i] != 127)
		i++;
	map_size = tab_coord[--i];
	i -= 2;
	str = ft_strnew(map_size * (map_size + 1) - 1);
	ft_memset(str, '.', map_size * (map_size + 1) - 1);
	str[map_size * (map_size + 1) - 1] = 0;
	ft_place_lines(str, map_size + 1);
	while (i >= 0)
	{
		ft_place_tetro(*tab, tab_coord[i], tab_coord[i + 1], str);
		i -= 2;
		tab++;
	}
	ft_putstr(str);
	ft_memdel((void**)&str);
}
