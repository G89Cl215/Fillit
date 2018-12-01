/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:54:11 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 21:21:34 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTION_MAP_H
# define GESTION_MAP_H

#include "libft/libft.h"

//unsigned long long	ft_column_mask(int size_map);
unsigned short		ft_line_mask(int size_map);
unsigned short		*ft_gen_map(int size_map);

#endif
