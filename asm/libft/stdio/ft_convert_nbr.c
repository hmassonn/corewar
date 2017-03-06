/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 17:38:53 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:11:43 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*openuit(char *str, t_flags *flags, uintmax_t cast)
{
	if (flags->hh)
		str = ft_uitoamax((unsigned char)cast);
	else if (flags->h)
		str = ft_uitoamax((unsigned short)cast);
	else if (flags->l)
		str = ft_uitoamax((unsigned long)cast);
	else if (flags->ll)
		str = ft_uitoamax((long long)cast);
	else if (flags->j)
		str = ft_uitoamax(cast);
	else if (flags->z)
		str = ft_uitoamax((size_t)cast);
	else
		str = ft_uitoamax((unsigned int)cast);
	return (str);
}

static char	*openit(char *str, t_flags *flags, uintmax_t cast)
{
	if (flags->hh)
		str = ft_itoamax((signed char)cast);
	else if (flags->h)
		str = ft_itoamax((short)cast);
	else if (flags->l)
		str = ft_itoamax((unsigned long)cast);
	else if (flags->ll)
		str = ft_itoamax((long long)cast);
	else if (flags->j)
		str = ft_itoamax(cast);
	else if (flags->z)
		str = ft_itoamax((size_t)cast);
	else
		str = ft_itoamax((int)cast);
	return (str);
}

int			convert_omaj(char *nb, va_list ap, t_flags *flags)
{
	char			*str;
	uintmax_t		cast;
	int				len;

	if (nb[0] == 'O')
	{
		flags->space = 0;
		flags->plus = 0;
		flags->omaj = 1;
		cast = (va_arg(ap, uintmax_t));
		if (cast == 0 && flags->dieze == 1)
			return (write(1, "0", 1));
		str = ft_itoa_base((unsigned long)cast, 8);
		if (str[0] == '0' && str[1] == '\0' && flags->point &&
		flags->width_min < 1)
			return (EMPTY_STR);
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int			convert_u(char *nb, va_list ap, t_flags *flags)
{
	char		*str;
	uintmax_t	cast;
	int			len;

	if (nb[0] == 'u')
	{
		flags->u = 1;
		flags->space = 0;
		flags->plus = 0;
		cast = (va_arg(ap, uintmax_t));
		str = NULL;
		str = openuit(str, flags, cast);
		if (FLAGZ && STRZ && ZEROZ && flags->width_min < 1)
			return (EMPTY_STR);
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int			convert_di(char *nb, va_list ap, t_flags *flags)
{
	char		*str;
	uintmax_t	cast;
	int			len;

	if (nb[0] == 'd' || nb[0] == 'i')
	{
		flags->d = 1;
		cast = (va_arg(ap, uintmax_t));
		str = NULL;
		str = openit(str, flags, cast);
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
