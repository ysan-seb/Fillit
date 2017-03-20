/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysan-seb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 09:01:08 by ysan-seb          #+#    #+#             */
/*   Updated: 2016/12/22 15:54:22 by ealrick          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_ctw(char const *s, char c)
{
	int	nb_w;
	int	i;

	nb_w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			nb_w++;
		i++;
	}
	return (nb_w);
}

int		ft_ctl(char const *s, char c, int i)
{
	int nb_l;

	nb_l = 0;
	while (s[i] && s[i] != c)
	{
		nb_l++;
		i++;
	}
	return (nb_l);
}

char	**ft_strsplit(char const *s, char c)
{
	int		nb_l;
	int		i;
	int		k;
	int		j;
	char	**tmp;

	i = 0;
	j = 0;
	if (!s || (tmp = (char **)malloc(sizeof(char *) * (ft_ctw(s, c) + 1)))
			== NULL)
		return (NULL);
	while (i < ft_ctw(s, c))
	{
		k = 0;
		while (s[j] == c)
			j++;
		nb_l = ft_ctl(s, c, j);
		if ((tmp[i] = (char *)malloc(sizeof(char) * nb_l + 1)) == NULL)
			return (NULL);
		while (s[j] != c && s[j] != '\0')
			tmp[i][k++] = s[j++];
		tmp[i++][k] = '\0';
	}
	tmp[ft_ctw(s, c)] = NULL;
	return (tmp);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	if (!s)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
