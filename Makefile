# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2018/11/29 17:03:26 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCFILE	= 

SRCDIR	= ./
SRC		= $(addprefix $(SRCDIR),$(SRCFILE))
HDR 	= .
OBJ 	= $(SRCFILE:.c=.o)

NAME 	= fillit

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
