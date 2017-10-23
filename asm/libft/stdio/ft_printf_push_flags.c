/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_push_flags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:25:34 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/06 20:50:58 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*dieze(char *str, t_flags *flags)
{
	if (flags->dieze == 1)
	{
		if (flags->o == 0 && flags->omaj == 0)
		{
			str = ft_strextendend(str, (ft_strlen(str) + 2), ' ');
			str[0] = '0';
			if (flags->maj == 1)
				str[1] = 'X';
			else
				str[1] = 'x';
		}
		else if (flags->precision < (int)ft_strlen(str))
		{
			str = ft_strextendend(str, (ft_strlen(str) + 1), ' ');
			str[0] = '0';
		}
	}
	return (str);
}

static char		*plusspace(char *str, t_flags *flags)
{
	int		i;

	i = 0;
	str = dieze(str, flags);
	while (str[i] == '0')
		i++;
	if (str[i] == '-')
	{
		if (flags->space)
			str[i] = ' ';
		else
			str[i] = '0';
		i = -1;
	}
	if (flags->plus || flags->space)
		str = ft_strextendend(str, (ft_strlen(str) + 1), ' ');
	if (flags->plus)
		str[0] = '+';
	if (i == -1)
		str[0] = '-';
	return (str);
}

static char		*push_minus(char *str, t_flags *flags)
{
	if (str[0] == '-')
	{
		flags->plus = 0;
		flags->space = 0;
		if (flags->precision > 0)
		{
			str = ft_strextendend(str, (flags->precision + 1), '0');
			flags->precision = -1;
		}
	}
	return (str);
}

char			*push_flags(char *str, t_flags *flags)
{
	str = push_minus(str, flags);
	if (flags->precision > 0)
		str = ft_strextendend(str, (flags->precision), '0');
	if (flags->zero == 1)
	{
		if (flags->x == 1)
			str = ft_strextendend(str, (flags->width_min - flags->plus -
				flags->space - (flags->dieze * 2)), '0');
		else if (flags->d == 0 || (flags->zero && !flags->point))
			str = ft_strextendend(str, (flags->width_min - flags->plus -
				flags->space), '0');
		else
			str = ft_strextendend(str, (flags->width_min - flags->plus -
				flags->space), ' ');
	}
	str = plusspace(str, flags);
	if (flags->minus == 0 && flags->zero == 0)
		str = ft_strextendend(str, flags->width_min, ' ');
	else
		str = ft_strextend(str, flags->width_min, ' ');
	return (str);
}
