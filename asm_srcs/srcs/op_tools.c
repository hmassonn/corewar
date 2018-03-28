/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 16:35:55 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/27 16:37:49 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

int		name_to_op(char *name)
{
	int i;

	i = 0;
	if (!name)
		return (0);
	while (g_op_tab[i].opcode)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (g_op_tab[i].opcode);
		i++;
	}
	return (0);
}

char	*op_to_name(int op)
{
	char	*name;
	int		i;

	i = 0;
	name = NULL;
	while (g_op_tab[i].opcode)
	{
		if (op == g_op_tab[i].opcode)
			name = ft_strdup(g_op_tab[i].name);
		i++;
	}
	i = 0;
	return (name);
}

char	**tabsplit(char *line, char **tab)
{
	char		*cl;

	cl = NULL;
	cl = ft_clean(line);
	cl = ft_cleanseparator(cl);
	tab = ft_strsplit(cl, ' ');
	free(cl);
	return (tab);
}
