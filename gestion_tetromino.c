/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_tetromino.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:04:00 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/02 18:00:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_conv_tetro(char *tetro, unsigned short **tab, int *size)
{
	unsigned short	tetro_bits;
	int				i;	

	tetro_bits = 0;
	i = 1;
	while (*tetro && i > 0)
	{
		if (*tetro++ == '#')
			tetro_bits += i;
		i <<= 1;
	}
	if (ft_verif_tetro_ok(&tetro_bits))
	{
		(*tab)[(*size)++] = tetro_bits;
		return (1);
	}
	return (0);
}

int				ft_verif_tetro_ok(unsigned short *tetro)
{
	while (!(*tetro & 15))
		*tetro >>= 4;
	while (!(*tetro & 4369))
		*tetro >>= 1;
	if ( VERIF(tetro) )
		return (1);
	return (0);
}

unsigned long	ft_tetro_long(unsigned short tetro)
{
	int				i;
	unsigned long	tetro_long;
	unsigned long	mask;

	i = -1;
	tetro_long = (unsigned long)tetro;
	while (++i < 4)
	{
		mask = ft_pow(2, 4 + 16 * i) - 1;
		mask &= tetro_long;
		tetro_long ^= mask;
		tetro_long <<= 12;
		tetro_long ^= mask;
	}
	return (tetro_long);
}
