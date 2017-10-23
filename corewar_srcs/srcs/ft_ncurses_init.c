/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ncurses_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <clanier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:54:53 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:46:51 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <corewar.h>

void	ft_ncurses_init(void)
{
	WINDOW * win;
	initscr();
	win = subwin(stdscr, 66, 196, 0, 0);
	box(win, ACS_VLINE, ACS_HLINE);
	start_color();
	init_color(COLOR_MAGENTA, 700, 700, 700);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
}
