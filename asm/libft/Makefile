# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:56:27 by hmassonn          #+#    #+#              #
#    Updated: 2017/01/16 18:36:56 by hmassonn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = -I./includes

STDIO_SRCS_NAME =   ft_printf.c					\
					ft_initprintf.c				\
					ft_convert_p.c				\
					ft_printf_little_options.c	\
					ft_printf_check_flags.c		\
					ft_printf_push_flags.c		\
					ft_printf_pull_str_flags.c	\
					ft_printf_pull_char_flags.c	\
					ft_printf_pull_wstr_flags.c	\
					ft_convert_str.c			\
					ft_convert_nbr.c			\
					ft_convert_other.c			\
					ft_convert_little.c			\
					ft_convert_smaj.c

STDIO_SRCS = $(addprefix stdio/, $(STDIO_SRCS_NAME))

LIBC_SRCS_NAME = ft_memset.c		\
				ft_bzero.c		\
				ft_memcpy.c		\
				ft_memccpy.c	\
				ft_memmove.c	\
				ft_memchr.c		\
				ft_memcmp.c		\
				ft_strlen.c		\
				ft_strdup.c		\
				ft_strcpy.c		\
				ft_strncpy.c	\
				ft_strcat.c 	\
				ft_strncat.c 	\
				ft_strlcat.c 	\
				ft_strchr.c		\
				ft_strrchr.c	\
				ft_strstr.c		\
				ft_strnstr.c	\
				ft_strcmp.c		\
				ft_strncmp.c	\
				ft_atoi.c		\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_toupper.c	\
				ft_tolower.c

LIBC_SRCS = $(addprefix libc/, $(LIBC_SRCS_NAME))

SRC =	$(STDIO_SRCS)	\
		$(LIBC_SRCS)	\
	  ft_memalloc.c ft_memdel.c	ft_itoamax.c ft_puthexamaj.c 			\
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c	\
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c		\
	  ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strsplit.c ft_putchar.c	\
	  ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c ft_putwstr.c	\
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c			\
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c 	\
	  ft_arrnew.c ft_arrprint.c ft_arrdup.c ft_lstlen.c ft_arrdel.c		\
	  ft_sqrt.c ft_strnlen.c get_next_line.c ft_putwchar.c ft_abs.c		\
	  ft_puthexa.c ft_sqrt.c ft_strcpyend.c ft_strextend.c				\
	  ft_strextendend.c ft_putcharnb.c ft_itoa_base.c ft_itoa_basemaj.c	\
	  ft_wstrlen.c ft_uitoamax.c ft_wstrextend.c ft_wstrextendend.c		\
	  ft_wstrcpyend.c ft_strndup.c ft_swap.c ft_arrlen.c ft_swapchar.c	\
	  ft_strintdup.c ft_arrcpy.c ft_strintcpy.c ft_strarrcmp.c

CFLAGS = -Wall -Werror -Wextra -g $(INC)

LO = $(SRC:.c=.o)

$(NAME): $(LO)
	@ar rc $(NAME) $(LO)
	@ranlib $(NAME)
	@echo "\033[33;32mcompilation done"
	@echo "\033[33;37m"

all: $(NAME)

clean:
	@/bin/rm -f $(LO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

test: re
	gcc $(NAME) $(INC) main.c
	./a.out

.PHONY: all clean fclean re test
