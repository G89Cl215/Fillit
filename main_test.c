/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:58:41 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 23:27:38 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "gestion_tetromino.h"
#include "gestion_map.h"
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	unsigned short i = 0;
	unsigned short *map;
/*	i = ft_conv_tetro("......##...#...#");
	ft_putnbr_base(i, "01");
	ft_putchar('\n');
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr(ft_verif_tetro_ok(&i));
	ft_putchar('\n');
	ft_putnbr_base(i, "01");
	ft_putchar('\n');
	i = ft_conv_tetro("####....");
	ft_putnbr_base(i, "01");
	ft_putchar('\n');
	ft_putnbr(ft_verif_tetro_ok(&i));
	while (++i < 9)
	{
		printf("%llu\n", ft_column_mask(4));
//		ft_putchar('\n');
	}
	*/
	map = ft_gen_map(11);
	while (i < 16)
	{
		ft_putnbr_base(map[i++], "01");
		ft_putchar('\n');
	}
		free(map);
	strlen(NULL);
	return (0);
}
