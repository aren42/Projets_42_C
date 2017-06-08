/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools_opt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:07:41 by aren              #+#    #+#             */
/*   Updated: 2016/10/25 17:07:42 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_init_opt(t_opt *option)
{
	option->big_r = 0;
	option->l = 0;
	option->a = 0;
	option->r = 0;
	option->t = 0;
	option->o = 0;
	option->g = 0;
	option->p = 0;
	option->big_g = 0;
	option->nb_av = 0;
	option->owner_len = 0;
	option->group_len = 0;
	option->link_len = 0;
	option->major_len = 0;
	option->minor_len = 0;
	option->size_len = 0;
	option->total_blocks = 0;
	return (0);
}

static int	ft_push_opt(char push, t_opt *opt)
{
	opt->big_r = (push == 'R') ? 1 : opt->big_r;
	opt->l = (push == 'l') ? 1 : opt->l;
	opt->a = (push == 'a') ? 1 : opt->a;
	opt->r = (push == 'r') ? 1 : opt->r;
	opt->t = (push == 't') ? 1 : opt->t;
	opt->o = (push == 'o') ? 1 : opt->o;
	opt->g = (push == 'g') ? 1 : opt->g;
	opt->p = (push == 'p') ? 1 : opt->p;
	opt->big_g = (push == 'G') ? 1 : opt->big_g;
	return (0);
}

static int	ft_norme(int ct, char **av, t_opt *opt, int i)
{
	while (av[ct][0] == '-' && av[ct][i])
	{
		if (av[ct][i] != 'R' && av[ct][i] != 'l' && av[ct][i] != 'a' &&
			av[ct][i] != 'r' && av[ct][i] != 't' && av[ct][i] != 'o' &&
			av[ct][i] != 'g' && av[ct][i] != 'p' && av[ct][i] != 'G')
			ft_error(2, &av[ct][i]);
		ft_push_opt(av[ct][i], opt);
		i++;
	}
	return (0);
}

int			ft_get_opt(t_opt *opt, int *ac, char **av, int i)
{
	int		ct;

	ct = 0;
	while (++ct < *ac)
	{
		i = 1;
		if (av[1][0] == '-' && av[1][1] == '\0')
		{
			ft_error(4, "-");
			return (-1);
		}
		if (ft_strcmp(av[i], "--") == 0 && av[2] == '\0')
			continue ;
		if (ft_strcmp(av[i], "--") == 0 && av[2] != '\0')
		{
			ft_error(4, av[i]);
			break ;
		}
		ft_norme(ct, av, opt, i);
		if (av[ct][0] != '-')
			break ;
	}
	*ac -= ct;
	return (0);
}

int			ft_get_pwgr(struct passwd **pwd, struct group **grp, struct stat st)
{
	if ((*pwd = getpwuid(st.st_uid)) == NULL)
	{
		if ((*pwd = (struct passwd *)malloc(sizeof(struct passwd))) == NULL)
			ft_error(1, "owner info");
		(*pwd)->pw_name = ft_itoa(st.st_uid);
	}
	if ((*grp = getgrgid(st.st_gid)) == NULL)
	{
		if ((*grp = (struct group *)malloc(sizeof(struct group))) == NULL)
			ft_error(1, "group info");
		(*grp)->gr_name = ft_itoa(st.st_gid);
	}
	return (0);
}
