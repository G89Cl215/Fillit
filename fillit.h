/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:13:55 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/03 15:40:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft/libft.h"

# define VERIF(tetro) (*tetro == 15 || *tetro == 23 || *tetro == 39\
		|| *tetro == 51 || *tetro == 54 || *tetro == 71 || *tetro == 94\
		|| *tetro == 99 || *tetro == 113 || *tetro == 116 || *tetro == 275\
		|| *tetro == 305 || *tetro == 306 || *tetro == 547 || *tetro == 561\
		|| *tetro == 562 || *tetro == 785 || *tetro == 802 || *tetro == 4369)

typedef unsigned short	ushort;
typedef unsigned long	ulong;

void	ft_print_errors(int n);
int		ft_free_var(ushort **tab, char **tetro, char **line);
int		ft_check_errors(char **line);
int		ft_map_size_min(int size);
ulong	ft_line_mask(int size_map);
ushort	*ft_gen_map(int size_map);
int		ft_conv_tetro(char *tetro, ushort **tab, int *size);
int		ft_verif_tetro_ok(ushort *tetro);
ulong	ft_tetro_long(ushort tetro);
int		ft_resolve_map(ushort **map, ushort *tab, int size_map);
ushort	*ft_resolve(ushort **tab);

#endif
