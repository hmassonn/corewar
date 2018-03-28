/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:21:02 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/26 21:52:50 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

void		init_header(t_header **head)
{
	if ((*head = malloc(sizeof(t_header))) == NULL)
		exit(0);
	(*head)->magic = COREWAR_EXEC_MAGIC;
	ft_bzero((*head)->prog_name, PROG_NAME_LENGTH);
	(*head)->prog_size = 0;
	ft_bzero((*head)->comment, COMMENT_LENGTH);
}

char		*s_to_cor(char *str)
{
	int		i;
	char	*new;

	if ((new = (char*)malloc(sizeof(char) * ft_strlen(str) + 3)) == NULL)
		exit(0);
	i = 0;
	while ((ft_strcmp(&str[i], ".s")) != 0)
	{
		if (i == (int)ft_strlen(str) - 1)
			exit(write(2, "Usage: ./asm <sourcefile.s>\n", 28));
		new[i] = str[i];
		i++;
	}
	new[i] = '.';
	new[i + 1] = 'c';
	new[i + 2] = 'o';
	new[i + 3] = 'r';
	new[i + 4] = '\0';
	return (new);
}
