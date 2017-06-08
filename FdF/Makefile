# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aren <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/16 04:06:28 by aren              #+#    #+#              #
#    Updated: 2016/03/16 04:06:29 by aren             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LFLAGS	= -L libft/ -lft \
			-L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
SRC_DIR	= ./srcs/
SRC		= main.c mlx.c get_tools.c get_data.c point.c calculs.c \
			ft_move.c ft_option_mov_zoom.c
VPATH	= $(SRC_DIR)
INC		= -I./includes -I./libft/includes
O_DIR	= ./obj
OBJ		= $(addprefix $(O_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	
	@echo "\033[1;31m"
	@echo "_________________________________"
	@echo "|                                |"
	@echo "|  _|_|_|_|  _|_|_|    _|_|_|_|  |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|_|_|    _|    _|  _|_|_|    |"
	@echo "|  _|        _|    _|  _|        |"
	@echo "|  _|        _|_|_|    _|        |"
	@echo "|                                |"
	@echo "|______________________by aren___|"
	@make -C libft
	@echo "Link !"
	@$(CC) -o $(NAME) $^ $(LFLAGS)

$(O_DIR)/%.o: %.c
	@mkdir -p $(O_DIR)
	@printf "\033[1;31m."
	@$(CC) $(CFLAGS) -I ./includes -o $@ -c $<

clean:
	@echo "\033[1;34mDeleting FdF .o files."
	@rm -f $(OBJ)
	@rm -rf obj

fclean: clean
	@echo "\033[1;34mDeleting fdf."
	@rm -f $(NAME)
	@rm -rf obj
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
