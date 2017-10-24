/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:41:05 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:45:12 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl(char const *s)
{
	int		i;
	char	n;

	i = 0;
	n = '\n';
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
		write(1, &n, 1);
	}
}
