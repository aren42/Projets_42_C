/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:17:51 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_check_sa_at_the_top(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (tmp->next->next != list)
	{
		if (tmp->next->data > tmp->next->next->data)
		{
			sa(list);
			if (ft_ok_next(list) == 1)
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

int			ft_check_sa_at_the_end(t_list *list)
{
	int		i;
	t_list	*tmp;
	t_list	*str;

	i = 0;
	tmp = list;
	while (tmp->next->next != list)
	{
		if (tmp->next->data > tmp->next->next->data)
		{
			str = tmp;
			i++;
		}
		tmp = tmp->next;
	}
	if (tmp->next->next == list)
	{
		if ((i == 1) && (tmp->data > tmp->next->data))
			ft_end_op(list, tmp, str, i);
	}
	return (0);
}

void		ft_end_op(t_list *list, t_list *tmp, t_list *str, int i)
{
	if (tmp->next->next == list)
	{
		if ((i == 1) && (tmp->data > tmp->next->data))
		{
			rra(str);
			rra(str);
			sa(str);
			ra(str);
			ra(str);
			ft_str_exit("\n");
		}
	}
}

void		ft_check_three_params(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	if (tmp->next->next != list)
	{
		if (tmp->next->next->next->next == list)
		{
			while ((tmp->next->data > tmp->next->next->data)
				&& (tmp->next->next != list))
			{
				tmp = tmp->next;
				if (tmp->next->next == list)
				{
					sa(list);
					rra(list);
				}
			}
		}
	}
}
