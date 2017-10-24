/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:09:02 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:47:06 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	ns = malloc(sizeof(char) * len + 1);
	if (ns == NULL)
		return (NULL);
	while (i < len)
	{
		ns[i] = s[i + start];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}
