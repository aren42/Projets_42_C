/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:18:53 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		sa(t_list *list)
{
	int		swap;

	if (list->next == list || list->next->next == list)
		return ;
	swap = list->next->data;
	list->next->data = list->next->next->data;
	list->next->next->data = swap;
	ft_putstr_fd(" sa", 1);
	return ;
}

void		sb(t_list *list)
{
	int		swap;

	if (list->next == list || list->next->next == list)
		return ;
	swap = list->next->data;
	list->next->data = list->next->next->data;
	list->next->next->data = swap;
	ft_putstr_fd(" sb", 1);
	return ;
}

void		ss(t_list *a, t_list *b)
{
	int		swap;

	if ((a->next == a) || (a->next->next == a))
		return ;
	if ((b->next == b) || (b->next->next == b))
		return ;
	swap = a->next->data;
	a->next->data = a->next->next->data;
	a->next->next->data = swap;
	swap = b->next->data;
	b->next->data = b->next->next->data;
	b->next->next->data = swap;
	ft_putstr_fd(" ss", 1);
	return ;
}
