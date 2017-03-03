/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrextendend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:10:45 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 00:32:11 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrextendend(wchar_t *str, int length, char c)
{
	wchar_t	*tmp;

	tmp = NULL;
	if (length > (int)ft_wstrlen(str))
	{
		if ((tmp = (wchar_t*)malloc(sizeof(wchar_t) * length)) == NULL)
			return (NULL);
		ft_memset(tmp, c, length);
		tmp = ft_wstrcpyend(tmp, str);
		free(str);
		return (tmp);
	}
	return (str);
}
