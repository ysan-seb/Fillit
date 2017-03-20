/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:28:36 by ealrick           #+#    #+#             */
/*   Updated: 2016/12/22 16:11:56 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char				**entry_split(char *s)
{
	int				i;
	int				nb_tetri;
	char			**tab;
	unsigned int	start;
	size_t			len;

	i = 0;
	nb_tetri = (ft_strlen(s) + 1) / 21;
	if ((tab = (char **)malloc(sizeof(char *) * (nb_tetri + 1))) == NULL)
		return (NULL);
	start = 0;
	len = 20;
	while (i < nb_tetri)
	{
		tab[i] = ft_strsub((char const *)s, start, len);
		start += 21;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char				***tetri_split(char **tab, int nb_tetri)
{
	char			***cub;
	int				i;

	i = 0;
	if ((cub = (char ***)malloc(sizeof(char **) * (nb_tetri + 1))) == NULL)
		return (NULL);
	while (i < nb_tetri)
	{
		cub[i] = ft_strsplit((char const *)tab[i], '\n');
		i++;
	}
	cub[i] = NULL;
	return (cub);
}

t_struct			*check_pos(char **tab)
{
	int				i;
	int				j;
	t_struct		*pos;

	if ((pos = (t_struct *)malloc(sizeof(t_struct))) == NULL)
		return (NULL);
	i = 0;
	pos->x = 4;
	pos->y = 4;
	while (i < 4)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '#' && i < pos->x)
				pos->x = i;
			if (tab[i][j] == '#' && j < pos->y)
				pos->y = j;
			j++;
		}
		i++;
	}
	return (pos);
}

char				***tetri_move(char ***cub, int nb_tetri)
{
	int				i;
	int				j;
	int				k;
	t_struct		*tmp;

	if ((tmp = (t_struct *)malloc(sizeof(t_struct))) == NULL)
		return (NULL);
	i = -1;
	while (++i < nb_tetri)
	{
		tmp = check_pos(cub[i]);
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
				if (cub[i][j][k] == '#' && (tmp->x != 0 || tmp->y != 0))
				{
					cub[i][j - tmp->x][k - tmp->y] = '#';
					cub[i][j][k] = '.';
				}
		}
	}
	free(tmp);
	return (cub);
}
