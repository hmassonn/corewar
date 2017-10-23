/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:33:35 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:27:41 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		check_others(const char *restrict format, int *i,
	t_flags *flags, int *count)
{
	char	*str;
	int		len;

	if (format[*i] == 'Z' || format[*i] == '}' || format[*i] == 'R')
	{
		flags->space = 0;
		str = ft_strndup(&format[*i], 1);
		str = push_flags(str, flags);
		ft_putstr(str);
		(*i)++;
		len = ft_strlen(str);
		(*count) += len;
		free(str);
		return (len);
	}
	return (0);
}

static int		putwhat(const char *restrict format, int *i, va_list ap,
	int *count)
{
	t_flags		*flags;
	t_conv		*conv;
	int			tmp;
	int			ret;

	conv = NULL;
	if (!(conv = init_conv(conv)) ||
	(flags = (t_flags*)malloc(sizeof(t_flags))) == NULL)
		exit(-1);
	ret = 0;
	flags = init_flags(flags);
	while (format[*i] != '\0' && ret == 0)
	{
		tmp = 0;
		if ((flags = check_flags(format, i, flags)) == NULL)
			return (-1);
		while (ret == 0 && tmp < 14 && ret != EMPTY_STR)
			ret = conv->convert[tmp++]((char*)&format[*i], ap, flags);
		if (check_others(format, i, flags, count))
			break ;
		(*i)++;
	}
	free(flags);
	free(conv);
	return (ret);
}

static int		modu(const char *restrict format, int *i, int count, va_list ap)
{
	int		safecount;

	(*i)++;
	safecount = count;
	if ((count += putwhat(format, i, ap, &count)) < safecount)
		return (-1);
	if (count >= EMPTY_STR)
		count -= EMPTY_STR;
	return (count);
}

int				ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, format);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i])
		{
			ft_putchar(format[i++]);
			count++;
		}
		if (format[i] == '%')
			count = modu(format, &i, count, ap);
	}
	va_end(ap);
	return (count);
}
