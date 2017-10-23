COREWAR_NAME	=	corewar
ASM_NAME		=	asm
SHEL			=	/bin/bash

LIBFT_DIR		=	libft/
COREWAR_DIR		=	corewar_srcs/
ASM_DIR			=	asm_srcs/

.PHONY : all clean norme fclean re

all :
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(COREWAR_DIR)
	@cp $(addprefix $(COREWAR_DIR), $(COREWAR_NAME)) ./
	@make --no-print-directory -C $(ASM_DIR)
	@cp $(addprefix $(ASM_DIR), $(ASM_NAME)) ./

norme :
	@make norme --no-print-directory -C $(LIBFT_DIR)
	@make norme --no-print-directory -C $(COREWAR_DIR)
	@make norme --no-print-directory -C $(ASM_DIR)

clean :
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@make clean --no-print-directory -C $(COREWAR_DIR)
	@make clean --no-print-directory -C $(ASM_DIR)

fclean :
	@rm -rf $(COREWAR_NAME)
	@rm -rf $(ASM_NAME)
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@make fclean --no-print-directory -C $(COREWAR_DIR)
	@make fclean --no-print-directory -C $(ASM_DIR)

re : fclean all
