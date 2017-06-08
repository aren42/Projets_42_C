/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_opt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:00:52 by aren              #+#    #+#             */
/*   Updated: 2016/11/09 17:00:54 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_display_majmin(t_data **lst, t_opt **opt)
{
	int			i;
	int			j;
	int			size;
	char		*tmp;
	char		len[(*opt)->minor_len + 1];

	i = -1;
	j = -1;
	len[(*opt)->minor_len] = '\0';
	size = ((*opt)->minor_len - ft_strlen((*lst)->minor));
	while (++i < size)
		len[i] = ' ';
	while ((*lst)->minor[++j])
		len[i++] = (*lst)->minor[j];
	if ((tmp = ft_strjoin((*lst)->major, len)) == NULL)
		ft_error(3, (*lst)->major);
	if (((*lst)->size = ft_strdup(tmp)) == NULL)
		ft_error(3, tmp);
	(*lst)->fsize_len = ft_strlen((*lst)->size);
	if (((*opt)->a == 1 || ((*opt)->a == 0 && (*lst)->name[0] != '.'))
			&& (*lst)->fsize_len > (*opt)->size_len)
		(*opt)->size_len = (*lst)->fsize_len;
	ft_strdel(&tmp);
	return (0);
}

static int		ft_display_size_and_date(t_data **lst, t_opt *opt)
{
	ft_put_space((*lst)->size, opt->size_len);
	ft_putstr((*lst)->size);
	ft_putchar(' ');
	ft_putstr((*lst)->date);
	ft_putstr((*lst)->year);
	ft_putchar(' ');
	return (0);
}

char			put_mode_end(t_data *list)
{
	char	buf[256];

	if (listxattr(list->path, buf, 256, XATTR_NOFOLLOW) > 0)
		return ('@');
	else if (acl_get_file(list->path, ACL_TYPE_EXTENDED))
		return ('+');
	else
		return (' ');
}

int				ft_long_display(t_data **lst, t_opt *opt)
{
	ft_putstr((*lst)->mode);
	ft_put_space((*lst)->nblink, (opt->link_len));
	ft_putstr((*lst)->nblink);
	ft_putchar(' ');
	if (opt->g == 0)
	{
		ft_putstr((*lst)->owner);
		ft_put_space((*lst)->owner, (opt->owner_len + 2));
	}
	if (opt->o == 0)
	{
		ft_putstr((*lst)->group);
		ft_put_space((*lst)->group, (opt->group_len + 2));
	}
	if (opt->o == 1 && opt->g == 1)
		ft_putstr("  ");
	if ((opt->a == 1 || (opt->a == 0 && (*lst)->name[0] != '.'))
			&& ((*lst)->type == 'b' || (*lst)->type == 'c'))
		ft_display_majmin(lst, &opt);
	ft_display_size_and_date(lst, opt);
	return (0);
}

int				ft_display_total(t_opt **opt, int i)
{
	if (i > 0 && ((*opt)->l == 1 || (*opt)->o == 1
				|| (*opt)->g == 1))
	{
		ft_putstr("total ");
		ft_putnbr((*opt)->total_blocks);
		ft_putchar('\n');
	}
	(*opt)->total_blocks = 0;
	return (0);
}
