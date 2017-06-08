/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 19:47:56 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 00:23:08 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		o;
	char	*tmp;

	if (s)
	{
		i = 0;
		j = ft_strlen((char *)s) - 1;
		o = 0;
		if ((tmp = (char *)malloc(sizeof(char) * (j - i + 1))) == NULL)
			return (NULL);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		while (i <= j)
			tmp[o++] = s[i++];
		tmp[o] = '\0';
		return (tmp);
	}
	return (NULL);
}
