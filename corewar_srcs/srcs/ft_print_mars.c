/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_mars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:08:38 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 15:15:58 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_mars_top_pipe(t_mars **mars)
{
	ft_addbuf(mars, "\033[1m╔═══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════════════════╗\n║ \033[30m");
}

void	ft_mars_btm_pipe(t_mars **mars)
{
	ft_addbuf(mars, "\033[0m\033[1m║\n╚═══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════");
	ft_addbuf(mars, "══════════════════════════════════════════╝\n\n");
	if (!((*mars)->opt & 0b1000))
		return ;
	ft_addbuf(mars, "\t\tCycles : ");
	ft_addbuf_nbr(mars, (*mars)->cycle, 10);
	ft_addbuf(mars, "\t\tCycles to die : ");
	ft_addbuf_nbr(mars, (*mars)->cycle_to_die, 10);
	ft_addbuf(mars, "\t\tProcess : ");
	ft_addbuf_nbr(mars, (*mars)->process, 10);
	ft_addbuf(mars, "\033[0m\n");
}

void	ft_print_pid_color(t_mars **mars, int pid, char fill)
{
	ft_addbuf(mars, "\033[0m");
	if (pid < 0)
	{
		pid = ft_abs(pid) % 5;
		ft_addbuf(mars, "\033[1m");
	}
	if (pid == 1)
		ft_addbuf(mars, fill ? "\033[42m" : "\033[32m");
	else if (pid == 2)
		ft_addbuf(mars, fill ? "\033[44m" : "\033[34m");
	else if (pid == 3)
		ft_addbuf(mars, fill ? "\033[41m" : "\033[31m");
	else
		ft_addbuf(mars, fill ? "\033[46m" : "\033[36m");
}

void	ft_print_arena(t_mars **mars, char pc[MEM_SIZE])
{
	int		i;
	int		j;
	int		incode;

	j = 0;
	i = -1;
	incode = 0;
	while (++i < MEM_SIZE)
	{
		if (incode && !(incode = (*mars)->arena_color[i]))
			ft_addbuf(mars, "\033[0;1;30m");
		else if ((incode = (*mars)->arena_color[i]))
			ft_print_pid_color(mars, (*mars)->arena_color[i], pc[i]);
		ft_addbuf_nbr(mars, (*mars)->arena[i], 16);
		if (j == 63 && i != MEM_SIZE - 1)
			ft_addbuf(mars, "\033[0;1m║\n║ \033[30m");
		j == 63 ? j = 0 : j++;
	}
}

void	ft_print_mars(t_mars **mars, t_cpu *cpu)
{
	int		len;
	char	pc[MEM_SIZE];

	ft_bzero(pc, MEM_SIZE);
	while (cpu)
	{
		if (cpu->live >= 0)
			pc[ft_abs(cpu->pc % MEM_SIZE)] = 1;
		cpu = cpu->next;
	}
	(*mars)->ifb = 0;
	ft_mars_top_pipe(mars);
	ft_print_arena(mars, pc);
	ft_mars_btm_pipe(mars);
	len = ft_strlen((*mars)->fat_buf);
	system("clear");
	write(1, (*mars)->fat_buf, len);
}
