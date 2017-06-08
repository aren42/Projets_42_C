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

void			ft_putchar(char c, int nb)
{
	static int	first_space = 0;

	if (first_space || c != ' ')
		write(nb, &c, 1);
	first_space = 1;
	return ;
}

int				ft_strlen(char *str)
{
	int			i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void			ft_putstr_fd(char *str, int fd)
{
	int			i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++], fd);
}

int				ft_strcmp(const char *s1, const char *s2)
{
	int			i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
