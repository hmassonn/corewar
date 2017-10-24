/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_smaj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:17:31 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:30:22 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	begin_smaj(wchar_t *str, t_flags *flags, char *size)
{
	int		len;

	if (flags->zero && flags->point && flags->width_min > 0)
	{
		size = ft_strextendend(size, flags->width_min, '0');
		ft_putstr(size);
		len = ft_strlen(size);
		free(size);
		return (len);
	}
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (ft_strlen("(null)"));
	}
	return (0);
}

static int	big_smaj(size_t len, t_flags *flags, wchar_t *str)
{
	int		wid;

	wid = flags->width_min;
	if (flags->precision == 1)
		wid--;
	while (wid >= flags->precision)
	{
		ft_putchar(' ');
		wid--;
	}
	len = flags->precision;
	if (flags->point && flags->precision > 0)
	{
		ft_putwchar(*str);
		return (flags->width_min > flags->precision ? flags->width_min :
				flags->precision - 1);
	}
	ft_putwchar(str[(len / 4) - 1]);
	len -= 4;
	if (!flags->minus)
		return (flags->width_min > flags->precision ?
				flags->width_min : flags->precision - 1);
		return (0);
}

static int	middle_smaj(size_t len, t_flags *flags, wchar_t *str)
{
	len = 0;
	if (flags->precision < 1 && flags->point)
	{
		while ((int)len < flags->width_min)
		{
			ft_putchar(' ');
			len++;
		}
		return (flags->width_min);
	}
	while (len < (size_t)flags->precision - 10)
	{
		ft_putwchar(str[len]);
		len++;
	}
	return (flags->precision);
}

static char	*reduc_size(size_t len, char *size, t_flags *flags)
{
	if (flags->zero > 0)
		size = ft_strextendend(size, flags->width_min - len, '0');
	else
		size = ft_strextendend(size, flags->width_min - len, ' ');
	ft_putstr(size);
	return (size);
}

int			convert_smaj(char *nb, va_list ap, t_flags *flags)
{
	wchar_t	*str;
	char	*size;
	size_t	len;

	if (nb[0] == 'S')
	{
		size = ft_strdup("");
		str = (va_arg(ap, wchar_t*));
		if ((flags->zero && flags->point && flags->width_min > 0) || !str)
			return (begin_smaj(str, flags, size));
		len = ft_wstrlen(str);
		if (len < (size_t)flags->width_min && !flags->minus)
			size = reduc_size(len, size, flags);
		if (flags->precision > 0 && (flags->width_min < 0 || flags->precision <
					flags->width_min))
			return (big_smaj(len, flags, str));
		if (flags->precision < (int)len && len > (size_t)flags->width_min)
			return (middle_smaj(len, flags, str));
		ft_putwstr(str);
		return (smaj_end(len, flags, size));
	}
	return (0);
}
