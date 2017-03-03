/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 18:27:16 by basle-qu          #+#    #+#             */
/*   Updated: 2017/02/27 14:20:51 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

int		find_label(char *list, char *label)
{
	int		i;
	char	**list2;

	i = 0;
	if (!label || !list)
		return (0);
	list2 = ft_strsplit(list, SEPARATOR_CHAR);
	while (list2[i])
	{
		if (!ft_strcmp(list2[i], label))
		{
			free_tab(list2);
			return (1);
		}
		i++;
	}
	free_tab(list2);
	return (0);
}

void	print_direct_char(t_inst *champ, char **args, int i, int fd)
{
	if (g_op_tab[champ->opcode - 1].label_size)
	{
		if (args[i][1] == LABEL_CHAR)
			print_half_int(print_label(champ, &args[i][1]), fd);
		else
			print_half_int(ft_atoi(&args[i][1]), fd);
	}
	else
	{
		if (args[i][1] == LABEL_CHAR)
			print_int(print_label(champ, &args[i][1]), fd);
		else
			print_int(ft_atoi(&args[i][1]), fd);
	}
}

void	print_args(t_inst *champ, char **args, int fd)
{
	int		i;

	i = -1;
	if (!champ->opcode)
		return ;
	while (args[++i])
	{
		if (args[i][0] == LABEL_CHAR)
			print_half_int(print_label(champ, args[i]), fd);
		else if (args[i][0] == '-' || ft_isdigit(args[i][0]))
			print_half_int(ft_atoi(&args[i][0]), fd);
		else if (args[i][0] == 'r')
			ft_putchar_fd(ft_atoi(&args[i][1]), fd);
		else if (args[i][0] == DIRECT_CHAR)
			print_direct_char(champ, args, i, fd);
	}
}

void	print_inst(t_inst *champ, int fd)
{
	t_inst	*tmp;

	tmp = champ;
	while (tmp)
	{
		if (tmp->opcode)
		{
			ft_putchar_fd(tmp->opcode, fd);
			if (g_op_tab[tmp->opcode - 1].octal)
				print_args_value(tmp->args, fd);
			print_args(tmp, tmp->args, fd);
		}
		tmp = tmp->next;
	}
}

void	fill_file(int fd, t_header *head, t_inst *champ)
{
	print_int(head->magic, fd);
	print_progname(head, fd);
	print_int(head->prog_size, fd);
	print_comment(head, fd);
	print_inst(champ, fd);
}
