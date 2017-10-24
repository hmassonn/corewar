/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:28:51 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 17:28:51 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_draw_skull_head(t_mars *mars)
{
	if (mars->last_live == 1)
		mars->last_live = 0x00ff00;
	else if (mars->last_live == 2)
		mars->last_live = 0x0000ff;
	else if (mars->last_live == 3)
		mars->last_live = 0xff0000;
	else
		mars->last_live = 0xff00ff;
	ft_reset_top_grid(mars);
	ft_draw_skull_1(mars);
	ft_draw_skull_2(mars);
	ft_draw_skull_3(mars);
	ft_draw_skull_4(mars);
	ft_reset_btm_grid(mars);
	ft_draw_info(&mars);
	sleep(10);
}

void	ft_print_winner(t_mars *mars, t_cpu *cpu)
{
	t_cpu	*lst;

	mars->process = 0;
	if ((mars->opt & 0b1))
		ft_display_mars(&mars, cpu);
	lst = cpu;
	while (lst)
	{
		if (lst->uid == mars->last_live)
		{
			mars->last_live = lst->color;
			ft_printf("le joueur %d(%s) a gagne\n",
			lst->color, lst->name);
			break ;
		}
		lst = lst->next;
	}
	if (mars->opt & 0b10)
		ft_draw_skull_head(mars);
}
