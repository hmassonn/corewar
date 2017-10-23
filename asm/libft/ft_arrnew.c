/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbadia <rbadia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:31:23 by rbadia            #+#    #+#             */
/*   Updated: 2016/11/29 18:39:03 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_arrnew(size_t rows, size_t columns)
{
	char	**new;
	size_t	i;
	size_t	j;

	i = 0;
	if ((new = (char **)malloc(sizeof(char *) * (rows + 1))) == NULL)
		return (NULL);
	while (i < rows)
	{
		if ((new[i] = (char *)malloc(sizeof(char) * (columns + 1))) == NULL)
			return (NULL);
		j = 0;
		while (j < columns)
		{
			new[i][j] = '.';
			j++;
		}
		new[i][j] = '\0';
		i++;
	}
	new[i] = NULL;
	return (new);
}
