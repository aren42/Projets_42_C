/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 03:33:00 by aren              #+#    #+#             */
/*   Updated: 2014/11/15 14:57:00 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	void	*tmp_b;

	tmp_b = b;
	while (len--)
		*(unsigned char *)b++ = (unsigned char)c;
	return (tmp_b);
}
