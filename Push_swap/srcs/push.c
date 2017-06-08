/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:17:53 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		pa(t_list *a, t_list *b)
{
	int		tmp;

	if (b->next == b)
		return ;
	tmp = b->next->data;
	remove_first_elem(b);
	add_start_elem(tmp, a);
	ft_putstr_fd(" pa", 1);
	return ;
}

void		pb(t_list *a, t_list *b)
{
	int		tmp;

	if (a->next == a)
		return ;
	tmp = a->next->data;
	remove_first_elem(a);
	add_start_elem(tmp, b);
	ft_putstr_fd(" pb", 1);
	return ;
}
