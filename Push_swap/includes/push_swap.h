/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aren <aren@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 16:19:56 by aren              #+#    #+#             */
/*   Updated: 2016/01/28 05:09:02 by aren             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

/*
** Main
*/
int					ft_ok_next(t_list *list);
t_list				*ft_push_swap(t_list *la, t_list *lb);

/*
** Special cases
*/
void				ft_swap(t_list *list);
void				ft_check_three_params(t_list *list);
int					ft_check_only_one_sa(t_list *list);
int					ft_check_sa_at_the_top(t_list *list);
int					ft_check_sa_at_the_end(t_list *list);
void				ft_end_op(t_list *list, t_list *tmp, t_list *str, int i);

/*
**	Tools
*/
void				ft_putchar(char c, int nb);
int					ft_strlen(char *str);
void				ft_putstr_fd(char *str, int fd);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_isdigit(int c);
int					ft_isdigitstr(char *str);
int					ft_getnbr(char *str);
void				ft_str_exit(char *str);

/*
**	Operators tools
*/
t_list				*init_list(void);
void				remove_first_elem(t_list *list);
void				remove_last_elem(t_list *list);
void				add_start_elem(int data, t_list *list);
void				add_end_elem(int data, t_list *list);

/*
**	Operators
*/
void				sa(t_list *lst);
void				sb(t_list *lst);
void				ss(t_list *a, t_list *b);
void				pa(t_list *a, t_list *b);
void				pb(t_list *a, t_list *b);
void				ra(t_list *list);
void				rb(t_list *list);
void				rr(t_list *a, t_list *b);
void				rra(t_list *list);
void				rrb(t_list *list);
void				rrr(t_list *a, t_list *b);

/*
** Params & errors
*/
void				ft_error_str_exit(char *str);
void				ft_check_max_int(char *av);
void				ft_check_min_int(char *av);
void				ft_check_overflow(char *av);
unsigned char		ft_check_params(int ac, char **av);
int					is_just_troll(char *str);
int					ft_is_valid_int(char *string);
void				validate_arguments(int len, char **args);

#endif
