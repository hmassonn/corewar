/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 19:00:13 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/05 15:03:31 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_unch	*str;

	i = 0;
	str = (t_unch *)s;
	while (i < n)
	{
		if ((t_unch)c == (t_unch)str[i])
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
