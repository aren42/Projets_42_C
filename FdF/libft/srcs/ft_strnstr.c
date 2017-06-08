/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 21:41:49 by aren              #+#    #+#             */
/*   Updated: 2014/11/11 21:41:50 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			size2;
	const char		*tmp1;
	const char		*tmp2;

	size2 = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char *)s1);
	while (n && *s1 != '\0')
	{
		if (n < size2)
			return (NULL);
		tmp2 = s2;
		tmp1 = s1;
		while (*tmp1 && *tmp2 && *tmp1 == *tmp2)
		{
			tmp1++;
			tmp2++;
		}
		if (*tmp2 == '\0')
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
