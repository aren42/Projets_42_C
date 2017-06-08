/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:30:50 by aren              #+#    #+#             */
/*   Updated: 2014/11/18 16:48:51 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** La fonction memccpy copie au plus n octets de la zone mémoire src vers
** la zone mémoire dst, s'arrêtant dès qu'elle rencontre le caractère c.
** Si les zones mémoires se chevauchent, le résultat est indéfini.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n > 0 && dst && src)
	{
		*(unsigned char *)dst++ = *(unsigned char *)src;
		if (*(unsigned char *)src == (unsigned char)c)
			return (dst);
		src++;
		n--;
	}
	return (NULL);
}
