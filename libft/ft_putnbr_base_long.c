/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_long.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:48:19 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 11:52:26 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_verif_base(char *str)
{
	while (*str)
	{
		if (ft_isin(*str, str + 1) || ft_isin(*str, "+-/*"))
			return (0);
		str++;
	}
	return (1);
}

void		ft_putnbr_base_long(long n, char *base)
{
	unsigned long	i;
	size_t			j;

	if (!(ft_verif_base(base)) || !(j = ft_strlen(base)))
	{
		ft_putstr_fd("Usage : les bases correctes sont non vides, sans doublons\
				,et sans operateur", 2);
		return ;
	}
	j = ft_strlen(base);
	if (n < 0)
		ft_putchar('-');
	i = (n < 0 ? -n : n);
	if (i >= j)
		ft_putnbr_base_long(i / j, base);
	ft_putchar(base[i % j]);
}
