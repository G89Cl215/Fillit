# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 22:11:12 by tgouedar          #+#    #+#              #
#    Updated: 2018/12/01 23:08:05 by tgouedar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra

SRCFILE	= gestion_tetromino.c\
		  gestion_map.c\
		  gestion_de_crise.c\
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
	/bin/rm -f $(OBJ)
	/bin/rmdir $(OBJDIR)

fclean : clean
	/bin/rm -f $(NAME)

re_lib :
	make re -C libft/

re : fclean re_lib all