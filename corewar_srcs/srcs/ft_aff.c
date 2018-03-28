/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:17:13 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 16:29:28 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cpu	*ft_aff(t_mars **mars, t_cpu *cpu)
{
	int	arg1;

	++cpu->pc;
	(*mars)->modif = true;
	if (!ft_check_type((*mars)->arena[cpu->pc % MEM_SIZE], 0b100, 0b000, 0b000))
		return (cpu);
	arg1 = (*mars)->arena[(cpu->pc + 1) % MEM_SIZE] - 1;
	if (arg1 > 15 || arg1 < 0)
		return (cpu);
	if (!((*mars)->opt & 0b00100000))
		ft_putchar(cpu->reg[arg1] % 256);
	cpu->pc += 2;
	return (cpu);
}
