#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aren <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/17 16:21:11 by aren              #+#    #+#              #
#    Updated: 2014/12/17 16:21:12 by aren             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC =   ft_strlen.c\
		ft_strdup.c\
		ft_strchr.c\
		ft_memalloc.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strsub.c\
		ft_strjoin.c\

NAME = libft.a

INCLUDE = -I ./includes/

OBJET = ft_strlen.o\
		ft_strdup.o\
		ft_strchr.o\
		ft_memalloc.o\
		ft_strnew.o\
		ft_strdel.o\
		ft_strsub.o\
		ft_strjoin.o\

FLAGS = -Wall -Wextra -Werror $(INCLUDE) -c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC)
	ar rc $(NAME) $(OBJET)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJET)

fclean:
	/bin/rm -f $(NAME) $(OBJET)

re: fclean all
