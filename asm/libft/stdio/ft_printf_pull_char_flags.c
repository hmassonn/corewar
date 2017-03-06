/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfPullCharFlags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:25:34 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/05 17:42:31 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*plusandspace(char *str, t_flags *flags)
{
	int		i;

	i = 0;
	if (flags->plus || flags->space)
		str = ft_strextendend(str, (ft_strlen(str) + 1), ' ');
	if (flags->plus)
		str[0] = '+';
	if (i == -1)
		str[0] = '-';
	return (str);
}

char			*pull_char_flags(char *str, t_flags *flags)
{
	size_t		len;
	size_t		one;

	one = 0;
	len = ft_strlen(str);
	if (len == 0)
		one = 1;
	if (flags->precision > 0 && len > (size_t)flags->precision)
		str[flags->precision] = '\0';
	if (flags->zero == 1)
		str = ft_strextendend(str, (flags->width_min - flags->plus -
			flags->space - one), '0');
	str = plusandspace(str, flags);
	if (flags->minus == 0 && flags->zero == 0)
		str = ft_strextendend(str, flags->width_min - one, ' ');
	else
		str = ft_strextend(str, flags->width_min - one, ' ');
	return (str);
}
