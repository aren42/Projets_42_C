/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 02:51:35 by aren              #+#    #+#             */
/*   Updated: 2016/03/19 02:51:36 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			check_x(t_env *e, int x)
{
	if ((x + e->move_x) < WIN_W && (x + e->move_x) > 0)
		return (1);
	return (0);
}

int			check_y(t_env *e, int y)
{
	if ((y + e->move_y) < WIN_H && (y + e->move_y) > 0)
		return (1);
	return (0);
}

int			create_x(t_env *e, int x)
{
	return (x + e->move_x);
}

int			create_y(t_env *e, int y)
{
	return (y + e->move_y);
}
