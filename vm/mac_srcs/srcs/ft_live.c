/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 17:11:15 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 18:38:58 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void	ft_print_one_line(t_cpu *cpu)
{
	ft_printf("un processus dit que le joueur %d(%s) est en vie\n",
	cpu->color, cpu->name);
}

t_cpu		*ft_live(t_mars **mars, t_cpu *cpu)
{
	unsigned int	uid;
	int				i;

	uid = 0;
	uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
	uid <<= 8;
	uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
	uid <<= 8;
	uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
	uid <<= 8;
	uid |= (*mars)->arena[++cpu->pc % MEM_SIZE];
	++cpu->pc;
	i = 0;
	while (i < 4)
	{
		if ((*mars)->players[i++] == uid)
		{
			if (!((*mars)->opt & 0b00100000))
				ft_print_one_line(cpu);
			(*mars)->last_live = uid;
		}
	}
	(*mars)->modif = true;
	++cpu->live;
	return (cpu);
}
