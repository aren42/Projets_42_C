/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:24:28 by aren              #+#    #+#             */
/*   Updated: 2016/11/04 11:24:29 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_data			*ft_init_lst(char *name, char *fpath, t_opt **option)
{
	t_data		*new;

	if ((new = (t_data *)malloc(sizeof(t_data))) == NULL)
		ft_error(1, "list creation");
	if ((new->name = ft_strdup(name)) == NULL)
		ft_error(1, name);
	if ((new->path = ft_strdup(fpath)) == NULL)
		ft_error(1, fpath);
	new->type = 0;
	new->date = NULL;
	new->year = NULL;
	new->epoc = 0;
	new->owner = NULL;
	new->group = NULL;
	new->size = NULL;
	new->nblink = NULL;
	new->link = NULL;
	new->next = NULL;
	new->fsize_len = 0;
	new->block = 0;
	if (ft_file_info(new->path, new->name, *option, &new) == -1)
		return (NULL);
	return (new);
}

int				intcmp(int a, int b)
{
	return (a - b);
}

static int		ft_lst_time_insert_bis(t_opt *option, t_data **lst, t_data *new)
{
	int				cmp;
	t_data			*tmp;

	tmp = *lst;
	while (tmp->next != NULL && (cmp = (option->r ?
					intcmp(tmp->next->epoc, new->epoc) :
					intcmp(new->epoc, tmp->next->epoc))) <= 0)
	{
		if (cmp == 0)
		{
			while (tmp->next && (option->r ?
						ft_strcmp(tmp->next->name, new->name) :
						ft_strcmp(new->name, tmp->next->name)) > 0
						&& intcmp(tmp->next->epoc, new->epoc) == 0)
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
			return (0);
		}
		tmp = tmp->next;
	}
	new->next = tmp->next;
	tmp->next = new;
	return (0);
}

int				ft_lst_time_insert(t_opt *opt, t_data **lst, t_data *new)
{
	t_data			*tmp;
	int				cmp;

	tmp = *lst;
	cmp = (opt->r ? intcmp(tmp->epoc, new->epoc) :
			intcmp(new->epoc, tmp->epoc));
	if (cmp > 0 || (cmp == 0 && (opt->r ? ft_strcmp(tmp->name, new->name) :
										ft_strcmp(new->name, tmp->name)) < 0))
	{
		new->next = tmp;
		*lst = new;
		return (0);
	}
	else if (tmp->next == NULL)
	{
		tmp->next = new;
		return (0);
	}
	ft_lst_time_insert_bis(opt, lst, new);
	return (0);
}

int				ft_lst_insert(t_opt *option, t_data **lst, t_data *new)
{
	t_data			*tmp;
	int				cmp;

	tmp = *lst;
	if ((cmp = (option->r ? ft_strcmp(tmp->name, new->name) :
					ft_strcmp(new->name, tmp->name))) < 0)
	{
		new->next = tmp;
		*lst = new;
		return (0);
	}
	else if (tmp->next == NULL)
	{
		tmp->next = new;
		return (0);
	}
	while (tmp->next != NULL && (cmp = (option->r ?
					ft_strcmp(tmp->next->name, new->name) :
					ft_strcmp(new->name, tmp->next->name))) > 0)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;
	return (0);
}
