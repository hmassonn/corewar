/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:34:49 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/01 18:23:20 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		ft_puthexa(unsigned int n)
{
	int		compt;

	compt = 0;
	if (n >= 16)
	{
		compt += ft_puthexa(n / 16);
		compt += ft_puthexa(n % 16);
	}
	if (n < 10)
		compt += ft_putcharnb(n + '0');
	else if (n < 16)
		compt += ft_putcharnb(n + 'a' - 10);
	return (compt);
}
