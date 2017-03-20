/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:14:19 by ysan-seb          #+#    #+#             */
/*   Updated: 2016/12/22 15:49:06 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_cub(char ***cub)
{
	int		i;

	i = 0;
	while (cub[i])
	{
		free_map(cub[i]);
		cub[i] = NULL;
		i++;
	}
	free(cub);
	cub = NULL;
}

int			main(int ac, char **av)
{
	char	***cub;
	char	**map;
	int		nb_tetri;

	if (ac == 2)
	{
		if ((nb_tetri = start_prog(av[1])) == 0)
			return (0);
	}
	else
	{
		ft_putstr("usage : fillit [input_file]\n");
		return (0);
	}
	if (read_file(av[1]) != NULL)
	{
		cub = tetri_move(tetri_split(entry_split(read_file(av[1])),
				nb_tetri), nb_tetri);
		map = solver(cub, nb_tetri);
		print_map(map);
		free_map(map);
		free_cub(cub);
	}
	return (0);
}
