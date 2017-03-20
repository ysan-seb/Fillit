/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealrick <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 14:31:33 by ealrick           #+#    #+#             */
/*   Updated: 2016/12/22 16:37:35 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_1(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i > 545 || (i + 1) % 21 != 0)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] != '.' && s[i] != '#' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int		check_2(char *s)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] != '\n')
		{
			j++;
			i++;
		}
		if (j != 4 && j != 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_3(char *s)
{
	int k;

	k = 20;
	while (s[k])
	{
		if ((s[k] != '\n' && s[k] != '\0') || s[k - 1] != '\n')
			return (0);
		k += 21;
	}
	return (1);
}

int		check_4(char *s)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] == '#' && (s[i + 1] == '#' && (i + 1) <= 19))
			j++;
		if (s[i] == '#' && (s[i - 1] == '#') && (i - 1) >= 0)
			j++;
		if (s[i] == '#' && (s[i + 5] == '#' && (i + 5) <= 19))
			j++;
		if (s[i] == '#' && (s[i - 5] == '#' && (i - 5) >= 0))
			j++;
		if (s[i] == '#')
			k++;
		i++;
	}
	if ((j != 6 && j != 8) || (k != 4))
		return (0);
	return (1);
}

int		check_global(char *s)
{
	int		i;
	char	**tab;

	tab = entry_split(s);
	if (check_1(s) == 0 || check_2(s) == 0 || check_3(s) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	i = 0;
	while (tab[i])
	{
		if (check_4(tab[i]) == 0)
		{
			write(1, "error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}
