/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movexy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:25:14 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 08:18:13 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		num_max_x(int *t) /*check the size of the width of this tetoris */
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		if (n < t[i] % 4)
			n = t[i] % 4;
		i++;
	}
	return (n);
}

int		num_max_y(int *t) /*check the height as well as x*/
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (i < 4)
	{
		if (n < t[i] / 4)
			n = t[i] / 4;
		i++;
	}
	return (n);
}

void	change_xy(t_list *list, int xrange)
{
	if (list->x == xrange)
	{
		list->x = 0;
		list->y = list->y + 1;
	}
	else
		list->x = list->x + 1;
}

void	out_range_fix(t_list *list)
{
	int xrange;
	int yrange;

	if (list->i != 0)
	{
		list->i = list->i - 1;
		list->x = list->tmp[list->i * 4] % list->l - list->t[list->i * 4] % 4;
		list->y = list->tmp[list->i * 4] / list->l;
		xrange = list->l - 1 - num_max_x(&list->t[4 * list->i]);
		yrange = list->l - 1 - num_max_y(&list->t[4 * list->i]);
		change_xy(list, xrange);
	}
	else
	{
		list->l = list->l + 1;
		list->x = 0;
		list->y = 0;
		list->i = 0;
	}
}

int		move_xy(t_list *list)
{
	int xr; /*xrange*/
	int yr;

	while (list->i < list->num)
	{
		xr = list->l - 1 - num_max_x(&list->t[4 * list->i]);
		yr = list->l - 1 - num_max_y(&list->t[4 * list->i]);
		if (xr < 0 || yr < 0) /*xr < 0 or yr < 0 mean there is enough space to move this tetoris */
			list->l = list->l + 1;
		while (list->y <= yr && list->x <= xr && xr >= 0 && yr >= 0)
		{
			if (check_fit(list, &list->t[4 * list->i], &list->i))
				break ;
			change_xy(list, xr);
		}
		if (list->y > yr && yr >= 0 && xr >= 0)
		{
			out_range_fix(list);
			if (move_xy(list) == list->num)
				list->i = list->num;
		}
	}
	return (list->i);
}
