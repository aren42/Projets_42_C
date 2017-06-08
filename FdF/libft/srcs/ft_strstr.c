/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 23:13:31 by aren              #+#    #+#             */
/*   Updated: 2014/11/08 23:13:31 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *tmp1;
	const char *tmp2;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
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
	}
	return (NULL);
}
