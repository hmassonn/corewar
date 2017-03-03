/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:18:36 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/11 14:38:52 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	t_unch	*d;
	t_unch	*s;

	i = 0;
	d = (t_unch *)dst;
	s = (t_unch *)src;
	while (i < n)
	{
		d[i] = s[i];
		if ((t_unch)s[i] == (t_unch)c)
			return ((void *)(d + i + 1));
		i++;
	}
	return (NULL);
}
