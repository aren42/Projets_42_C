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

int				ft_display_colors_big_g(t_data **lst)
{
	if ((*lst)->mode[0] == 'd')
		ft_putstr("\033[1;36m");
	if ((*lst)->mode[0] == 'l')
		ft_putstr("\033[0;35m");
	if ((*lst)->mode[0] == 'b')
		ft_putstr("\033[0;34;46m");
	if ((*lst)->mode[0] == 'c')
		ft_putstr("\033[0;34;43m");
	if ((*lst)->mode[0] == 'p')
		ft_putstr("\033[0;33m");
	if ((*lst)->mode[0] == 's')
		ft_putstr("\033[0;37m");
	return (0);
}

int				ft_display_colors_big_g_v2(t_data **lst)
{
	if ((*lst)->mode[0] == '-' && ((*lst)->mode[3] == 'x' ||
				(*lst)->mode[6] == 'x' || (*lst)->mode[9] == 'x'))
		ft_putstr("\033[0;31m");
	if ((*lst)->mode[0] == 'd' && ((*lst)->mode[2] == 'w' &&
				(*lst)->mode[5] == 'w' && (*lst)->mode[8] == 'w'))
		ft_putstr("\033[0;30;43m");
	if ((*lst)->mode[0] == 's')
		ft_putstr("\033[0;32m");
	if ((*lst)->mode[3] == 's' || (*lst)->mode[6] == 's')
		ft_putstr("\033[0;30;41m");
	if ((*lst)->mode[3] == 'S' || (*lst)->mode[6] == 'S')
		ft_putstr("\033[0;46m");
	if ((*lst)->mode[9] == 't')
	{
		if ((*lst)->mode[8] == '-')
			ft_putstr("\033[1;36m");
		else
			ft_putstr("\033[0;30;42m");
	}
	return (0);
}
