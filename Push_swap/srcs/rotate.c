/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:18:50 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ra(t_list *list)
{
	int		tmp;

	tmp = list->next->data;
	remove_first_elem(list);
	add_end_elem(tmp, list);
	ft_putstr_fd(" ra", 1);
	return ;
}

void		rb(t_list *list)
{
	int		tmp;

	tmp = list->next->data;
	remove_first_elem(list);
	add_end_elem(tmp, list);
	ft_putstr_fd(" rb", 1);
	return ;
}

void		rr(t_list *a, t_list *b)
{
	int		tmp;

	tmp = a->next->data;
	remove_first_elem(a);
	add_end_elem(tmp, a);
	tmp = b->next->data;
	remove_first_elem(b);
	add_end_elem(tmp, b);
	ft_putstr_fd(" rr", 1);
	return ;
}
