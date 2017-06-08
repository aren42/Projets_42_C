/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:18:33 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		rra(t_list *list)
{
	int		tmp;

	tmp = list->prev->data;
	remove_last_elem(list);
	add_start_elem(tmp, list);
	ft_putstr_fd(" rra", 1);
	return ;
}

void		rrb(t_list *list)
{
	int		tmp;

	tmp = list->prev->data;
	remove_last_elem(list);
	add_start_elem(tmp, list);
	ft_putstr_fd(" rrb", 1);
	return ;
}

void		rrr(t_list *a, t_list *b)
{
	int		tmp;

	tmp = a->prev->data;
	remove_last_elem(a);
	add_start_elem(tmp, a);
	tmp = b->prev->data;
	remove_last_elem(b);
	add_start_elem(tmp, b);
	ft_putstr_fd(" rrr", 1);
}
