/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:03:56 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:05:51 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long int	ft_get_lld_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	else if (type == 2)
	{
		arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		if (arg >> 31)
			arg -= 0x100000000;
		return (arg);
	}
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[(arg + mars->arena[(cpu->pc + (*n)++)
			% MEM_SIZE]) % MEM_SIZE];
	return (arg);
}

long long int	ft_get_ld_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	else if (type == 2)
	{
		arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		if (arg >> 31)
			arg -= 0x100000000;
		return (arg);
	}
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[((arg + mars->arena[(cpu->pc + (*n)++) % MEM_SIZE])
			% IDX_MOD + cpu->pc) % MEM_SIZE];
	return (arg);
}

t_cpu			*ft_ld(t_mars **mars, t_cpu *cpu, int mod)
{
	long long int	arg1;
	long long int	arg2;
	unsigned char	type;
	int				n;

	n = 1;
	++cpu->pc;
	type = (*mars)->arena[cpu->pc % MEM_SIZE];
	(*mars)->modif = true;
	if (!ft_check_type(type, 0b011, 0b100, 0b000))
		return (cpu);
	if (mod == 0x02)
		arg1 = ft_get_ld_arg(*mars, cpu, type >> 6, &n);
	else
		arg1 = ft_get_lld_arg(*mars, cpu, type >> 6, &n);
	arg2 = ft_get_ld_arg(*mars, cpu, 1, &n);
	if (arg2 > 15)
		return (cpu);
	cpu->reg[arg2] = arg1;
	cpu->carry = cpu->reg[arg2] ? 0 : 1;
	cpu->pc += n;
	return (cpu);
}
