/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 16:13:59 by aren              #+#    #+#             */
/*   Updated: 2016/11/03 16:14:00 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_display_name(t_opt *opt, char *str)
{
	if (opt->nb_av > 1 || opt->big_r == 1)
	{
		if (opt->first_dir == 0 && opt->big_r == 0)
		{
			ft_putstr(str);
			ft_putendl(":");
		}
		else
		{
			ft_putchar('\n');
			ft_putstr(str);
			ft_putendl(":");
		}
		opt->first_dir = 1;
	}
	return (0);
}

static int		ft_second_display(t_opt *opt, t_data *tmp)
{
	if (opt->a == 1 && tmp->type == 'd')
	{
		if (opt->nb_av > 1)
			ft_display_name(opt, tmp->name);
		if (ft_recursion(opt, tmp->path, tmp->name) == -1)
			return (-1);
	}
	else if (tmp->type == 'd')
	{
		if (opt->nb_av > 1)
			ft_display_name(opt, tmp->name);
		if (ft_recursion(opt, tmp->path, tmp->name) == -1)
			return (-1);
	}
	else if (tmp->type == 'l' && (opt->l == 0 && opt->o == 0 && opt->g == 0))
	{
		if (ft_recursion(opt, tmp->path, tmp->name) == -1)
			return (-1);
	}
	return (0);
}

int				ft_display(t_data **lst, t_opt *opt)
{
	t_data		*tmp;

	tmp = *lst;
	while (tmp != NULL)
	{
		if (tmp->type != 'd')
			ft_ls_display(opt, &tmp);
		tmp = tmp->next;
	}
	tmp = *lst;
	while (tmp != NULL)
	{
		opt->total_blocks = 0;
		ft_second_display(opt, tmp);
		opt->first_dir = 1;
		tmp = tmp->next;
	}
	return (0);
}

int				ft_put_space(char *str, int lenght)
{
	int			i;

	i = ft_strlen(str);
	while (i < lenght)
	{
		ft_putchar(' ');
		i++;
	}
	return (0);
}

int				ft_ls_display(t_opt *opt, t_data **lst)
{
	if (opt->l == 1 || opt->o == 1 || opt->g == 1)
		ft_long_display(lst, opt);
	if (opt->big_g == 1)
	{
		ft_display_colors_big_g(lst);
		ft_display_colors_big_g_v2(lst);
	}
	ft_putstr((*lst)->name);
	if (opt->big_g)
		ft_putstr("\033[0m");
	if (opt->p && (*lst)->type == 'd')
		ft_putchar('/');
	if ((opt->l == 1 || opt->o == 1 || opt->g == 1)
			&& (*lst)->type == 'l')
	{
		ft_putstr(" -> ");
		ft_putstr((*lst)->link);
	}
	ft_putendl("");
	return (0);
}
