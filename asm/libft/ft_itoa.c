/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:36:15 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:42:44 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*itoa(char *str, int n, int len, char sign)
{
	int		i;

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
		len--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;
	char	sign;

	len = 0;
	sign = 'o';
	str = NULL;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		sign = '-';
		len = 1;
	}
	i = n;
	while (i /= 10)
		len++;
	str = itoa(str, n, len, sign);
	return (str);
}
