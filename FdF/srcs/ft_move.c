/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 03:29:12 by aren              #+#    #+#             */
/*   Updated: 2016/01/28 05:08:19 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_image_up(t_env *e)
{
	e->move_y -= 10;
	ft_reset(e);
}

void	move_image_down(t_env *e)
{
	e->move_y += 10;
	ft_reset(e);
}

void	move_image_left(t_env *e)
{
	e->move_x -= 10;
	ft_reset(e);
}

void	move_image_right(t_env *e)
{
	e->move_x += 10;
	ft_reset(e);
}
