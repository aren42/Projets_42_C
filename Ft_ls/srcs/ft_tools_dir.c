/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:26:36 by aren              #+#    #+#             */
/*   Updated: 2016/11/01 18:26:38 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_first_display_dir(t_data **lst, t_opt *opt, int i)
{
	t_data				*tmp;

	tmp = *lst;
	ft_display_total(&opt, i);
	while (tmp)
	{
		if (opt->a == 1 || (opt->a == 0 && tmp->name[0] != '.'))
			ft_ls_display(opt, &tmp);
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_occupy_list(DIR *dir, t_data **lst, t_opt *opt, char *path)
{
	struct dirent		*dirent;
	t_data				*new;
	char				*str;
	int					i;

	i = 0;
	while ((dirent = readdir(dir)) != NULL)
	{
		str = format_path(path, dirent->d_name, ft_strlen(dirent->d_name));
		if ((new = ft_init_lst(dirent->d_name, str, &opt)) == NULL)
			continue ;
		if (*lst == NULL)
			*lst = new;
		else if (opt->t == 1)
			ft_lst_time_insert(opt, lst, new);
		else
			ft_lst_insert(opt, lst, new);
		if (opt->a == 1 || (opt->a == 0 && new->name[0] != '.'))
			i++;
	}
	ft_first_display_dir(lst, opt, i);
	return (0);
}

static int		open_dir(t_data **lst, t_opt *opt, char *dir_path, char *name)
{
	DIR					*dir;

	if ((dir = opendir(dir_path)) == NULL)
		return (ft_error(3, name));
	ft_occupy_list(dir, lst, opt, dir_path);
	closedir(dir);
	return (0);
}

int				ft_recursion(t_opt *opt, char *dir_path, char *name)
{
	char				*str;
	t_data				*data;
	t_data				*tmp;

	data = NULL;
	if ((open_dir(&data, opt, dir_path, name)) == -1)
		return (-1);
	tmp = data;
	while (opt->big_r == 1 && tmp)
	{
		if (tmp->type == 'd' && ft_strcmp(tmp->name, ".")
				&& ft_strcmp(tmp->name, "..") && (opt->a == 1
					|| (opt->a != 1 && tmp->name[0] != '.')))
		{
			ft_display_name(opt, tmp->path);
			opt->link_len = 0;
			ft_recursion(opt, (str = format_path(dir_path, tmp->name,
							ft_strlen(tmp->name))), tmp->name);
		}
		tmp = tmp->next;
	}
	return (1);
}
