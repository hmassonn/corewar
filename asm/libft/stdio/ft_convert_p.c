/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 17:43:10 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:52:41 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*tmp_reduc(char *tmp, t_flags *flags)
{
	tmp = ft_strextend(tmp, ft_strlen(tmp) + 2, '0');
	tmp = push_flags(tmp, flags);
	tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, 'x');
	tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, '0');
	if ((flags->precision) < ((int)ft_strlen(tmp) - 2))
		tmp[ft_strlen(tmp) - 2] = '\0';
	return (tmp);
}

static char	*reduc_p(char *tmp, t_flags *flags)
{
	if ((flags->precision < (int)ft_strlen(tmp) || flags->width_min + 2
	< (int)ft_strlen(tmp)) && flags->width_min > flags->precision)
	{
		tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, 'x');
		tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, '0');
		tmp = push_flags(tmp, flags);
	}
	else
	{
		tmp = push_flags(tmp, flags);
		tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, 'x');
		tmp = ft_strextendend(tmp, ft_strlen(tmp) + 1, '0');
	}
	return (tmp);
}

int			convert_p(char *nb, va_list ap, t_flags *flags)
{
	char	*tmp;
	int		len;

	if (nb[0] == 'p')
	{
		flags->space = 0;
		flags->plus = 0;
		tmp = ft_itoa_base(va_arg(ap, size_t), 16);
		if (flags->precision < 1 && tmp[0] == '0' && flags->point == 1)
			tmp = ft_strdup("");
		if (flags->zero == 0 && (flags->width_min > (int)ft_strlen(tmp) ||
		flags->precision > (int)ft_strlen(tmp)))
			tmp = reduc_p(tmp, flags);
		else
			tmp = tmp_reduc(tmp, flags);
		ft_putstr(tmp);
		len = ft_strlen(tmp);
		free(tmp);
		return (len);
	}
	return (0);
}
