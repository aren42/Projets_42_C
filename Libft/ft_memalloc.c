/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 22:47:13 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 14:52:41 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*mem;

	if (size == 0)
		return ((void *)0);
	mem = malloc(size * sizeof(void *));
	if (mem == NULL)
		return (NULL);
	if (mem)
		ft_bzero(mem, size);
	return (mem);
}
