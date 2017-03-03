/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:08:32 by hmassonn          #+#    #+#             */
/*   Updated: 2017/02/19 15:47:19 by basle-qu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	t_unch	*tmp;

	tmp = (t_unch *)b;
	while (len > 0)
	{
		tmp[len - 1] = c;
		len--;
	}
	return (b);
}
