# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:56:27 by hmassonn          #+#    #+#              #
#    Updated: 2017/02/27 16:37:35 by hmassonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asm

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC_PATH = ./includes/ ./libft/includes
OBJ_PATH = ./obj/
LIB_PATH = ./libft/
SRC_PATH = ./srcs/
SRC_NAME =	asm.c			\
			op.c			\
			init.c			\
			take.c			\
			inst.c 			\
			debug.c 		\
			tools.c			\
			verif.c 		\
			calc.c 			\
			clean.c 		\
			fill_file.c 	\
			print.c			\
			verif_tools.c	\
			print_label.c	\
			get_line.c		\
			op_tools.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I, $(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB_NAME = /libft.a
LIB_FILE = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[34m[  LIBRAIRIES  ]\033[0m"
	@make -C $(LIB_PATH)
	@echo "\033[34m[ MAIN PROJECT ]\033[0m"
	@echo "\033[32m[$(NAME)]\t\t(release)\033[0m"
	@$(CC) $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB_FILE)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -g $(CFLAGS) $(INC) -o $@ -c $<

re: fclean all

follow:
	@rm -rf $(OBJ_PATH)
	@rm -rf $(NAME)

test: follow $(OBJ)
	@$(CC) -g $(CFLAGS) -o $(NAME) $(INC) $(OBJ) $(LIB_FILE)

clean:
	@rm -rf $(OBJ_PATH)
	@(cd $(LIB_PATH) && $(MAKE) $@)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf .DS_Store
	@rm -rf ../.DS_Store
	@rm -rf asm.dSYM
	@rm -f $(LIB_FILE)
	@echo "\n\033[31mWow ! I've clean $(NAME) so much !\033[0m\n"

.PHONY: re clean fclean norme rendu all test follow
