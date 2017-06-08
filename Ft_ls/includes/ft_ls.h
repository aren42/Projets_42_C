/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 17:38:26 by aren              #+#    #+#             */
/*   Updated: 2016/10/08 17:38:28 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef	struct		s_opt
{
	int				big_r;
	int				big_g;
	int				l;
	int				a;
	int				r;
	int				t;
	int				o;
	int				g;
	int				p;
	int				nb_av;
	int				owner_len;
	int				group_len;
	int				link_len;
	int				major_len;
	int				minor_len;
	int				size_len;
	blkcnt_t		total_blocks;
	int				first_dir;
	int				linkspace;
}					t_opt;

typedef	struct		s_data
{
	char			*path;
	char			*name;
	char			type;
	char			mode[13];
	char			*nblink;
	char			*link;
	char			*owner;
	char			*group;
	char			*size;
	char			*date;
	char			*year;
	int				epoc;
	char			*major;
	char			*minor;
	int				fsize_len;
	struct s_data	*next;
	blkcnt_t		block;
}					t_data;

/*
** Tools opt
*/
int					ft_init_opt(t_opt *option);
int					ft_get_opt(t_opt *opt, int *ac, char **av, int i);
int					ft_get_pwgr(struct passwd **pwd, struct group **grp,
					struct stat st);
char				put_mode_end(t_data *list);
int					ft_display_colors_big_g(t_data **lst);
int					ft_display_colors_big_g_v2(t_data **lst);

/*
** Permissions
*/
char				ft_file_type(struct stat buff_stat);
int					ft_file_mode(t_data **lst, struct stat buff_stat);

/*
** Infos
*/
int					ft_tools_name(t_opt *opt, t_data **lst, int ac, char **av);
char				*format_path(char *path, char *filename, int name_len);
int					ft_get_time(t_data **lst, struct stat st);
int					ft_file_info(char *path, char *name, t_opt *option,
					t_data **lst);

/*
** Tools dir
*/
int					ft_recursion(t_opt *opt, char *dir_path, char *name);

/*
** Tools lst
*/
t_data				*ft_init_lst(char *name, char *fpath, t_opt **option);
int					ft_lst_insert(t_opt *option, t_data **lst, t_data *new);
int					ft_lst_time_insert(t_opt *opt, t_data **lst, t_data *new);

/*
** Display
*/
int					ft_display_name(t_opt *opt, char *str);
int					ft_display(t_data **lst, t_opt *opt);
int					ft_ls_display(t_opt *opt, t_data **lst);
int					ft_display_total(t_opt **opt, int i);
int					ft_long_display(t_data **lst, t_opt *opt);

/*
** Tools
*/
int					ft_error(int error, char *pb);
int					ft_put_space(char *str, int lenght);
void				ft_putnbrendl(int n);
int					free_s_data(t_data **lst);

#endif
