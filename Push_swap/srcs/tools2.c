/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/22 14:21:55 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int			ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

void		ft_error_str_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

void		ft_str_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int			ft_getnbr(char *str)
{
	int		i;
	int		nb;
	int		neg;

	i = 0;
	nb = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			nb++;
	}
	if (nb % 2 == 0)
		neg = 1;
	else
		neg = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - 48;
		i++;
	}
	if (str[i] && ft_isdigit(str[i]) == 0)
		ft_error_str_exit("Error\n");
	return (neg * nb);
}
