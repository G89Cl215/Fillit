/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:13:55 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/02 17:47:53 by tgouedar         ###   ########.fr       */
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

void			ft_print_errors(int n);
int				ft_free_var(unsigned short **tab, char **tetro, char **line);
int				ft_check_errors(char **line);
//unsigned long long	ft_column_mask(int size_map);
unsigned short	ft_line_mask(int size_map);
unsigned short	*ft_gen_map(int size_map);
int				ft_conv_tetro(char *tetro, unsigned short **tab, int *size);
int				ft_verif_tetro_ok(unsigned short *tetro);
unsigned long	ft_tetro_long(unsigned short tetro);
int				t_resolve(unsigned short **map, unsigned short **tab);

#endif
