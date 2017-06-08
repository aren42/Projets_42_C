/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_infos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:05:32 by aren              #+#    #+#             */
/*   Updated: 2016/11/04 12:05:33 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_minmaj(struct stat st, t_opt **opt, t_data **lst)
{
	int		i;
	char	*maj;
	char	*tmp;

	maj = ft_itoa(major(st.st_rdev));
	tmp = ft_strjoin(maj, ", ");
	(*lst)->major = ft_strdup(tmp);
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
		&& (i = ft_strlen((*lst)->major)) > (*opt)->major_len)
		(*opt)->major_len = i;
	(*lst)->minor = ft_itoa(minor(st.st_rdev));
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
		&& (i = ft_strlen((*lst)->minor)) > (*opt)->minor_len)
		(*opt)->minor_len = i;
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
		&& (i = (*opt)->major_len + (*opt)->minor_len + 1) > (*opt)->size_len)
		(*opt)->size_len = i;
	ft_strdel(&maj);
	ft_strdel(&tmp);
	return (0);
}

static int		ft_file_size(t_data **lst, t_opt **opt, struct stat st)
{
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& ((*lst)->type == 'b' || (*lst)->type == 'c'))
		ft_minmaj(st, opt, lst);
	else
	{
		(*lst)->size = ft_itoa(st.st_size);
		(*lst)->fsize_len = ft_strlen((*lst)->size);
	}
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (*lst)->fsize_len > (*opt)->size_len)
		(*opt)->size_len = (*lst)->fsize_len;
	return (0);
}

static int		ft_type_l(t_data **lst)
{
	int					re;
	char				*tmp;
	char				lbuff[1024];

	tmp = NULL;
	if ((re = readlink((*lst)->path, lbuff, 1023)) == -1)
	{
		ft_error(3, (tmp = ft_strjoin("read symbolic link ", (*lst)->name)));
		return (-1);
	}
	else
	{
		lbuff[re] = '\0';
		(*lst)->link = ft_strdup(lbuff);
	}
	free(tmp);
	return (0);
}

static int		ft_option_l(struct stat st, char *pwgr[], t_data **lst,
				t_opt **opt)
{
	int					tmp;

	(*lst)->owner = ft_strdup(pwgr[0]);
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (tmp = ft_strlen((*lst)->owner)) > (*opt)->owner_len)
		(*opt)->owner_len = tmp;
	(*lst)->group = ft_strdup(pwgr[1]);
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (tmp = ft_strlen((*lst)->group)) > (*opt)->group_len)
		(*opt)->group_len = tmp;
	ft_file_size(lst, opt, st);
	(*lst)->nblink = ft_itoa(st.st_nlink);
	if ((*opt)->a == 1 || ((*opt)->a != 1 && (*lst)->name[0] != '.'))
		(*lst)->block = st.st_blocks;
	(*opt)->total_blocks += (*lst)->block;
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (tmp = ft_strlen((*lst)->nblink)) > (*opt)->link_len)
		(*opt)->link_len = tmp;
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (*lst)->type == 'l')
		if ((tmp = ft_type_l(lst)) == -1)
			return (-1);
	return (0);
}

int				ft_file_info(char *path, char *name, t_opt *opt, t_data **lst)
{
	struct stat			st;
	struct passwd		*pwd;
	struct group		*grp;
	char				*pwgr[2];

	if (lstat(path, &st) == -1)
	{
		ft_error(3, name);
		return (-1);
	}
	(*lst)->type = ft_file_type(st);
	ft_file_mode(lst, st);
	if (opt->l == 1 || opt->t == 1 || opt->g == 1 || opt->o == 1)
		ft_get_time(lst, st);
	if (opt->l == 1 || opt->o == 1 || opt->g == 1)
	{
		ft_get_pwgr(&pwd, &grp, st);
		pwgr[0] = pwd->pw_name;
		pwgr[1] = grp->gr_name;
		if (ft_option_l(st, pwgr, lst, &opt) == -1)
			return (-1);
	}
	return (S_ISDIR(st.st_mode));
}
