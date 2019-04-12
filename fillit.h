/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 10:13:39 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 08:32:12 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include "get_next_line.h"

typedef struct	s_list
{
	int			num;
	int			*tmp;
	int			*t;
	int			l;
	int			x;
	int			y;
	int			i;
}				t_list;

int				check_line(char *line, int *j, int *s, int *count_hash);
int				check_ini(int *count_hash);
int				open_read(int fd, int *s);

void			change_tvalue(int *t);
int				check_hash(int *t, int i);
int				t_value_check(t_list *list, int i, int j);
int				check_change_t(int *s, t_list *list);

int				put_error(void);
void			put_value(t_list *list);

int				num_max_x(int *t);
int				num_max_y(int *t);
void			change_xy(t_list *list, int xrange);
void			out_range_fix(t_list *list);
int				move_xy(t_list *list);

int				check_space(int *s, int *tmp, int i);
int				check_fit(t_list *list, int *t, int *i);

void			alpha(int num_types, int l, int *tmp);

#endif
