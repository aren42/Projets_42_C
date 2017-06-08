#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aren <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/07 19:23:39 by aren              #+#    #+#              #
#    Updated: 2014/11/07 19:23:41 by aren             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_DIR	= ./srcs/

SRC = ft_isalpha.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_abs.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_strlen.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strdup.c \
	ft_strcat.c \
	ft_strlcat.c \
	ft_strncat.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strsub.c \
	ft_strnew.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_strsplit.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_bzero.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	get_next_line.c \

VPATH	= $(SRC_DIR)
INC		= -I./includes
O_DIR	= ./obj
OBJ = $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME):$(OBJ)
	@echo "\033[1;31m\nCreating libft library."
	@ar rc $(NAME) $(OBJ)
	@echo "\033[1;31m\nLibrary Ok !"
	@ranlib $(NAME)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "\033[1;34m."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "\033[1;34mDeleting Libft .o files."
	@/bin/rm -rf $(OBJ)
	@/bin/rm -rf obj

fclean: clean
	@echo "\033[1;34mDeleting libft."
	@/bin/rm -rf $(NAME)
	@/bin/rm -rf obj

re: fclean all

.PHONY: all clean fclean re
