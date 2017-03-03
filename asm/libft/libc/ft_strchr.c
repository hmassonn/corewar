/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:27:58 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/19 17:11:33 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	find = c;

	if (!s)
		return (NULL);
	while (*s != find)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}
