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

int			ft_ok_next(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp->next->next != list)
	{
		if (tmp->next->data > tmp->next->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_list		*ft_push_swap(t_list *a, t_list *b)
{
	t_list	*tmp;

	tmp = a;
	while ((ft_ok_next(a)) != 1)
	{
		while (tmp->next->data > tmp->next->next->data
				|| tmp->next->data > tmp->prev->data)
		{
			if (tmp->next->data > tmp->next->next->data)
				sa(a);
			else
				rra(a);
		}
		pb(a, b);
	}
	tmp = b;
	while (tmp->next != b)
	{
		pa(a, b);
		tmp = tmp->next;
	}
	pa(a, b);
	if ((ft_ok_next(a)) != 1)
		return (ft_push_swap(a, b));
	return (a);
}

int			main(int ac, char **av)
{
	int		err;
	int		i;
	t_list	*a;
	t_list	*b;

	(void)(ac);
	err = ft_check_params(ac, av);
	a = init_list();
	b = init_list();
	i = 1;
	while (av[i])
		add_end_elem(ft_getnbr(av[i++]), a);
	if ((ft_ok_next(a)) == 1)
		return (0);
	ft_check_three_params(a);
	ft_check_sa_at_the_top(a);
	ft_check_sa_at_the_end(a);
	ft_push_swap(a, b);
	ft_putstr_fd("\n", 1);
	return (0);
}
