/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:49:33 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:44:09 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*ncontent;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ncontent = ft_memalloc(content_size);
		ft_memcpy(ncontent, content, content_size);
		new->content = ncontent;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
