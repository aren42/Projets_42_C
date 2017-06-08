/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 01:20:22 by aren              #+#    #+#             */
/*   Updated: 2016/01/28 05:08:13 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		rotation_left(t_env *e)
{
	e->angle -= 0.05;
	ft_reset(e);
}

void		rotation_right(t_env *e)
{
	e->angle += 0.05;
	ft_reset(e);
}

void		zoom_map(t_env *e)
{
	e->size = e->size + 1;
	ft_reset(e);
}

void		dezoom_map(t_env *e)
{
	e->size = e->size - 1;
	ft_reset(e);
}
