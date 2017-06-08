# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aren <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:19:00 by aren              #+#    #+#              #
#    Updated: 2015/12/20 16:19:05 by aren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_DIR	= ./srcs/
SRC		= 	main.c swap.c push.c rotate.c reverse.c tools.c tools2.c \
			tools_lst.c error.c error2.c particular.c
VPATH	= $(SRC_DIR)
INC		= -I./includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	
	@echo "\033[1;31m"
	@echo "_________________________________________________________________________________________"
	@echo "|                                                                                        |"
	@echo "|  _|_|_|_|  _|    _|  _|_|_|_|  _|    _|     _|_|_|_|  _|       |_    _|_     _|_|_|_|  |"
	@echo "|  _|   |_|  _|    _|  _|        _|    _|     _|        _|       |_   _| |_    _|   |_|  |"
	@echo "|  _|_|_|_|  _|    _|  _|_|_|_|  _|_|_ _|     _|_|_|_|  _|  _|_  |_  _|_ _|_   _|_|_|_|  |"
	@echo "|  _|        _|    _|        _|  _|    _|           _|   _|_| |_|_  _|     |_  _|        |"
	@echo "|  _|        _|_|_|_|  _|_|_|_|  _|    _|     _|_|_|_|    |     |   _|     |_  _|        |"
	@echo "|                                                                                        |"
	@echo "|______________________________________________________________________________by aren___|"
	@echo "-> Creating $(NAME)..."
	@echo "\033[1;34mOk !"
	@$(CC) -o $(NAME) $^
	
$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "\033[1;31m."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "\033[1;34mDeleting .o files."
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@echo "\033[1;34mDeleting Push_swap."
	@rm -f $(NAME)
	@rm -rf obj

re: fclean all

.PHONY: all clean fclean re
