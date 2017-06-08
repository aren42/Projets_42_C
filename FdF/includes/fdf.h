/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <aren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:19:56 by aren              #+#    #+#             */
/*   Updated: 2016/01/28 05:09:02 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <math.h>

# define WIN_H 1200
# define WIN_W 1900

# define BLUE 0x0041FF
# define PINK 0xFF66CC
# define PURPLE 0x9966FF
# define WHITE 0xFFFFFF

typedef	struct	s_point
{
	int			color;
	int			x;
	int			y;
	int			z;
	int			tx;
	int			ty;
}				t_point;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	char		*path;
	int			size;
	int			height;
	int			move_x;
	int			move_y;
	int			map_x;
	int			map_y;
	int			max_z;
	t_point		**map;
	float		angle;
	int			sizeline;
	int			endian;
	int			bpp;
}				t_env;

typedef	struct	s_bres
{
	int			delta_x;
	int			delta_y;
	int			sign_x;
	int			sign_y;
	int			delta_error;
}				t_bres;

/*
** Draw & calculs
*/
t_bres			*bresenham_struct(t_point *point1, t_point *point2, int max);
void			draw_point(t_env *e, int x, int y, int color);
void			draw_line(t_env *e, t_point *point1, t_point *point2);
void			draw_map(t_env *e);
int				color_map(int point1, int point2, int max);
void			calcule_coord(t_env *e);
void			calculate(t_env *e, t_point *pt);

/*
** Display command, mouse and option
*/
void			put_info_command(t_env *e);
void			zoom_map(t_env *e);
void			dezoom_map(t_env *e);
void			move_image_up(t_env *e);
void			move_image_down(t_env *e);
void			move_image_left(t_env *e);
void			move_image_right(t_env *e);
void			rotation_left(t_env *e);
void			rotation_right(t_env *e);

/*
** Parsing and Tools
*/
t_point			ft_create_point(char *str, int x, int y);
t_point			*ft_create_int_table(t_env *e, char *str, int pos);
t_point			**ft_create_map(t_env *e);
int				ft_check_number(char *str);
int				count_nb_line(t_point **line);
int				count_nb_col(char **str);
int				tab_len(char *av);
void			ft_reset(t_env *e);
void			default_mode(t_env *e);

/*
** Points
*/
int				check_x(t_env *e, int x);
int				check_y(t_env *e, int y);
int				create_x(t_env *e, int x);
int				create_y(t_env *e, int y);

/*
** Events
*/
void			ft_insert_map(t_env *e);
int				expose_hook(t_env *e);
int				key_hook(int keycode, t_env *e);
int				mouse_hook(int button, int x, int y, t_env *e);

#endif
