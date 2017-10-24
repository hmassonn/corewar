/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmassonn <hmassonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:03:15 by hmassonn          #+#    #+#             */
/*   Updated: 2016/11/29 18:43:55 by hmassonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*res;
	t_list	*tmp;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if ((res = ft_lstnew(new->content, new->content_size)))
	{
		tmp = res;
		lst = lst->next;
		while (lst)
		{
			new = f(lst);
			if (!(tmp->next = ft_lstnew(new->content, new->content_size)))
				return (NULL);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (res);
}
