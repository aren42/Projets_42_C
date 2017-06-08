/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 23:21:57 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 17:23:39 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_tabsize(char *s, char c)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int	ft_len(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

static char	*ft_newstr(char *s, char *s2, char c, int start)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	**ft_newtab(char **tab, char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i])
	{
		len = ft_len(s, c, start);
		if ((tab[j] = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		if (tab[j])
		{
			tab[j] = ft_newstr(s, tab[j], c, start);
			j++;
			i += ft_len(s, c, start);
			while (s[i] == c && s[i])
				i++;
			start = i;
		}
		else
			return (NULL);
	}
	tab[j] = NULL;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_tabsize((char *)s, c);
		if ((tab = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
			return (NULL);
		i = 0;
		if (tab)
		{
			while (s[i] == c && s[i])
				i++;
			tab = ft_newtab(tab, (char *)s, c, i);
			return (tab);
		}
		return (NULL);
	}
	return (NULL);
}
