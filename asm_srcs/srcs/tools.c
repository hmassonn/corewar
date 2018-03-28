/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 17:54:48 by basle-qu          #+#    #+#             */
/*   Updated: 2017/02/26 21:15:35 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

char		*ft_clean(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	if ((ret = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)) == NULL)
		exit(0);
	while (str[i])
	{
		if (str[i] == '\t')
			ret[i] = ' ';
		else if (str[i] == COMMENT_CHAR || str[i] == ';')
			ret[i] = '\0';
		else
			ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char		*ft_cleanseparator(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == SEPARATOR_CHAR)
		{
			i--;
			while (str[i] == ' ')
				str[i--] = SEPARATOR_CHAR;
			i++;
			while (str[i] == SEPARATOR_CHAR)
				i++;
			while (str[i] == ' ')
			{
				str[i] = SEPARATOR_CHAR;
				i++;
			}
		}
		else
			i++;
	}
	return (str);
}

void		ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(0);
}

char		**ft_clean_comment(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i] && tab[i][0] == '#')
			tab[i] = NULL;
		i++;
	}
	return (tab);
}

int			label_exist(t_inst *champ, char *label)
{
	int			i;
	t_inst		*tmp;
	char		**split;

	tmp = champ;
	split = ft_strsplit(label, SEPARATOR_CHAR);
	while (tmp)
	{
		i = 0;
		while (split[i])
		{
			if (tmp->label && find_label(tmp->label, split[i]))
			{
				free_tab(split);
				return (1);
			}
			i++;
		}
		tmp = tmp->next;
	}
	free_tab(split);
	return (0);
}
