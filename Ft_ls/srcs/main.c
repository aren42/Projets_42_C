/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 17:38:26 by aren              #+#    #+#             */
/*   Updated: 2016/10/08 17:38:28 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_error(int error, char *pb)
{
	if (error == 1)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(pb);
		exit(EXIT_FAILURE);
	}
	if (error == 2)
	{
		ft_putstr_fd("ft_ls: illegal option -- ", 2);
		ft_putchar_fd(*pb, 2);
		ft_putendl_fd("\nusage: ft_ls [-RlartogpG] [file ...]", 2);
		exit(EXIT_FAILURE);
	}
	if (error == 3)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(pb);
	}
	if (error == 4)
	{
		ft_putstr_fd("ft_ls: -: No such file or directory\n", 2);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int			i;
	t_data		*lst;
	t_opt		option;

	i = 0;
	lst = NULL;
	ft_init_opt(&option);
	ft_get_opt(&option, &ac, av, i);
	option.nb_av = ac;
	ft_tools_name(&option, &lst, ac, av);
	ft_display(&lst, &option);
	return (0);
}
