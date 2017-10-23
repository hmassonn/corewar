/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strintdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:57:21 by hmassonn          #+#    #+#             */
/*   Updated: 2017/01/23 16:57:23 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		*ft_strintdup(int *str, int nb)
{
	int		i;
	int		*s2;

	i = 0;
	if ((s2 = (int*)malloc(sizeof(int) * nb)) == NULL)
		exit(0);
	while (i < nb)
	{
		s2[i] = str[i];
		i++;
	}
	return (s2);
}
