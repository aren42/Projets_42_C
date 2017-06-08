/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 16:18:20 by aren              #+#    #+#             */
/*   Updated: 2014/12/17 16:18:21 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*load;
	size_t	i;

	i = 0;
	load = (char *)malloc(size * sizeof(*load));
	if (load == NULL)
		return (NULL);
	while (i < size)
	{
		((char *)load)[i] = 0;
		i++;
	}
	return (load);
}
