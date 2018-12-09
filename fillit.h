/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 23:13:55 by tgouedar          #+#    #+#             */
/*   Updated: 2018/12/09 12:02:16 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# define VERIF(a) (V_1(a) || V_2(a) || V_3(a) || V_4(a))
# define V_1(a) (*a == 15 || *a == 23 || *a == 39 || *a == 51 || *a == 54)
# define V_2(a) (*a == 71 || *a == 99 || *a == 113 || *a == 114 || *a == 116)
# define V_3(a) (*a == 275 || *a == 305 || *a == 306 || *a == 547 || *a == 561)
# define V_4(a) (*a == 562 || *a == 785 || *a == 802 || *a == 4369)

typedef unsigned short	t_us;
typedef unsigned long	t_ul;

int		ft_free_var(t_us **tab, char **tetro, char **line);
int		ft_check_errors(char **line);
int		ft_map_size_min(int size);
t_ul	ft_line_mask(int size_map);
t_us	*ft_gen_map(int size_map);
int		ft_conv_tetro(char *tetro, t_us **tab, int *size);
int		ft_verif_tetro_ok(t_us *tetro);
t_ul	ft_tetro_long(t_us tetro);
int		ft_resolve_map(t_us **map, t_us *tab, int size_map, char **coord);
char	*ft_resolve(t_us **tab);
void	ft_affichage(char *tab_coord, t_us *tab);

#endif
