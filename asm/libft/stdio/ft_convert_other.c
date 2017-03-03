/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_other.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:42:01 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:34:16 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*openit(char *str, t_flags *flags, uintmax_t cast, int base)
{
	if (flags->hh)
		str = ft_itoa_base((unsigned char)cast, base);
	else if (flags->h)
		str = ft_itoa_base((unsigned short)cast, base);
	else if (flags->l)
		str = ft_itoa_base((unsigned long)cast, base);
	else if (flags->ll)
		str = ft_itoa_base((long long)cast, base);
	else if (flags->j)
		str = ft_itoa_base(cast, base);
	else if (flags->z)
		str = ft_itoa_base((size_t)cast, base);
	else
		str = ft_itoa_base((unsigned int)cast, base);
	return (str);
}

static char	*openitmaj(char *str, t_flags *flags, uintmax_t cast)
{
	if (flags->hh)
		str = ft_itoa_basemaj((unsigned char)cast, 16);
	else if (flags->h)
		str = ft_itoa_basemaj((unsigned short)cast, 16);
	else if (flags->l)
		str = ft_itoa_basemaj((unsigned long)cast, 16);
	else if (flags->ll)
		str = ft_itoa_basemaj((long long)cast, 16);
	else if (flags->j)
		str = ft_itoa_basemaj(cast, 16);
	else if (flags->z)
		str = ft_itoa_basemaj((size_t)cast, 16);
	else
		str = ft_itoa_basemaj((unsigned int)cast, 16);
	return (str);
}

int			convert_x(char *nb, va_list ap, t_flags *flags)
{
	char			*str;
	uintmax_t		cast;
	int				len;

	if (nb[0] == 'x')
	{
		flags->space = 0;
		flags->plus = 0;
		flags->x = 1;
		cast = (va_arg(ap, uintmax_t));
		str = NULL;
		if (cast == 0)
			flags->dieze = 0;
		str = openit(str, flags, cast, 16);
		if (FLAGZ && STRZ && ZEROZ && flags->width_min < 1)
			return (EMPTY_STR);
		str = push_flags(str, flags);
		if (str[flags->width_min - 1] == '0' && cast == 0 && flags->zero == 0)
			str[flags->width_min - 1] = ' ';
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int			convert_xmaj(char *nb, va_list ap, t_flags *flags)
{
	char			*str;
	uintmax_t		cast;
	int				len;

	if (nb[0] == 'X')
	{
		flags->space = 0;
		flags->plus = 0;
		flags->maj = 1;
		cast = (va_arg(ap, uintmax_t));
		if (cast == 0 && flags->dieze == 1)
			return (write(1, "0", 1));
		str = NULL;
		str = openitmaj(str, flags, cast);
		if (FLAGZ && STRZ && ZEROZ)
			return (EMPTY_STR);
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int			convert_o(char *nb, va_list ap, t_flags *flags)
{
	char			*str;
	uintmax_t		cast;
	int				len;

	if (nb[0] == 'o')
	{
		flags->o = 1;
		flags->space = 0;
		flags->plus = 0;
		cast = (va_arg(ap, uintmax_t));
		if (cast == 0 && flags->point == 0)
			return (write(1, "0", 1));
		str = openit(NULL, flags, cast, 8);
		if (FLAGZ && STRZ && ZEROZ && flags->dieze == 0 && flags->width_min < 1)
			return (EMPTY_STR);
		if (ZEROZ)
			str = ft_strextend(ft_strdup(""), flags->width_min, ' ');
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}
