/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <zaz@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2017/03/07 15:00:28 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# define NAMELEN				ft_strlen(NAME_CMD_STRING)
# define COMMENTLEN				ft_strlen(COMMENT_CMD_STRING)

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

# define COMMENT_CHAR			'#'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10

typedef char	t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

typedef struct			s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}						t_header;

typedef struct			s_intmain
{
	int					fd;
	int					i;
	int					opt;
}						t_intmain;

typedef struct			s_op
{
	char				*name;
	int					nb_arguments;
	int					arguments[3];
	int					opcode;
	int					cycles;
	char				*describe;
	int					octal;
	int					label_size;
}						t_op;

typedef struct			s_instruct
{
	int					opcode;
	char				**args;
	char				*label;
	struct s_instruct	*prev;
	struct s_instruct	*next;
}						t_inst;

/*
** in take.c
*/

void					take_name(char **line, t_header *head, int fd, int raz);
void					take_comment(char **line,
	t_header *head, int fd, int raz);

/*
** in init.c
*/

char					*s_to_cor(char *str);
void					init_header(t_header **head);

/*
** in tools.c
*/

void					ft_error(char *str);
char					*ft_clean(char *str);
char					*ft_cleanseparator(char *str);
char					**ft_clean_comment(char **tab);
int						label_exist(t_inst *champ, char *label);

/*
** in verif.c
*/

int						verif_params(char *name, char **param);

/*
** in verif_tools.c
*/

int						verif_name_label(char *label);
int						verif_name_instruct(char *name);
void					check_t(int *t, char *name);
void					check_label_ind(int t, int npara, char **para);

/*
** in debug.c
*/

void					print_header(t_header *head);
void					print_champ(t_inst *champ);

/*
** in inst.c
*/

t_inst					*fill_champ(char *line, t_inst *champ, int ret);

/*
** in op_tools.c
*/

int						name_to_op(char *name);
char					*op_to_name(int op);
char					**tabsplit(char *line, char **tab);

/*
** in calc.c
*/

int						calc_prog_size(t_inst *champ);
int						calc_args_size(t_inst *one);
int						size_arg(int opcode, char *arg);
int						arg_binary(char *name);

/*
** in clean.c
*/

void					free_tab(char **tab);
void					free_champ(t_inst **champ);
char					*ft_joinfree(char *s1, char *s2, int tamere);

/*
** in fill_file.c
*/

int						find_label(char *list, char *label);
void					fill_file(int fd, t_header *head, t_inst *champ);

/*
** in print.c
*/

void					print_int(unsigned int nb, int fd);
void					print_half_int(unsigned int nb, int fd);
void					print_progname(t_header *head, int fd);
void					print_comment(t_header *head, int fd);
void					print_args_value(char **args, int fd);

/*
** in print_label.c
*/

int						calc_top_label(t_inst *tmp, char *newlab);
int						calc_down_label(t_inst *tmp, char *newlab);
int						print_label(t_inst *champ, char *label);

/*
** in get_line.c
*/

int						check_line(char *line);
void					get_line(int fd, t_inst **champ, t_header *head);

#endif
