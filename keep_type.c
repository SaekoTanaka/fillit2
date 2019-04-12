/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:24:26 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 08:26:31 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void	change_tvalue(int *t)
{
	int	c;

	if ((t[0] % 4 > t[1] % 4) || (t[0] % 4 > t[2] % 4))
	{
		if (t[0] % 4 == t[1] % 4 + 2)
		{
			c = 4;
			while (--c >= 0)
				t[c] = t[c] - t[0] + 2;
		}
		else
		{
			c = 4;
			while (--c >= 0)
				t[c] = t[c] - t[0] + 1;
		}
	}
	else
	{
		c = 4;
		while (--c >= 0)
			t[c] = t[c] - t[0];
	}
}

int		check_hash(int *t, int i)
{
	int	d;
	int	c;

	d = i - 3;
	while (d <= i - 1)
	{
		c = i - 4;
		while (c < i - 1)
		{
			if (t[d] - 1 == t[c] || t[d] - 4 == t[c])
				break ;
			c++;
		}
		if (c == i - 1 && t[d] + 1 != t[d + 1])
			return (0);
		d++;
	}
	return (1);
}

int		t_value_check(t_list *list, int i, int j)
{
	list->t[i] = j;
	if (i > 0 && i % 4 != 0 && list->t[i] - list->t[i - 1] > 4)
		return (0);
	return (1);
}

int		check_change_t(int *s, t_list *list)
{
	int	j;
	int	m;
	int	i;

	i = 0;
	m = 0;
	while (m < list->num)
	{
		j = 0;
		while (j < 16)
		{
			if (s[m * 16 + j] == '#')
			{
				if (t_value_check(list, i, j) == 0)
					return (0);
				i++;
			}
			j++;
		}
		change_tvalue(&list->t[i - 4]);
		if (check_hash(list->t, i) == 0)
			return (0);
		m++;
	}
	return (1);
}
