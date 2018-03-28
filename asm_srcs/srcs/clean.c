/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:03:29 by basle-qu          #+#    #+#             */
/*   Updated: 2017/03/07 15:01:04 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void	free_champ(t_inst **champ)
{
	t_inst	*tmp;
	t_inst	*lst;

	lst = *champ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free_tab(tmp->args);
		tmp->args = NULL;
		if (tmp->label)
		{
			free(tmp->label);
			tmp->label = NULL;
		}
		free(tmp);
		tmp = NULL;
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

char	*ft_joinfree(char *s1, char *s2, int tamere)
{
	size_t	i;
	size_t	j;
	char	*ns;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(ns = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[++i])
		ns[i] = s1[i];
	while (s2[j])
	{
		ns[i + j] = s2[j];
		j++;
	}
	ns[i + j] = '\0';
	if (tamere == 1 || tamere == 3)
		free(s1);
	if (tamere == 2 || tamere == 3)
		free(s2);
	return (ns);
}
