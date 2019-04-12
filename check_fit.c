/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:24:04 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 07:38:08 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_space(int *s, int *tmp, int i)
{
	int n;
	int j;

	n = 0;
	if (i != 0)
	{
		while (n < 4)
		{
			j = 0;
			while (j < 4 * i)
			{
				if (s[n] == tmp[j])
					return (0); /* it means some other tetoris uses the space */
				j++;
			}
			n++;
		}
	}
	return (1);
}

int	check_fit(t_list *list, int *t, int *i)
{
	int n; /*this n dosen't mean anything, just count the number*/
	int j; /* j neither */
	int s[4]; /* we put the the number of the space into s[4] */

	n = 0;
	while (n < 4)
	{
		s[n] = list->x + t[n] % 4 + list->y * list->l + t[n] / 4 * list->l;
		n++;
	}
	if (check_space(&s[0], list->tmp, list->i) == 0)
		return (0); /*those lines after this means we get the number(s[]) into tmp.*/ 
	n = 0;
	j = *i * 4;
	while (n < 4)
		list->tmp[j++] = s[n++];
	list->x = 0;
	list->y = 0;
	*i = *i + 1;
	return (1);
}
