/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_tetromino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:04:00 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/05 16:47:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_conv_tetro(char *tetro, t_us **tab, int *size)
{
	t_us	tetro_bits;
	int		i;

	tetro_bits = 0;
	i = 1;
	while (*tetro && i > 0)
	{
		if (*tetro == '#')
			tetro_bits += i;
		else if (*tetro != '.')
			return (0);
		i <<= 1;
		tetro++;
	}
	if (ft_verif_tetro_ok(&tetro_bits))
	{
		(*tab)[(*size)++] = tetro_bits;
		return (1);
}
	return (0);
}

int		ft_verif_tetro_ok(t_us *tetro)
{
	if (!(*tetro))
		return (0);
	while (!(*tetro & 15))
		*tetro >>= 4;
	while (!(*tetro & 4369))
		*tetro >>= 1;
	if (VERIF(tetro))
		return (1);
	return (0);
}

t_ul	ft_tetro_long(t_us tetro)
{
	int		i;
	t_ul	tetro_long;
	t_ul	mask;

	i = -1;
	tetro_long = tetro;
	while (++i < 4)
	{
		mask = ft_line_mask(4 + 16 * i);
		mask &= tetro_long;
		tetro_long ^= mask;
		tetro_long <<= 12;
		tetro_long ^= mask;
	}
	return (tetro_long);
}
