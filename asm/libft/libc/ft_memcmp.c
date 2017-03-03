/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:28:10 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/05 14:41:56 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_unch	*sone;
	t_unch	*stwo;
	size_t	i;

	sone = (t_unch *)s1;
	stwo = (t_unch *)s2;
	i = 0;
	if (!s1 && !s2 && !n)
		return (0);
	while (n > 0)
	{
		if (sone[i] != stwo[i])
			return (sone[i] - stwo[i]);
		i++;
		n--;
	}
	return (0);
}
