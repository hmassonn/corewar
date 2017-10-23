/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:06:13 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/07 15:21:58 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long int		ft_get_st_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	if (arg >> 15)
		arg -= 0x10000;
	return (arg);
}

t_cpu				*ft_st(t_mars **mars, t_cpu *cpu)
{
	int					arg1;
	long long int		arg2;
	unsigned char		type;
	int					n;

	n = 1;
	++cpu->pc;
	type = (*mars)->arena[cpu->pc % MEM_SIZE];
	(*mars)->modif = true;
	if (!ft_check_type(type, 0b100, 0b101, 0b000))
		return (cpu);
	arg1 = ft_get_st_arg(*mars, cpu, 1, &n);
	arg2 = ft_get_st_arg(*mars, cpu, type >> 4 & 0b11, &n);
	if (arg1 > 15 || arg1 < 0 || ((type >> 4 & 0b11) == 1
	&& (arg2 > 15 || arg2 < 0)))
		return (cpu);
	else if ((type >> 4 & 0b11) == 1)
		cpu->reg[arg2] = cpu->reg[arg1];
	else
	{
		ft_print_on_mars(mars, cpu->reg[arg1],
		(cpu->pc - 1) + (arg2 % IDX_MOD), cpu->color);
	}
	cpu->pc += n;
	return (cpu);
}
