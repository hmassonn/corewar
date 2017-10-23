NAME			=	corewar
SHEL			=	/bin/bash

CC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror -arch x86_64

LIBFT_DIR		=	libft/
LIBFT			=	libft.a
SRCS_DIR		=	srcs/
SRCS_LIST		=	main.c \
					ft_addbuf.c \
					ft_cpu_funcs.c \
					ft_display_mars.c \
					ft_draw_mars.c \
					ft_dump.c \
					ft_exit.c \
					ft_fork.c \
					ft_graph_funcs.c \
					ft_ld.c \
					ft_ldi.c \
					ft_live.c \
					ft_mars_funcs.c \
					ft_math.c \
					ft_ncurses_mars.c \
					ft_op.c \
					ft_print_mars.c \
					ft_run_mars.c \
					ft_skull_draw.c \
					ft_skull_reset.c \
					ft_st.c \
					ft_sti.c \
					ft_usage.c \
					ft_music_load.c \
					ft_zjmp.c \
					ft_ncurses_init.c
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))
OBJS_DIR		=	objs/
OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))
HEADERS			=	-I libft/includes -I includes -I mlx_linux -I fmod/api
LIB_FMOD_NAME	=	libfmodex.dylib
LIB_FMOD_DIR	=	fmod/api/lib/
LIB_FMOD		=	$(addprefix $(LIB_FMOD_DIR), $(LIB_FMOD_NAME))
LIBS			=	-framework OpenGL -framework AppKit -lncurses -L libft -lft -L mlx -lmlx
MLX_DIR			=	mlx/

.PHONY : all clean

all : $(NAME)

$(NAME) : $(OBJS)
	@make --no-print-directory -C $(MLX_DIR)
	@make --no-print-directory -C $(LIBFT_DIR)
	@echo "\033[37mLinking...\033[0m"
	@$(CC) $(CFLAGS) $^ $(LIBS) -o $@ $(LIB_FMOD)
	@install_name_tool -change ./$(LIB_FMOD_NAME) $(LIB_FMOD) $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
	@echo "\033[34mCompilation of \033[36m$(notdir $<)\033[34m done.\033[0m"

norme :
	@norminette $(SRCS)

clean :
	@rm -rf $(OBJS_DIR)
	@make clean --no-print-directory -C $(LIBFT_DIR)
	@echo "\033[31mObjects files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

clean_mlx :
	@make clean --no-print-directory -C $(MLX_DIR)

fclean : clean
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@rm -rf $(addprefix $(LIBFT_DIR), $(LIBFT))
	@echo "\033[31mBin \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re : fclean all
