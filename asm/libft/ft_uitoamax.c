/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoamax.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:15 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/06 14:33:59 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*itoamax(char *str, uintmax_t n, uintmax_t len)
{
	uintmax_t		i;

	if ((str = (char *)malloc(sizeof(char) * len + 2)) == NULL)
		return (NULL);
	i = 0;
	str[len + 1] = '\0';
	while (len >= i)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		if (len == 0)
			break ;
		len--;
	}
	return (str);
}

char		*ft_uitoamax(uintmax_t n)
{
	char			*str;
	uintmax_t		i;
	uintmax_t		len;

	len = 0;
	str = NULL;
	i = n;
	while (i /= 10)
		len++;
	str = itoamax(str, n, len);
	return (str);
}
