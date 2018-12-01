/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_tetromino.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:03:49 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/01 19:28:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GESTION_TETROMINO_H
# define GESTION_TETROMINO_H

#include "libft/libft.h"

# define VERIF(tetro) (*tetro == 15 || *tetro == 23 || *tetro == 39\
		|| *tetro == 51 || *tetro == 54 || *tetro == 71 || *tetro == 94\
		|| *tetro == 99 || *tetro == 113 || *tetro == 116 || *tetro == 275\
		|| *tetro == 305 || *tetro == 306 || *tetro == 547 || *tetro == 561\
		|| *tetro == 562 || *tetro == 785 || *tetro == 802 || *tetro == 4369)

int		ft_conv_tetro(char *tetro, unsigned short *tab, int *size);
int		ft_verif_tetro_ok(unsigned short *tetro);

#endif
