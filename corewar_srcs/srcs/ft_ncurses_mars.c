/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_mars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:15:51 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 15:15:39 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_mars_ncurses_btm(t_mars **mars)
{
	attroff(A_BOLD);
	attroff(COLOR_PAIR((*mars)->last_color));
	if (!((*mars)->opt & 0b1000))
		return ;
	move(68, 20);
	printw("Cycles : ");
	printw("%d", (*mars)->cycle);
	printw("\t\tCycles to die : ");
	printw("%d", (*mars)->cycle_to_die);
	printw("\t\tProcess : ");
	printw("%d", (*mars)->process);
}

void	ft_ncurses_pid_color(t_mars **mars, int pid, char fill)
{
	attroff(COLOR_PAIR((*mars)->last_color));
	attroff(A_BOLD);
	(*mars)->last_color = pid;
	if (pid < 0)
	{
		pid = ft_abs(pid) % 5;
		attron(A_BOLD);
	}
	(*mars)->last_color = pid + 1 + 1 * 4 * fill;
	attron(COLOR_PAIR((*mars)->last_color));
}

void	ft_ncurses_arena(t_mars *mars, char pc[MEM_SIZE])
{
	int		i;
	int		j;
	int		incode;

	j = 0;
	i = -1;
	incode = 0;
	while (++i < MEM_SIZE)
	{
		if (incode && !(incode = mars->arena_color[i]))
		{
			attroff(COLOR_PAIR(mars->last_color));
			attron(COLOR_PAIR(mars->last_color = 1));
		}
		else if ((incode = mars->arena_color[i]))
			ft_ncurses_pid_color(&mars, mars->arena_color[i], pc[i]);
		printw("%02x ", mars->arena[i]);
		if (j == 63 && i != 4095)
			move(i / 63 + 1, 2);
		j == 63 ? j = 0 : j++;
	}
}

void	ft_ncurses_mars(t_mars *mars, t_cpu *cpu)
{
	char	pc[MEM_SIZE];

	ft_bzero(pc, MEM_SIZE);
	while (cpu)
	{
		if (cpu->live >= 0)
			pc[ft_abs(cpu->pc % MEM_SIZE)] = 1;
		cpu = cpu->next;
	}
	move(1, 2);
	ft_ncurses_arena(mars, pc);
	ft_mars_ncurses_btm(&mars);
	refresh();
}
