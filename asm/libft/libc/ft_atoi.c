/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 09:50:45 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/11 15:38:54 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t	i;
	int		rst;
	int		sign;

	sign = 1;
	i = 0;
	rst = 0;
	if (!ft_strcmp(str, "-2147483648"))
		return (-2147483648);
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		rst = rst * 10 + str[i] - '0';
		i++;
	}
	return (rst * sign);
}
