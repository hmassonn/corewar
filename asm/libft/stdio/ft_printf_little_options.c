/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfLittleOptions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:25:34 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/05 17:51:18 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flags		*check_size(const char *restrict format, int *i, t_flags *flags)
{
	if (format[*i] == 'h')
	{
		if (format[*i + 1] == 'h')
			flags->hh = 1;
		else
			flags->h = 1;
	}
	if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
			flags->ll = 1;
		else
			flags->l = 1;
	}
	if (format[*i] == 'j')
		flags->j = 1;
	if (format[*i] == 'z')
		flags->z = 1;
	return (flags);
}

t_flags		*check_minus(t_flags *flags, char format)
{
	if (format == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	return (flags);
}

t_flags		*check_plus(t_flags *flags, char format)
{
	if (format == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
	return (flags);
}

t_flags		*check_point(t_flags *flags, char format)
{
	if (format == '.')
		flags->point = 1;
	return (flags);
}
