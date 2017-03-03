/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_little.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:43:51 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:42:52 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		convert_modulo(char *nb, va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	(void)ap;
	if (nb[0] == '%')
	{
		flags->space = 0;
		flags->precision = -1;
		str = ft_strdup((const char*)"%");
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int		convert_dmaj(char *nb, va_list ap, t_flags *flags)
{
	char		*str;
	intmax_t	cast;
	int			len;

	if (nb[0] == 'D')
	{
		cast = (va_arg(ap, intmax_t));
		str = ft_itoamax((long)cast);
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int		convert_umaj(char *nb, va_list ap, t_flags *flags)
{
	char		*str;
	uintmax_t	cast;
	int			len;

	if (nb[0] == 'U')
	{
		flags->space = 0;
		flags->plus = 0;
		cast = (va_arg(ap, uintmax_t));
		str = ft_uitoamax((unsigned long)cast);
		str = push_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len);
	}
	return (0);
}

int		convert_cmaj(char *nb, va_list ap, t_flags *flags)
{
	wchar_t		c[2];

	(void)flags;
	if (nb[0] == 'C')
	{
		c[0] = (va_arg(ap, wchar_t));
		if (c[0] == '\0')
		{
			ft_putchar('\0');
			return (1);
		}
		ft_putwchar(c[0]);
		c[1] = '\0';
		return (ft_wstrlen(&c[0]));
	}
	return (0);
}

int		smaj_end(size_t len, t_flags *flags, char *size)
{
	if (len < (size_t)flags->width_min && flags->minus)
	{
		if (flags->zero > 0)
			size = ft_strextendend(size, flags->width_min - len, '0');
		else
			size = ft_strextendend(size, flags->width_min - len, ' ');
		ft_putstr(size);
	}
	free(size);
	if (flags->width_min == -1)
		return (len);
	return (len > (size_t)flags->width_min ? (int)len : flags->width_min);
}
