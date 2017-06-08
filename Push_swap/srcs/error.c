/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:17:50 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void				ft_check_max_int(char *av)
{
	int				i;
	char			*str;

	i = 0;
	str = "2147483647";
	if (ft_strlen(av) == ft_strlen(str))
	{
		while (av[i] && str[i])
		{
			if (av[i] > str[i])
				ft_error_str_exit("Error\n");
			i++;
		}
	}
}

void				ft_check_min_int(char *av)
{
	int				i;
	char			*nstr;

	i = 0;
	nstr = "2147483648";
	if (ft_strlen(av) == ft_strlen(nstr))
	{
		while (av[i] && nstr[i])
		{
			if (av[i] > nstr[i])
				ft_error_str_exit("Error\n");
			i++;
		}
	}
}

void				ft_check_overflow(char *av)
{
	unsigned int	i;
	int				neg;

	i = 0;
	neg = 0;
	if (*av == '-')
	{
		neg = 1;
		av++;
	}
	if (ft_strlen(av) > ft_strlen("2147483647"))
		ft_error_str_exit("Error\n");
	if (ft_strlen(av) == ft_strlen("2147483647"))
	{
		if (neg == 1)
			ft_check_min_int(av);
		else
			ft_check_max_int(av);
	}
	while (ft_isdigit(av[i]))
		++i;
	if (av[i])
		ft_error_str_exit("Error\n");
}

unsigned char		ft_check_params(int ac, char **av)
{
	int				i;
	int				tmp;

	if (ac < 2)
		exit(1);
	validate_arguments(ac, av);
	i = 1;
	while (ac > i)
		ft_check_overflow(av[i++]);
	tmp = 1;
	while (ac > tmp)
	{
		i = 2;
		while (i < ac && i != tmp)
		{
			if (!ft_strcmp(av[i], av[tmp]))
				ft_error_str_exit("Error\n");
			++i;
		}
		++tmp;
	}
	return (0);
}
