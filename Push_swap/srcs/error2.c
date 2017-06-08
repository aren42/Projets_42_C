/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:15:39 by aren              #+#    #+#             */
/*   Updated: 2016/03/26 23:17:50 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int					is_just_troll(char *str)
{
	int				check;

	check = (str[0] == '\0' || (str[0] == '-' && !ft_isdigit(str[1])));
	return (check);
}

int					ft_is_valid_int(char *string)
{
	if (is_just_troll(string))
		return (0);
	return (1);
}

void				validate_arguments(int len, char **args)
{
	int				i;

	i = 0;
	while (i < len)
	{
		if (!ft_is_valid_int(args[i]))
			ft_error_str_exit("Error\n");
		i++;
	}
}
