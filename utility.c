/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:52:21 by ealrick           #+#    #+#             */
/*   Updated: 2016/12/20 18:07:09 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i < nb)
	{
		if (i * i >= nb)
			return (i);
		i++;
	}
	return (0);
}

char	**create_map(int map_size)
{
	int		i;
	char	**map;

	if ((map = (char **)malloc(sizeof(char *) * (map_size + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < map_size)
	{
		if ((map[i] = (char *)malloc(sizeof(char) * (map_size + 1))) == NULL)
			return (NULL);
		map[i][map_size] = '\0';
		i++;
	}
	map[i] = NULL;
	fill_map(map, map_size);
	return (map);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	fill_map(char **map, int map_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}
