/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/21 22:32:40 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list		*init_list(void)
{
	t_list	*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error_str_exit("Error malloc\n");
	list->next = list;
	list->prev = list;
	list->data = 0;
	return (list);
}

void		remove_first_elem(t_list *list)
{
	if (list->next == list)
		return ;
	list->next = list->next->next;
	list->next->prev = list;
	return ;
}

void		remove_last_elem(t_list *list)
{
	if (list->next == list)
		return ;
	list->prev = list->prev->prev;
	list->prev->next = list;
	return ;
}

void		add_start_elem(int data, t_list *list)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error_str_exit("Error malloc\n");
	elem->data = data;
	elem->next = list->next;
	elem->prev = list;
	list->next->prev = elem;
	list->next = elem;
	return ;
}

void		add_end_elem(int data, t_list *list)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == NULL)
		ft_error_str_exit("Error malloc\n");
	elem->data = data;
	elem->prev = list->prev;
	elem->next = list;
	list->prev->next = elem;
	list->prev = elem;
	return ;
}
