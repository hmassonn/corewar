/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrextend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:35:30 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 00:32:23 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrextend(wchar_t *str, int length, char c)
{
	wchar_t	*tmp;

	tmp = NULL;
	if (length > (int)ft_wstrlen(str))
	{
		if ((tmp = (wchar_t*)malloc(sizeof(wchar_t) * length)) == NULL)
			return (NULL);
		ft_memset(tmp, c, length);
		tmp = ft_memcpy(tmp, str, ft_wstrlen(str));
		free(str);
		return (tmp);
	}
	return (str);
}
