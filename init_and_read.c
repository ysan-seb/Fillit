/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:00:46 by ysan-seb          #+#    #+#             */
/*   Updated: 2016/12/19 10:39:31 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*read_file(char *av)
{
	int		i;
	int		fd;
	int		n;
	char	*buff;

	i = 0;
	buff = (char *)malloc(sizeof(char) * 546);
	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	else
	{
		while ((n = read(fd, buff, 545)) > 0)
			i++;
		if (i == 0)
			ft_putstr("error\n");
		buff[545] = '\0';
		close(fd);
		return (buff);
	}
	return (NULL);
}

int		start_prog(char *av)
{
	char	*filecontent;
	int		nb_tetri;

	filecontent = read_file(av);
	if (filecontent == NULL)
		return (0);
	nb_tetri = (ft_strlen(filecontent) + 1) / 21;
	if (ft_strlen(filecontent) > 0)
	{
		if (check_global(filecontent) != 0)
			return (nb_tetri);
	}
	return (0);
}
