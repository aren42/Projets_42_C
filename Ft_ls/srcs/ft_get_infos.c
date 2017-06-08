/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_infos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 18:26:29 by aren              #+#    #+#             */
/*   Updated: 2016/11/01 18:26:31 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int				ft_get_time(t_data **lst, struct stat st)
{
	int				today;
	char			*tmp;
	char			*str;

	str = NULL;
	today = time(NULL);
	tmp = ctime(&st.st_mtime);
	(*lst)->epoc = st.st_mtime;
	if (((*lst)->date = ft_strsub(tmp, 4, 7)) == NULL)
		ft_error(3, tmp);
	if (((*lst)->year = ((today - (*lst)->epoc) > 15768000 ?
					ft_strjoin(" ", (str = ft_strsub(tmp, 20, 4))) :
					ft_strsub(tmp, 11, 5))) == NULL)
		ft_error(3, tmp);
	free(str);
	return (0);
}

static int		ft_first_link(char *str, t_opt *opt, t_data **new)
{
	char			*tmp;
	char			*t2;

	tmp = NULL;
	t2 = NULL;
	if (str[0] == '/')
	{
		if ((*new = ft_init_lst(str, str, &opt)) == NULL)
			return (-1);
	}
	else
	{
		if ((t2 = ft_strdup(str)) == NULL)
			ft_error(3, str);
		tmp = format_path("./", t2, ft_strlen(str));
		if ((*new = ft_init_lst(str, tmp, &opt)) == NULL)
			return (-1);
		ft_strdel(&tmp);
	}
	return (0);
}

int				ft_tools_name(t_opt *opt, t_data **lst, int ac, char **av)
{
	int			i;
	t_data		*new;

	i = 1;
	if (ac == 0)
		if (ft_recursion(opt, "./", ".") == -1)
			return (-1);
	while (av[i] && av[i][0] == '-')
		i++;
	while (av[i])
	{
		if ((ft_first_link(av[i], opt, &new)) == -1)
		{
			i++;
			continue ;
		}
		if (*lst == NULL && new)
			*lst = new;
		else if (opt->t == 1 && new)
			ft_lst_time_insert(opt, lst, new);
		else if (new)
			ft_lst_insert(opt, lst, new);
		i++;
	}
	return (0);
}

char			*format_path(char *path, char *filename, int name_len)
{
	char			*tmp;
	char			*final_path;
	int				path_len;

	tmp = NULL;
	path_len = ft_strlen(path);
	if (filename[name_len - 1] == '/')
		filename[name_len - 1] = '\0';
	if (path_len > 0 && path[path_len - 1] != '/')
	{
		if ((tmp = ft_strjoin(path, "/")) == NULL)
			ft_error(1, path);
	}
	else if (path_len > 0)
	{
		if ((tmp = ft_strdup(path)) == NULL)
			ft_error(1, path);
	}
	if (((final_path = ft_strjoin(tmp, filename)) == NULL))
		ft_error(1, filename);
	free(tmp);
	return (final_path);
}
