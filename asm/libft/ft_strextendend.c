/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strextendend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:10:45 by hmassonn          #+#    #+#             */
/*   Updated: 2016/12/07 02:24:56 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strextendend(char *str, int length, char c)
{
	char	*tmp;

	tmp = NULL;
	if (length > (int)ft_strlen(str))
	{
		if ((tmp = ft_strnew(length)) == NULL)
			return (NULL);
		ft_memset(tmp, c, length);
		tmp = ft_strcpyend(tmp, str);
		free(str);
		return (tmp);
	}
	return (str);
}
