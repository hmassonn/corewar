/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm2.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 19:56:50 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 17:05:03 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define MAX_ARGS_NUMBER 4
# define MAX_PLAYERS 4
# define MEM_SIZE (4*1024)
# define IDX_MOD (MEM_SIZE / 8)
# define CHAMP_MAX_SIZE (MEM_SIZE / 6)
# define REG_NUMBER 16
# define CYCLE_TO_DIE 1536
# define CYCLE_DELTA 50
# define NBR_LIVE 21
# define MAX_CHECKS 10
# define PROG_NAME_LENGTH (128)
# define COMMENT_LENGTH (1024)
# define COREWAR_EXEC_MAGIC 0xea83f3

# define X_MAP 833
# define Y_MAP 833
# define X_WIN (X_MAP + 300)
# define Y_WIN Y_MAP

# include "mlx.h"
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <ncurses.h>
# include "inc/fmod.h"
# include <OpenGL/gl3.h>

typedef struct			s_cpu
{
	char				name[128];
	char				comment[1024];
	unsigned int		reg[REG_NUMBER];
	int					pc;
	int					carry;
	int					cycle_wait;
	int					size;
	unsigned char		*code;
	int					live;
	unsigned int		uid;
	unsigned char		color;
	struct s_cpu		*next;
}						t_cpu;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					sl;
	int					info_sl;
}						t_mlx;

typedef struct			s_sound
{
	FMOD_SYSTEM			*system;
	FMOD_CHANNELGROUP	*channelgroup;
	FMOD_SOUND			*sound;
}						t_sound;

typedef struct			s_mars
{
	int					dump;
	short int			arena_color[MEM_SIZE];
	int					cycle;
	int					cycle_to_die;
	unsigned int		last_live;
	int					live_check;
	int					last_live_check;
	int					last_flush;
	bool				modif;
	unsigned char		arena[MEM_SIZE];
	char				fat_buf[90000];
	int					fat_buf_len;
	int					ifb;
	char				opt;
	int					process;
	char				nb_players;
	unsigned int		players[4];
	unsigned int		total_size;
	char				last_color;
	t_mlx				*mlx;
	t_sound				*sound;
}						t_mars;

void					ft_ncurses_init(void);
void					ft_music_load(t_mars **mars, t_cpu *cpu);
void					ft_flush(t_mars *mars);
void					ft_addbuf(t_mars **pmars, char *str);
int						ft_nbrlen_base(unsigned int n, int base);
void					ft_addbuf_nbr(t_mars **mars,
						unsigned int nbr, int base);
int						ft_get_code_size(int fd);
int						ft_get_cpu_info(int fd, t_cpu *cpu);
t_cpu					*ft_new_cpu(int fd, int uid, int color);
void					ft_del_cpu(t_cpu **cpu);
int						ft_cpu_addfront(t_cpu **cpu,
						int fd, int color, int uid);
void					ft_display_mars(t_mars **mars, t_cpu *cpu);
void					ft_draw_case(t_mars *mars, int y, int x, int color);
int						ft_get_color(int arena_color);
void					ft_draw_mars(t_mars **mars, t_cpu *cpu);
void					ft_draw_info(t_mars **mars);
void					ft_refresh_mars(t_mars **mars, t_cpu *cpu);
void					ft_dump_memory(unsigned char *arena);
void					ft_draw_skull_head(t_mars *mars);
void					ft_print_winner(t_mars *mars, t_cpu *cpu);
t_cpu					*ft_new_cpucpy(t_cpu *src, int address);
void					ft_cpu_cpyfront(t_cpu **cpu, t_cpu *src, int address);
t_cpu					*ft_fork(t_mars **mars, t_cpu *cpu,
						int *new_address, int mod);
