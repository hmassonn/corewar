/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 16:56:50 by hmassonn          #+#    #+#             */
/*   Updated: 2017/03/06 21:50:56 by hmassonn         ###   ########.fr       */
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

static void			ft_put_print(t_mars **mars,
	t_cpu *cpu, int arg1, long long int arg2)
{
	ft_printf("%02x %02x %02x %02x %02x\n",
	(*mars)->arena[(cpu->pc - 1) % MEM_SIZE],
	(*mars)->arena[cpu->pc % MEM_SIZE],
	(*mars)->arena[(cpu->pc + 1) % MEM_SIZE],
	(*mars)->arena[(cpu->pc + 2) % MEM_SIZE],
	(*mars)->arena[(cpu->pc + 3) % MEM_SIZE]);
	ft_printf("st r%d %d\n", arg1 + 1, arg2);
	ft_print_on_mars(mars, cpu->reg[arg1],
		(cpu->pc - 1) + (arg2 % IDX_MOD), cpu->color);
}

t_cpu				*ft_st(t_mars **mars, t_cpu *cpu)
{
	int				arg1;
	long long int	arg2;
	unsigned char	type;
	int				n;

	n = 1;
	++cpu->pc;
	type = (*mars)->arena[cpu->pc % MEM_SIZE];
	(*mars)->modif = true;
	if (!ft_check_type(type, 0b100, 0b101, 0b000))
		return (cpu);
	arg1 = ft_get_st_arg(*mars, cpu, 1, &n);
	arg2 = ft_get_st_arg(*mars, cpu, type >> 4 & 0b11, &n);
	if (arg1 > 15 || ((type >> 4 & 0b11) == 1 && arg2 > 15))
		return (cpu);
	else if ((type >> 4 & 0b11) == 1)
		cpu->reg[arg2] = cpu->reg[arg1];
	else
		ft_put_print(mars, cpu, arg1, arg2);
	cpu->pc += n;
	return (cpu);
}
