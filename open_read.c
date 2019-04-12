/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:25:42 by stanaka           #+#    #+#             */
/*   Updated: 2019/04/12 08:29:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_line(char *line, int *j, int *s, int *count_hash)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i] && n < 16)
	{
		if (!(line[i] == '#' || line[i] == '.'))
			return (-1);
		if (line[i] == '#')
			*count_hash = *count_hash + 1;
		s[*j + n] = line[i];
		i++;
		n++;
	}
	*j = *j + n;
	return (i);
}

int	check_ini(int *count_hash)
{
	if (*count_hash != 4)
		return (-1);
	*count_hash = 0;
	return (0);
}

int	open_read(int fd, int *s)
{
	char	*line;
	int		j;
	int		count_hash;
	int		count_nl;
	int		i;

	count_hash = 0;
	count_nl = 0;
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		count_nl++;
		if (count_nl % 5 == 0 && line[0])
			return (-1);
		if ((i = check_line(line, &j, s, &count_hash)) == -1)
			return (-1);
		if (count_nl % 5 != 0 && i != 4)
			return (-1);
		if (j % 16 == 0 && check_ini(&count_hash) == -1 && count_nl % 5 != 0)
			return (-1);
	}
	if (count_nl % 5 != 4)
		return (-1);
	return (j / 16);
}
