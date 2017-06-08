/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:29:58 by aren              #+#    #+#             */
/*   Updated: 2016/03/17 21:30:00 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			count_nb_line(t_point **grid)
{
	int		i;

	i = 0;
	while (grid[i] != NULL)
		i++;
	return (i);
}

int			count_nb_col(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int			tab_len(char *av)
{
	int		fd;
	char	*buff;
	int		ret;
	int		size;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		exit(1);
	buff = (char *)ft_strnew(200);
	size = 0;
	while ((ret = read(fd, buff, 200)) > 0)
	{
		if (ret == -1)
			exit(1);
		size += ret;
	}
	close(fd);
	free(buff);
	return (size);
}

void		ft_reset(t_env *e)
{
	ft_bzero(e->data, WIN_W * WIN_H * 4);
	expose_hook(e);
}

void		default_mode(t_env *e)
{
	e->size = 20;
	e->height = 5;
	e->move_x = 1;
	e->move_y = 1;
	e->angle = 0;
	ft_reset(e);
}
