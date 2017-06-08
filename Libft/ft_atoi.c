/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:27:12 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 10:28:41 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int		neg;
	int		nbr;

	nbr = 0;
	neg = 0;
	if (!str)
		return (0);
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r')
		++str;
	if (*str == '-' || *str == '+')
		neg = (*str++ == '-') ? 1 : 0;
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str++ - 48;
	}
	return ((neg) ? nbr * -1 : nbr);
}
