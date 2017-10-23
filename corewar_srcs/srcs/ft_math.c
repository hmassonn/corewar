/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:17:13 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 15:25:22 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

t_cpu	*ft_math(t_mars **mars, t_cpu *cpu, int math)
{
	int	arg1;
	int	arg2;
	int	arg3;

	++cpu->pc;
	(*mars)->modif = true;
	if (!ft_check_type((*mars)->arena[cpu->pc % MEM_SIZE], 0b100, 0b100, 0b100))
		return (cpu);
	arg1 = (*mars)->arena[(cpu->pc + 1) % MEM_SIZE] - 1;
	arg2 = (*mars)->arena[(cpu->pc + 2) % MEM_SIZE] - 1;
	arg3 = (*mars)->arena[(cpu->pc + 3) % MEM_SIZE] - 1;
	if (arg1 > 15 || arg2 > 15 || arg3 > 15 || arg1 < 0 || arg2 < 0 || arg3 < 0)
		return (cpu);
	cpu->reg[arg3] = math == 0x04 ? cpu->reg[arg1] + cpu->reg[arg2]
	: cpu->reg[arg1] - cpu->reg[arg2];
	cpu->carry = cpu->reg[arg3] ? 0 : 1;
	cpu->pc += 4;
	return (cpu);
}
