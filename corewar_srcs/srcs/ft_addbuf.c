/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addbuf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clanier <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 11:59:12 by clanier           #+#    #+#             */
/*   Updated: 2017/03/07 11:59:29 by clanier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	ft_addbuf(t_mars **pmars, char *str)
{
	int		i;
	t_mars	*mars;

	mars = *pmars;
	i = 0;
	while (str[i])
		mars->fat_buf[mars->ifb++] = str[i++];
	mars->fat_buf[mars->ifb] = '\0';
}

int		ft_nbrlen_base(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

void	ft_addbuf_nbr(t_mars **mars, unsigned int nbr, int base)
{
	int		i;
	int		n;
	double	pow;
	char	c[2];

	i = ft_nbrlen_base(nbr, base) - 1;
	if (!i && base == 16)
		ft_addbuf(mars, "0");
	c[1] = 0;
	while (i >= 0)
	{
		pow = ft_pow(base, i);
		n = (double)nbr / pow;
		c[0] = n < 10 ? n + 48 : n + 87;
		ft_addbuf(mars, c);
		nbr -= (unsigned int)pow * (unsigned int)n;
		i--;
	}
	base == 16 ? ft_addbuf(mars, " ") : (void)nbr;
}
