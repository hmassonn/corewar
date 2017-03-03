/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initprintf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:27:17 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/06 21:45:19 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_conv		*init_conv(t_conv *conv)
{
	if (!(conv = (t_conv*)malloc(sizeof(t_conv))))
		return (NULL);
	conv->convert[0] = convert_s;
	conv->convert[1] = convert_smaj;
	conv->convert[2] = convert_p;
	conv->convert[3] = convert_di;
	conv->convert[4] = convert_dmaj;
	conv->convert[5] = convert_o;
	conv->convert[6] = convert_omaj;
	conv->convert[7] = convert_u;
	conv->convert[8] = convert_umaj;
	conv->convert[9] = convert_x;
	conv->convert[10] = convert_xmaj;
	conv->convert[11] = convert_c;
	conv->convert[12] = convert_cmaj;
	conv->convert[13] = convert_modulo;
	return (conv);
}

t_flags		*init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->dieze = 0;
	flags->space = 0;
	flags->width_min = -1;
	flags->point = 0;
	flags->precision = -1;
	flags->maj = 0;
	flags->o = 0;
	flags->omaj = 0;
	flags->d = 0;
	flags->x = 0;
	flags->type = 0;
	flags->neg = 0;
	flags->h = 0;
	flags->hh = 0;
	flags->l = 0;
	flags->ll = 0;
	flags->j = 0;
	flags->z = 0;
	flags->u = 0;
	return (flags);
}
