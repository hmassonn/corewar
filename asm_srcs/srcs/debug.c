/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 20:51:10 by basle-qu          #+#    #+#             */
/*   Updated: 2017/02/26 17:53:05 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

void	print_header(t_header *head)
{
	ft_putendl("\033[1;31mHEADER");
	ft_putendl("----------\033[00m");
	ft_putstr("Name: ");
	ft_putendl(head->prog_name);
	ft_putstr("Comment: ");
	ft_putendl(head->comment);
	ft_putendl("");
}

void	print_instruct(t_inst *tmp)
{
	char	*name;
	int		i;

	ft_putstr("instruct: ");
	ft_putstr((name = op_to_name(tmp->opcode)));
	free(name);
	i = 0;
	while (tmp->args[i])
	{
		ft_putchar(' ');
		ft_putstr(tmp->args[i]);
		i++;
	}
	ft_putchar('\n');
}

void	print_label_opcode(t_inst *tmp)
{
	if (tmp->label)
	{
		ft_putstr("label:   ");
		ft_putendl(tmp->label);
	}
	ft_putstr("opcode:   ");
	ft_putnbr(tmp->opcode);
	ft_putchar('\n');
	print_instruct(tmp);
}

void	print_champ(t_inst *champ)
{
	int		size;
	int		global_size;
	t_inst	*tmp;

	tmp = champ;
	global_size = 0;
	ft_putendl("\033[1;31mCHAMP");
	ft_putendl("----------\033[00m");
	while (tmp)
	{
		ft_putchar('(');
		ft_putnbr(global_size);
		ft_putendl(")     :");
		size = 0;
		print_label_opcode(tmp);
		size += 1 + calc_args_size(tmp);
		if (g_op_tab[tmp->opcode - 1].octal == 1)
			size++;
		ft_putstr("line size:  ");
		ft_putnbr(size);
		ft_putendl("");
		ft_putendl("-------------");
		global_size += size;
		tmp = tmp->next;
	}
}
