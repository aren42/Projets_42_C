/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 02:46:26 by aren              #+#    #+#             */
/*   Updated: 2016/03/18 02:46:28 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		draw_map(t_env *e)
{
	int		i;
	int		j;

	j = 0;
	while (j < e->map_y && j < WIN_H)
	{
		i = 0;
		while (i < e->map_x && i < WIN_W)
		{
			if (i < e->map_x - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j][i + 1]));
			if (j < e->map_y - 1)
				draw_line(e, &(e->map[j][i]), &(e->map[j + 1][i]));
			i++;
		}
		j++;
	}
}

void		draw_line(t_env *e, t_point *point1, t_point *point2)
{
	int		e2;
	t_point	pt;
	t_bres	*bres;

	bres = bresenham_struct(point1, point2, (e->max_z));
	pt.x = point1->tx;
	pt.y = point1->ty;
	while (1)
	{
		if ((check_x(e, pt.x) && check_y(e, pt.y)))
			draw_point(e, create_x(e, pt.x), create_y(e, pt.y), point1->color);
		if (pt.x == point2->tx && pt.y == point2->ty)
			break ;
		if ((e2 = bres->delta_error) > -(bres->delta_x))
		{
			bres->delta_error -= bres->delta_y;
			pt.x += bres->sign_x;
		}
		if (e2 < bres->delta_y)
		{
			bres->delta_error += bres->delta_x;
			pt.y += bres->sign_y;
		}
	}
	free(bres);
}

void		draw_point(t_env *e, int x, int y, int color)
{
	ft_memcpy(&e->data[(x * 4) + (y * e->sizeline)], &(color),
		(size_t)(sizeof(int)));
}

t_bres		*bresenham_struct(t_point *point1, t_point *point2, int max)
{
	t_bres	*bres;

	bres = (t_bres *)malloc(sizeof(t_bres));
	bres->delta_x = ft_abs(point2->tx - point1->tx);
	bres->sign_x = point1->tx < point2->tx ? 1 : -1;
	bres->delta_y = ft_abs(point2->ty - point1->ty);
	bres->sign_y = point1->ty < point2->ty ? 1 : -1;
	bres->delta_error = (bres->delta_x > bres->delta_y ? bres->delta_x :
		-(bres->delta_y)) / 2;
	point1->color = color_map(point1->z, point2->z, max);
	return (bres);
}

int			main(int ac, char **av)
{
	t_env	e;

	e.path = av[1];
	if (ac == 2)
		ft_insert_map(&e);
	else
		ft_putstr("Insert map!\n");
	return (0);
}
