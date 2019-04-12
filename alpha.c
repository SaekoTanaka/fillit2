/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:23:42 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/09 16:37:13 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	alpha(int num_types, int l, int *tmp)
{
	int		i;
	int		place;
	char	c;

	place = 0;
	while (place < l * l)
	{
		i = 0;
		while (i < 4 * num_types && place != tmp[i])
			i++;
		if (i == 4 * num_types)
			write(1, ".", 1);
		else
		{
			c = 65 + i / 4;
			write(1, &c, 1);
		}
		place++;
		if (place % l == 0)
			write(1, "\n", 1);
	}
}
