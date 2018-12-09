/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:48:20 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 12:18:28 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned long	ft_pow(unsigned long n, unsigned int i)
{
	if (!i)
		return (1);
	return (n * ft_pow(n, --i));
}