/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_check_flags.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:25:34 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:29:15 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_flags	*check_width_min(const char *restrict format, int *i,
		t_flags *flags)
{
	char		*tmp;
	int			id;
	int			z;

	id = *i;
	z = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		(*i)++;
		z++;
	}
	if ((tmp = (char*)malloc(sizeof(char) * (z + 1))) == NULL)
		return (NULL);
	tmp[z] = '\0';
	z = 0;
	while (id < *i)
		tmp[z++] = format[id++];
	if (flags->point == 0)
		flags->width_min = ft_atoi(tmp);
	if (flags->point == 1)
		flags->precision = ft_atoi(tmp);
	(*i)--;
	free(tmp);
	return (flags);
}

t_flags			*check_flags(const char *restrict format, int *i,
	t_flags *flags)
{
	flags = check_minus(flags, format[*i]);
	if (format[*i] == '0' && !flags->minus && !flags->zero
			&& flags->width_min < 1 && flags->precision < 1)
		flags->zero = 1;
	flags = check_plus(flags, format[*i]);
	if (format[*i] == '#')
		flags->dieze = 1;
	if (format[*i] == ' ' && flags->plus == 0)
		flags->space = 1;
	flags = check_point(flags, format[*i]);
	if (format[*i] >= '1' && format[*i] <= '9')
	{
		if ((flags = check_width_min(format, i, flags)) == NULL)
			return (NULL);
	}
	if (FLAGZ && STRZ)
		flags = check_size(format, i, flags);
	return (flags);
}
