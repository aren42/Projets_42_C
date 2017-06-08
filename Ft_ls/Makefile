# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aren <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:19:00 by aren              #+#    #+#              #
#    Updated: 2016/01/28 05:08:48 by aren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft
SRC_DIR	= ./srcs/
SRC		= main.c ft_permissions.c ft_tools_dir.c ft_tools_lst.c ft_tools_opt.c \
	ft_file_infos.c ft_get_infos.c ft_display.c ft_display_opt.c ft_tools_opt2.c
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	
	@echo "\033[1;31m"
	@echo "_________________________________"
	@echo "|                                |"
	@echo "|                                |"
	@echo "|                                |"
	@echo "|           F T _ L S            |"
	@echo "|                                |"
	@echo "|                                |"
	@echo "|______________________by aren___|"
	@make -C libft
	@echo "Link !"
	@$(CC) -o $(NAME) $^ $(LFLAGS)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "\033[1;31m."
	@$(CC) $(CFLAGS) -c $< -I ./includes -o $@

clean:
	@echo "\033[1;34mDeleting Ft_ls .o files."
	@make -C libft/ clean
	@rm -rf $(OBJ)
	@/bin/rm -rf obj

fclean: clean
	@echo "\033[1;34mDeleting Ft_ls."
	@rm -rf $(NAME) $(OBJ)
	@make fclean -C libft
	@/bin/rm -rf obj

re: fclean all

.PHONY: all clean fclean re
