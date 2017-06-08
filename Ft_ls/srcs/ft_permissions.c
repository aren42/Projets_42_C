/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permissions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 16:11:20 by aren              #+#    #+#             */
/*   Updated: 2016/10/25 16:11:23 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char		ft_get_uid(struct stat st)
{
	char	ret;

	ret = (st.st_mode & S_IXUSR) ? 'x' : '-';
	if (ret == 'x' && (st.st_mode & S_ISUID))
		ret = 's';
	else if (ret == '-' && (st.st_mode & S_ISUID))
		ret = 'S';
	return (ret);
}

static char		ft_get_gid(struct stat st)
{
	char	ret;

	ret = (st.st_mode & S_IXGRP) ? 'x' : '-';
	if (ret == 'x' && (st.st_mode & S_ISGID))
		ret = 's';
	else if (ret == '-' && (st.st_mode & S_ISGID))
		ret = 'S';
	return (ret);
}

static char		ft_get_vtx(struct stat st)
{
	char	ret;

	ret = (st.st_mode & S_IXOTH) ? 'x' : '-';
	if (ret == 'x' && (st.st_mode & S_ISVTX))
		ret = 't';
	else if (ret == '-' && (st.st_mode & S_ISVTX))
		ret = 'T';
	return (ret);
}

int				ft_file_mode(t_data **lst, struct stat st)
{
	(*lst)->mode[0] = (*lst)->type;
	(*lst)->mode[1] = (st.st_mode & S_IRUSR) ? 'r' : '-';
	(*lst)->mode[2] = (st.st_mode & S_IWUSR) ? 'w' : '-';
	(*lst)->mode[3] = ft_get_uid(st);
	(*lst)->mode[4] = (st.st_mode & S_IRGRP) ? 'r' : '-';
	(*lst)->mode[5] = (st.st_mode & S_IWGRP) ? 'w' : '-';
	(*lst)->mode[6] = ft_get_gid(st);
	(*lst)->mode[7] = (st.st_mode & S_IROTH) ? 'r' : '-';
	(*lst)->mode[8] = (st.st_mode & S_IWOTH) ? 'w' : '-';
	(*lst)->mode[9] = ft_get_vtx(st);
	(*lst)->mode[10] = put_mode_end(*lst);
	(*lst)->mode[11] = ' ';
	(*lst)->mode[12] = '\0';
	return (0);
}

char			ft_file_type(struct stat st)
{
	char				type;

	if (S_ISBLK(st.st_mode))
		type = 'b';
	else if (S_ISREG(st.st_mode))
		type = '-';
	else if (S_ISCHR(st.st_mode))
		type = 'c';
	else if (S_ISDIR(st.st_mode))
		type = 'd';
	else if (S_ISFIFO(st.st_mode))
		type = 'p';
	else if (S_ISLNK(st.st_mode))
		type = 'l';
	else if (S_ISSOCK(st.st_mode))
		type = 's';
	else
		type = '?';
	return (type);
}
