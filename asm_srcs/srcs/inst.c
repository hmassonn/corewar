/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:13:38 by basle-qu          #+#    #+#             */
/*   Updated: 2017/03/07 16:13:19 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

extern t_op g_op_tab[];

t_inst	*add_inst(t_inst *champ, char *name, char **args, char *label)
{
	t_inst *new;
	t_inst *tmp;

	if ((new = malloc(sizeof(t_inst))) == NULL)
		exit(0);
	tmp = champ;
	new->opcode = name_to_op(name);
	new->args = args;
	new->label = ft_strdup(label);
	new->next = NULL;
	if (champ == NULL)
	{
		new->prev = NULL;
		return (new);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
	}
	return (champ);
}

char	*fill_lab(char *line, char *lab)
{
	char *ret;
	char *tmp;
	char c[2];

	tmp = NULL;
	ret = NULL;
	c[0] = SEPARATOR_CHAR;
	c[1] = '\0';
	if (!line)
		return (NULL);
	if (lab == NULL)
		ret = ft_strdup(line);
	else
	{
		tmp = ft_strjoin(lab, c);
		free(lab);
		ret = ft_strjoin(tmp, line);
		free(tmp);
	}
	return (ret);
}

t_inst	*with_label(t_inst *champ, char **tab, char **lab)
{
	char	**args;
	char	c[2];

	args = NULL;
	if (verif_name_instruct(tab[1]))
		args = ft_strsplit(tab[2], SEPARATOR_CHAR);
	c[0] = SEPARATOR_CHAR;
	c[1] = '\0';
	if (*lab && !label_exist(champ, tab[0]))
		*lab = ft_joinfree(ft_strjoin(tab[0], c), *lab, 3);
	else if (!label_exist(champ, tab[0]))
		*lab = ft_strdup(tab[0]);
	if (verif_params(tab[1], args))
	{
		champ = add_inst(champ, tab[1], args, *lab);
		free(*lab);
		*lab = NULL;
	}
	return (champ);
}

t_inst	*without_label(t_inst *champ, char **tab, char **lab)
{
	char	**args;

	args = NULL;
	args = ft_strsplit(tab[1], SEPARATOR_CHAR);
	if (verif_params(tab[0], args) && *lab == NULL)
		champ = add_inst(champ, tab[0], args, NULL);
	else if (verif_params(tab[0], args) && *lab != NULL)
	{
		champ = add_inst(champ, tab[0], args, *lab);
		free(*lab);
		*lab = NULL;
	}
	return (champ);
}

t_inst	*fill_champ(char *line, t_inst *champ, int ret)
{
	char		**tab;
	static char	*lab = NULL;

	if (ret == 1)
		return (lab ? add_inst(champ, NULL, NULL, lab) : champ);
	tab = NULL;
	if (!(tab = tabsplit(line, tab)))
		return (champ);
	if (verif_name_label(tab[0]))
	{
		if (label_exist(champ, tab[0]))
			return (champ);
		if (!tab[1])
		{
			lab = fill_lab(tab[0], lab);
			free_tab(tab);
			return (champ);
		}
		champ = with_label(champ, tab, &lab);
	}
	else if (verif_name_instruct(tab[0]))
		champ = without_label(champ, tab, &lab);
	if (tab)
		free_tab(tab);
	return (champ);
}
