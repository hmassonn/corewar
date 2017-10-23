/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 12:06:13 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 12:07:33 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

long long int	ft_get_lldi_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	else if (type == 2)
	{
		arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		return (arg);
	}
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	return (mars->arena[arg % MEM_SIZE]);
}

long long int	ft_get_ldi_arg(t_mars *mars, t_cpu *cpu, int type, int *n)
{
	long long int	arg;

	if (type == 1)
		return (mars->arena[(cpu->pc + (*n)++) % MEM_SIZE] - 1);
	else if (type == 2)
	{
		arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		arg <<= 8;
		arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
		if (arg >> 15)
			arg -= 0x10000;
		return (arg);
	}
	arg = mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	arg <<= 8;
	arg += mars->arena[(cpu->pc + (*n)++) % MEM_SIZE];
	return (mars->arena[(cpu->pc + arg % IDX_MOD) % MEM_SIZE]);
}

unsigned int	ft_load_regsize(t_mars *mars, int address)
{
	unsigned int	value;

	value = mars->arena[address % MEM_SIZE];
	value <<= 8;
	value += mars->arena[(address + 1) % MEM_SIZE];
	value <<= 8;
	value += mars->arena[(address + 2) % MEM_SIZE];
	value <<= 8;
	value += mars->arena[(address + 3) % MEM_SIZE];
	return (value);
}

int				ft_check_ld_reg(t_cpu *cpu, char type,
				long long int *arg1, long long int *arg2)
{
	if (type >> 6 == 1 && *arg1 > 15)
		return (0);
	else if (type >> 6 == 1)
		*arg1 = cpu->reg[*arg1];
	if ((type >> 4 & 0b11) == 1 && *arg2 > 15)
		return (0);
	else if ((type >> 4 & 0b11) == 1)
		*arg2 = cpu->reg[*arg2];
	return (1);
}

t_cpu			*ft_ldi(t_mars **mars, t_cpu *cpu, int mod)
{
	long long int	arg1;
	long long int	arg2;
	long long int	arg3;
	unsigned char	type;
	int				n;

	type = (*mars)->arena[++cpu->pc % MEM_SIZE];
	(*mars)->modif = true;
	if ((n = 1) && !ft_check_type(type, 0b111, 0b110, 0b100))
		return (cpu);
	if (mod == 0x0e)
		arg1 = ft_get_lldi_arg(*mars, cpu, type >> 6, &n);
	else
		arg1 = ft_get_ldi_arg(*mars, cpu, type >> 6, &n);
	if (mod == 0x0e)
		arg2 = ft_get_lldi_arg(*mars, cpu, type >> 4 & 0b11, &n);
	else
		arg2 = ft_get_ldi_arg(*mars, cpu, type >> 4 & 0b11, &n);
	arg3 = ft_get_ldi_arg(*mars, cpu, 1, &n);
	if (!ft_check_ld_reg(cpu, type, &arg1, &arg2) || arg3 > 15)
		return (cpu);
	cpu->reg[arg3] = ft_load_regsize(*mars, (cpu->pc - 1) + arg1 + arg2);
	cpu->carry = cpu->reg[arg3] ? 0 : 1;
	cpu->pc += n;
	return (cpu);
}
