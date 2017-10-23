/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:39:55 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:45:35 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	re_alloc(char **str, char add)
{
	char	*ptr;
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = *str;
	while (tmp[i])
		i++;
	if (!(ptr = malloc(sizeof(char) * (i + 2))))
		return ;
	i = 0;
	while (tmp[i])
	{
		ptr[i] = tmp[i];
		i++;
	}
	ptr[i] = add;
	i++;
	ptr[i] = '\0';
	free(*str);
	*str = ptr;
}

static void	printex(uintmax_t nb, int base, char **str)
{
	if (nb < (uintmax_t)base)
	{
		if (nb <= 9)
			re_alloc(str, (nb + '0'));
		else
			re_alloc(str, (nb + 'a' - 10));
		return ;
	}
	printex(nb / base, base, str);
	nb = nb % base;
	if (nb <= 9)
		re_alloc(str, (nb + '0'));
	else
		re_alloc(str, (nb + 'a' - 10));
}

char		*ft_itoa_base(uintmax_t value, int base)
{
	char	*str;

	if (base < 2 || base > 16)
		return (NULL);
	if ((str = malloc(sizeof(char))) == NULL)
		return (NULL);
	str[0] = '\0';
	printex(value, base, &str);
	return (str);
}
