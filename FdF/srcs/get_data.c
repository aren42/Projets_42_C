/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 21:30:42 by aren              #+#    #+#             */
/*   Updated: 2016/03/17 21:30:43 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point		ft_create_point(char *str, int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = ft_atoi(str);
	return (point);
}

int			ft_check_number(char *str)
{
	while (*str)
	{
		if (ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

t_point		*ft_create_int_table(t_env *e, char *str, int pos)
{
	int		i;
	int		size;
	char	**split;
	t_point	*list;

	i = -1;
	if (ft_check_number(str))
		return (NULL);
	split = ft_strsplit(str, ' ');
	size = count_nb_col(split);
	e->map_x = (size > e->map_x) ? size : e->map_x;
	list = (t_point *)malloc(sizeof(t_point) * (e->map_x + 1));
	while (split[++i] != NULL)
	{
		e->max_z = ((ft_atoi(split[i])) > e->max_z) ? ft_atoi(split[i])
			: e->max_z;
		list[i] = ft_create_point(split[i], i, pos);
		free(split[i]);
	}
	return (list);
}

t_point		**ft_create_map(t_env *e)
{
	int		i;
	int		fd;
	char	*line;
	t_point	**grid;

	i = 0;
	e->map_x = 0;
	grid = (t_point **)malloc(sizeof(t_point *) * tab_len(e->path));
	if (!(fd = open(e->path, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) > 0)
	{
		grid[i] = ft_create_int_table(e, line, i);
		free(line);
		i++;
	}
	grid[i] = ft_create_int_table(e, line, i);
	free(line);
	close(fd);
	e->map_y = count_nb_line(grid);
	return (grid);
}
