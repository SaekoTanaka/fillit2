/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:24:39 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 08:26:57 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int		put_error(void)
{
	write(1, "error", 5);
	return (0);
}

void	put_value(t_list *list)
{
	int		l;

	l = 0;
	while (l * l < 4 * list->num)
		l++;
	list->l = l;
	list->x = 0;
	list->y = 0;
	list->i = 0;
}

int		main(int ac, char **av)
{
	t_list	list;
	int		fd;
	int		s[26 * 16];

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
		return (put_error());
	if ((list.num = open_read(fd, s)) == -1)
		return (put_error());
	if ((list.t = malloc(sizeof(int) * 4 * list.num)) == NULL)
		return (put_error());
	if ((list.tmp = malloc(sizeof(int) * 4 * list.num)) == NULL)
		return (put_error());
	if (check_change_t(&s[0], &list) == 0)
		return (put_error());
	put_value(&list);
	move_xy(&list);
	alpha(list.num, list.l, list.tmp);
	return (0);
}
