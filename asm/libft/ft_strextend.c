/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 18:35:30 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:33:10 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strextend(char *str, int length, char c)
{
	char	*tmp;

	tmp = NULL;
	if (length > (int)ft_strlen(str))
	{
		if ((tmp = ft_strnew(length)) == NULL)
			return (NULL);
		tmp = ft_memset(tmp, c, length);
		tmp = ft_memcpy(tmp, str, ft_strlen(str));
		free(str);
		return (tmp);
	}
	return (str);
}
