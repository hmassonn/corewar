/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexamaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:34:49 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/01 18:23:29 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_puthexamaj(unsigned int n)
{
	int		compt;

	compt = 0;
	if (n >= 16)
	{
		compt += ft_puthexamaj(n / 16);
		compt += ft_puthexamaj(n % 16);
	}
	if (n < 10)
		compt += ft_putcharnb(n + '0');
	else if (n < 16)
		compt += ft_putcharnb(n + 'A' - 10);
	return (compt);
}
