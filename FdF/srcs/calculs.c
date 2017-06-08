/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 03:00:03 by aren              #+#    #+#             */
/*   Updated: 2016/03/18 03:00:04 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			calculate(t_env *e, t_point *pt)
{
	float		act_px;
	float		act_py;
	float		act_pz;
	float		px;
	float		py;

	act_px = pt->x * e->size;
	act_py = pt->y * e->size;
	act_pz = pt->z * e->height;
	px = act_px * cos(e->angle) - act_py * sin(e->angle);
	py = act_px * sin(e->angle) + act_py * cos(e->angle);
	pt->tx = px - py + WIN_W * 0.3;
	pt->ty = px * 0.5 + py * 0.5 - act_pz + WIN_H * 0.3;
}

void			calcule_coord(t_env *e)
{
	int			i;
	int			j;

	j = 0;
	while (j < e->map_y)
	{
		i = 0;
		while (i < e->map_x)
		{
			calculate(e, &(e->map[j][i]));
			i++;
		}
		j++;
	}
	draw_map(e);
}

int				color_map(int a, int b, int max)
{
	if (((a + b) / 2) > (max * 0.8))
		return (PINK);
	else if (((a + b) / 2) == 0)
		return (BLUE);
	else if (((a + b) / 2) < 0)
		return (WHITE);
	else
		return (PURPLE);
}
