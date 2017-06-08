/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:32:41 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 14:56:42 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*tmp_dst;

	tmp_dst = dst;
	if (!len)
		return (dst);
	if (dst <= src || (unsigned char *)dst > ((unsigned char *)src + len))
		return (ft_memcpy(dst, src, len));
	else
	{
		dst = (unsigned char *)dst + len - 1;
		src = (unsigned char *)src + len - 1;
		while (len--)
			*(unsigned char *)dst-- = *(unsigned char *)src--;
	}
	return (tmp_dst);
}
