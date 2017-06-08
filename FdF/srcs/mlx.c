/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 02:04:15 by aren              #+#    #+#             */
/*   Updated: 2016/03/18 02:04:16 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include "../minilibx_macos/mlx.h"

void		put_info_command(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 1300, 100, 0xCC6699, "Control Panel :");
	mlx_string_put(e->mlx, e->win, 1300, 150, 0xCC6699, "To move : Arrow keys");
	mlx_string_put(e->mlx, e->win, 1300, 170, 0xCC6699, "To zoom : + , -");
	mlx_string_put(e->mlx, e->win, 1300, 190, 0xCC6699, "To rotation : / , *");
	mlx_string_put(e->mlx, e->win, 1300, 210, 0xCC6699,
			"To change Z : mouse 1 , mouse 3");
	mlx_string_put(e->mlx, e->win, 1300, 230, 0xCC6699,
			"Default value : D");
}

int			expose_hook(t_env *e)
{
	calcule_coord(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	put_info_command(e);
	return (0);
}

int			key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
	if (keycode == 69)
		zoom_map(e);
	if (keycode == 78)
		dezoom_map(e);
	if (keycode == 126)
		move_image_up(e);
	if (keycode == 125)
		move_image_down(e);
	if (keycode == 123)
		move_image_left(e);
	if (keycode == 124)
		move_image_right(e);
	if (keycode == 75)
		rotation_left(e);
	if (keycode == 67)
		rotation_right(e);
	if (keycode == 2)
		default_mode(e);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == 1)
	{
		e->height = (e->height + 1.2 <= 0) ? e->height : e->height + 1.2;
		ft_reset(e);
	}
	if (button == 2)
	{
		e->height = (e->height - 1.2 <= 0) ? e->height : e->height - 1.2;
		ft_reset(e);
	}
	(void)x;
	(void)y;
	return (0);
}

void		ft_insert_map(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_W, WIN_H, "FdF");
	e->size = 20;
	e->height = 5;
	e->move_x = 1;
	e->move_y = 1;
	e->angle = 0;
	e->img = mlx_new_image(e->mlx, WIN_W, WIN_H);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline),
		&(e->endian));
	e->map = ft_create_map(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}
