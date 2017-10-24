NAME		=	corewar
SHEL		=	/bin/bash

LIBFT_DIR	=	libft/
LINUX_DIR	=	linux_srcs/
MAC_DIR		=	mac_srcs/

.PHONY : all clean

all : linux

linux :
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(LINUX_DIR)
	@cp $(addprefix $(LINUX_DIR), $(NAME)) ./

mac :
	@make --no-print-directory -C $(LIBFT_DIR)
	@make --no-print-directory -C $(MAC_DIR)
	@cp $(addprefix $(MAC_DIR), $(NAME)) ./

clean :
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@make clean --no-print-directory -C $(LINUX_DIR)
	@make clean --no-print-directory -C $(MAC_DIR)

fclean :
	@rm -rf $(NAME)
	@make fclean --no-print-directory -C $(LIBFT_DIR)
	@make fclean --no-print-directory -C $(LINUX_DIR)
	@make fclean --no-print-directory -C $(MAC_DIR)

re : fclean all
