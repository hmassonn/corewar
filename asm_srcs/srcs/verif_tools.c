/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:39:06 by basle-qu          #+#    #+#             */
/*   Updated: 2017/03/01 16:36:47 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op	g_op_tab[];

int			verif_name_label(char *name)
{
	int			i;
	int			j;
	int			count;
	static char	label[] = LABEL_CHARS;

	i = 0;
	count = 0;
	if (!name)
		return (0);
	while (name[i])
	{
		j = 0;
		while (label[j])
		{
			if (label[j] == name[i])
				count++;
			j++;
		}
		i++;
	}
	if (name[i - 1] != LABEL_CHAR || count < i - 1)
		return (0);
	return (1);
}

int			verif_name_instruct(char *label)
{
	if (label == NULL)
		return (0);
	if (ft_strcmp(label, "live") && ft_strcmp(label, "ld") &&
	ft_strcmp(label, "st") && ft_strcmp(label, "add") &&
	ft_strcmp(label, "sub") && ft_strcmp(label, "and") &&
	ft_strcmp(label, "or") && ft_strcmp(label, "xor") &&
	ft_strcmp(label, "zjmp") && ft_strcmp(label, "ldi") &&
	ft_strcmp(label, "sti") && ft_strcmp(label, "fork") &&
	ft_strcmp(label, "lld") && ft_strcmp(label, "lldi") &&
	ft_strcmp(label, "lfork") && ft_strcmp(label, "aff"))
		ft_error("Bad name instruct");
	return (1);
}

void		check_t(int *t, char *name)
{
	*t = 0;
	if (!name)
		ft_error("bad instruction");
	while (g_op_tab[*t].name && ft_strcmp(g_op_tab[*t].name, name))
		(*t)++;
	if (!g_op_tab[*t].name)
		ft_error("unknow instruction");
}

void		check_label_ind(int t, int npara, char **para)
{
	int			i;
	int			j;
	int			count;
	static char	label[] = LABEL_CHARS;

	i = 1;
	count = 0;
	if ((g_op_tab[t].arguments[npara] & T_IND) != T_IND)
		ft_error("Bad label indirect");
	while (para[npara][i])
	{
		j = 0;
		while (label[j])
		{
			if (label[j] == para[npara][i])
				count++;
			j++;
		}
		i++;
	}
	if (i == 1 || count < i - 1)
		ft_error("Bad label indirect empty");
}
