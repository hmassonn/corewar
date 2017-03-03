/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:50:25 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:59:36 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int	s_ls(va_list ap, t_flags *flags)
{
	char *str;

	str = ft_strdup("");
	str[0] = 'S';
	return (convert_smaj(str, ap, flags));
}

static int	s_null(char *str, t_flags *flags)
{
	int		len;

	str = ft_strdup("");
	str = ft_strextendend(str, flags->width_min, '0');
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int			convert_s(char *nb, va_list ap, t_flags *flags)
{
	char	*str;
	int		len;

	if (nb[0] == 's')
	{
		flags->plus = 0;
		flags->space = 0;
		if (nb[-1] == 'l')
			return (s_ls(ap, flags));
		str = (va_arg(ap, char*));
		if (str == NULL && flags->width_min < 1)
			return (write(1, "(null)", 6));
		else if (str == NULL && flags->width_min > 0)
			return (s_null(str, flags));
		str = ft_strdup(str);
		str = pull_str_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		if (len == 0)
			return (EMPTY_STR);
		return (len);
	}
	return (0);
}

static int	c_zero(t_flags *flags, char *size)
{
	if (flags->zero > 0)
		size = ft_strextend(size, flags->width_min - 1, '0');
	else
		size = ft_strextend(size, flags->width_min - 1, ' ');
	ft_putstr(size);
	ft_putchar('\0');
	return (ft_strlen(size) + 1);
}

int			convert_c(char *nb, va_list ap, t_flags *flags)
{
	char	*str;
	char	*size;
	int		len;

	if (nb[0] == 'c')
	{
		size = ft_strdup("");
		flags->space = 0;
		flags->plus = 0;
		str = ft_strdup((const char*)"");
		if (nb[-1] == 'l')
			return (convert_cmaj("C", ap, flags));
		str[0] = va_arg(ap, int);
		if (str[0] == '\0')
			return (c_zero(flags, size));
		str = pull_char_flags(str, flags);
		ft_putstr(str);
		len = ft_strlen(str);
		free(str);
		return (len > 0 ? len : 1);
	}
	return (0);
}
