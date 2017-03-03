/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 15:13:00 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:46:40 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s2;

	j = 0;
	i = ft_strlen(s1);
	if (n < i)
	{
		s2 = (char *)malloc(sizeof(char) * n + 1);
		if (s2 == NULL)
			return (NULL);
		while (j < n)
		{
			s2[j] = s1[j];
			j++;
		}
		s2[j] = '\0';
	}
	else
		s2 = ft_strdup(s1);
	return (s2);
}
