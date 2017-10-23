/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 14:19:49 by basle-qu          #+#    #+#             */
/*   Updated: 2017/03/07 15:04:19 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

int		calc_top_label(t_inst *tmp, char *newlab)
{
	int		size;

	size = 4294967295;
	size++;
	tmp = tmp->prev;
	while (tmp)
	{
		size -= (1 + calc_args_size(tmp));
		if (g_op_tab[tmp->opcode - 1].octal)
			size--;
		if (tmp->label && find_label(tmp->label, newlab))
		{
			free(newlab);
			return (size);
		}
		tmp = tmp->prev;
	}
	return (0);
}

int		calc_down_label(t_inst *tmp, char *newlab)
{
	int size;

	size = 0;
	while (tmp)
	{
		if (tmp->label && find_label(tmp->label, newlab))
		{
			free(newlab);
			return (size);
		}
		size += 1 + calc_args_size(tmp);
		if (g_op_tab[tmp->opcode - 1].octal)
			size++;
		tmp = tmp->next;
	}
	return (0);
}

int		print_label(t_inst *champ, char *label)
{
	t_inst		*tmp;
	int			size;
	char		*newlab;
	char		*tmpnl;
	char		c[2];

	tmp = champ;
	c[0] = LABEL_CHAR;
	c[1] = '\0';
	tmpnl = ft_strdup(&label[1]);
	if (label)
		newlab = ft_joinfree(tmpnl, c, 1);
	if (tmp && label && tmp->label && find_label(tmp->label, newlab))
	{
		free(newlab);
		return (0);
	}
	if ((size = calc_top_label(tmp, newlab)) != 0)
		return (size);
	tmp = champ;
	if ((size = calc_down_label(tmp, newlab)) != 0)
		return (size);
	free(newlab);
	return (0);
}