void					ft_draw_pixel(t_mars *mars, int y, int x, int color);
void					ft_new_image(t_mars *mars);
void					ft_draw_grid(t_mars *mars);
void					ft_mlx_init(t_mars *mars);
void					ft_mlx_exit(t_mars *mars);
long long int			ft_get_lld_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
long long int			ft_get_ld_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
t_cpu					*ft_ld(t_mars **mars, t_cpu *cpu, int mod);
long long int			ft_get_lldi_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
long long int			ft_get_ldi_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
unsigned int			ft_load_regsize(t_mars *mars, int address);
int						ft_check_ld_reg(t_cpu *cpu, char type,
						long long int *arg1, long long int *arg2);
t_cpu					*ft_ldi(t_mars **mars, t_cpu *cpu, int mod);
t_cpu					*ft_live(t_mars **mars, t_cpu *cpu);
t_cpu					*ft_aff(t_mars **mars, t_cpu *cpu);
int						ft_get_gap(t_cpu *cpu);
void					ft_fill_arena(t_mars *mars, t_cpu **cpu);
void					ft_get_players_uid(t_mars *mars, t_cpu *cpu);
t_mars					*ft_new_mars(t_cpu **cpu, char opt, int dump);
void					ft_del_mars(t_mars *mars);
t_cpu					*ft_math(t_mars **mars, t_cpu *cpu, int math);
long long int			ft_get_op_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
int						ft_check_op_reg(t_cpu *cpu, char type,
						long long int *arg1, long long int *arg2);
t_cpu					*ft_binary_op(t_mars **mars, t_cpu *cpu, char op);
void					ft_mars_top_pipe(t_mars **mars);
void					ft_mars_btm_pipe(t_mars **mars);
void					ft_print_pid_color(t_mars **mars, int pid, char fill);
void					ft_print_mars(t_mars **mars, t_cpu *cpu);
t_cpu					*ft_get_cycle_wait(t_cpu *cpu, unsigned char opcode);
t_cpu					*ft_get_opcode(t_mars **mars, t_cpu *cpu, int opcode);
void					ft_run_cpu(t_mars **mars, t_cpu **cpu);
int						ft_kill_cpu(t_mars **mars, t_cpu **cpu);
void					ft_run_mars(t_mars *mars, t_cpu *cpu);
void					ft_draw_case_line(t_mars *mars, int x1, int x2, int y);
void					ft_draw_skull_1(t_mars *mars);
void					ft_draw_skull_2(t_mars *mars);
void					ft_draw_skull_3(t_mars *mars);
void					ft_draw_skull_4(t_mars *mars);
void					ft_reset_line(t_mars *mars, int y);
void					ft_reset_top_grid(t_mars *mars);
void					ft_reset_btm_grid(t_mars *mars);
long long int			ft_get_st_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
t_cpu					*ft_st(t_mars **mars, t_cpu *cpu);
long long int			ft_get_sti_arg(t_mars *mars,
						t_cpu *cpu, int type, int *n);
void					ft_abs_mars_color(t_mars **mars);
void					ft_print_on_mars(t_mars **pmars,
						unsigned int value, int address, int uid);
int						ft_check_type(unsigned char type,
						char a1, char a2, char a3);
t_cpu					*ft_sti(t_mars **mars, t_cpu *cpu);
void					ft_helper(void);
int						ft_bad_usage(t_cpu **cpu, int ac);
int						ft_player_error(t_cpu **cpu, char *name, int fd);
t_cpu					*ft_zjmp(t_mars **mars, t_cpu *cpu);
void					ft_get_player_index(char **av, int *i, int *j);
int						ft_get_players(char **av, t_cpu **cpu);
void					ft_parse_opt(char **av, int i, int j, char *opt);
void					ft_get_opt(char *opt, int *dump, char **av, int ac);
void					ft_mars_ncurses_btm(t_mars **mars);
void					ft_ncurses_pid_color(t_mars **mars, int pid, char fill);
void					ft_ncurses_mars(t_mars *mars, t_cpu *cpu);

#endif
