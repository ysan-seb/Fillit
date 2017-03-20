/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 18:05:12 by ysan-seb          #+#    #+#             */
/*   Updated: 2016/12/19 18:05:18 by ysan-seb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char const *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			tetri_heigth(char **t)
{
	int		i;
	int		j;
	int		heigth;
	int		pos_line;

	i = -1;
	heigth = 0;
	pos_line = -1;
	while (t[++i])
	{
		j = -1;
		while (t[i][++j])
		{
			if (t[i][j] == '#' && i != pos_line)
			{
				heigth++;
				pos_line = i;
			}
		}
	}
	return (heigth);
}

int			tetri_width(char **t)
{
	if (t == NULL)
		return (0);
	if (t[0][0] == t[1][0] && t[1][0] == t[2][0] && t[2][0] == t[3][0])
		return (1);
	if ((t[0][0] == t[1][0] && t[1][0] == t[2][0] && t[2][0] != t[3][0]) ||
		(t[0][1] == t[1][1] && t[1][1] == t[2][1] && t[2][1] != t[3][1]) ||
		(t[0][0] == t[0][1] && t[0][1] == t[1][1] && t[1][1] == t[1][0]) ||
		(t[0][0] == t[2][1] && t[2][1] != t[3][3]) ||
		(t[0][1] == t[2][0] && t[2][0] != t[3][3]))
		return (2);
	if ((t[0][0] == t[0][1] && t[0][1] == t[0][2] && t[0][2] != t[0][3]) ||
		(t[1][0] == t[1][1] && t[1][1] == t[1][2] && t[1][2] != t[1][3]) ||
		(t[0][0] == t[1][2]) || (t[0][2] == t[1][0]))
		return (3);
	if (t[0][0] == t[0][1] && t[0][1] == t[0][2] && t[0][2] == t[0][3])
		return (4);
	return (0);
}
