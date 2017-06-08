/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/15/08 01:31:20 by aren              #+#    #+#             */
/*   Updated: 2014/15/08 03:31:22 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*newlist;
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	ret = new;
	newlist = new;
	lst = lst->next;
	while (lst)
	{
		new = f(lst);
		if (!(new = f(lst)))
			return (NULL);
		ret->next = new;
		ret = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (newlist);
}
