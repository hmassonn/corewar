/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoamax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:15 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/03 04:04:15 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*itoamax(char *str, uintmax_t n, uintmax_t len, char sign)
{
	uintmax_t		i;

	if ((str = (char *)malloc(sizeof(char) * len + 2)) == NULL)
		return (NULL);
	i = 0;
	if (sign == '-')
	{
		i = 1;
		str[0] = '-';
	}
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

char		*ft_itoamax(intmax_t n)
{
	char			*str;
	uintmax_t		i;
	uintmax_t		len;
	char			sign;

	len = 0;
	sign = 'o';
	str = NULL;
	if (n < 0)
	{
		n = -n;
		sign = '-';
		len = 1;
	}
	i = n;
	while (i /= 10)
		len++;
	str = itoamax(str, n, len, sign);
	return (str);
}
