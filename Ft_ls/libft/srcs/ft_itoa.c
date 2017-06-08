/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 14:48:56 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 15:12:29 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

static int		nb(int x)
{
	if (x < 0)
		return (1 + nb(-x));
	if (x < 10)
		return (1);
	return (1 + nb(x / 10));
}

char			*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = (n < 0 ? 1 : 0);
	len = nb(n);
	if ((str = (char *)malloc(sizeof(*str) * (len + 1))) == NULL)
		return (NULL);
	if (str)
	{
		n = (n < 0 ? -n : n);
		i = len - 1;
		while (i >= neg)
		{
			str[i--] = (n % 10) + 48;
			n /= 10;
		}
		if (neg)
			str[0] = '-';
		str[len] = '\0';
	}
	return (str);
}
