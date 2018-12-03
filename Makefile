# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2018/12/03 23:11:58 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCFILE	= gestion_tetromino.c\
		  gestion_map.c\
		  gestion_de_crise.c\
		  gestion_resolution.c\
		  gestion_affichage.c\
		  fillit.c\

SRCDIR	= .
SRC		= $(addprefix $(SRCDIR)/,$(SRCFILE))
HDR 	= .
OBJDIR	= obj
OBJFILE	= $(SRCFILE:.c=.o)
OBJ		= $(addprefix $(OBJDIR)/,$(OBJFILE))

LIB		= libft/libft.a

NAME 	= fillit

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIB)

$(OBJDIR)/%.o : %.c
	@/bin/mkdir $(OBJDIR) 2>/dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $< -I $(HDR)

$(LIB) :
	make -C libft/

clean :
	make -C libft fclean
	/bin/rm -f $(OBJ) 2>/dev/null  || true
	/bin/rmdir $(OBJDIR) 2>/dev/null || true

fclean : clean
	make -C libft fclean
	/bin/rm -f $(NAME)

re_lib :
	make re -C libft/

re : fclean all
