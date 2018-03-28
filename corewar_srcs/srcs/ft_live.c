/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:07:53 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 15:44:55 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cpu	*ft_live(t_mars **mars, t_cpu *cpu)
{
	unsigned int	uid;
	int				i;

	uid = 0;
	i = 0;
	while (i++ < 4)
	{
		uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
		uid <<= i != 4 ? 8 : 0;
	}
	++cpu->pc;
	i = 0;
	while (i < (*mars)->nb_players)
	{
		if ((*mars)->players[i++] == uid)
		{
			if (!((*mars)->opt & 0b00100000))
				ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
						cpu->color, cpu->name);
			(*mars)->last_live = uid;
		}
	}
	(*mars)->modif = true;
	++cpu->live;
	return (cpu);
}
