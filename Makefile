# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/06 18:50:06 by hmassonn          #+#    #+#              #
#    Updated: 2017/03/06 19:05:27 by hmassonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ASM_DIR		=	asm/
VM_DIR		=	vm/

all :
	make -C $(ASM_DIR)
	make -C $(VM_DIR) mac

clean :
	@make clean -C $(ASM_DIR)
	@make clean -C $(VM_DIR)

fclean :
	@make fclean -C $(ASM_DIR)
	@make fclean -C $(VM_DIR)

re : fclean all

.PHONY : all clean asm vm
