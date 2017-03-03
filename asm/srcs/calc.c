/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 20:55:33 by basle-qu          #+#    #+#             */
/*   Updated: 2017/02/26 18:24:14 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

int		size_arg(int opcode, char *arg)
{
	if (ft_isdigit(arg[0]) || arg[0] == '-' || arg[0] == LABEL_CHAR)
		return (2);
	else if (arg[0] == 'r')
		return (1);
	else if (arg[0] == DIRECT_CHAR)
	{
		if (g_op_tab[opcode - 1].label_size == 0)
			return (4);
		else
			return (2);
	}
	return (0);
}

int		calc_args_size(t_inst *one)
{
	int i;
	int size;

	i = 0;
	size = 0;
	if (!one->opcode)
		return (0);
	while (one->args[i])
	{
		size = size + size_arg(one->opcode, one->args[i]);
		i++;
	}
	return (size);
}

int		calc_prog_size(t_inst *champ)
{
	t_inst	*tmp;
	int		size;

	tmp = champ;
	size = 0;
	while (tmp)
	{
		if (!tmp->args)
			break ;
		size += 1 + calc_args_size(tmp);
		if (g_op_tab[tmp->opcode - 1].octal == 1)
			size++;
		tmp = tmp->next;
	}
	return (size);
}

int		arg_binary(char *name)
{
	if (!name)
		return (0);
	if (ft_isdigit(name[0]) || name[0] == '-' || name[0] == LABEL_CHAR)
		return (3);
	else if (name[0] == DIRECT_CHAR)
		return (2);
	else if (name[0] == 'r')
		return (1);
	return (0);
}
