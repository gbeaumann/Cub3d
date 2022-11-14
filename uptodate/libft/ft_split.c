/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 09:56:01 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/27 10:28:32 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

static size_t	strcount(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static char	**juste_pour_une_ligne(char **str, size_t i)
{
	str[i] = 0;
	return (str);
}

char	**ft_split(const char *s, char c)
{
	size_t		indlen[2];
	char		**str;
	const char	*deb;

	if (!s)
		return (NULL);
	str = (char **) malloc(((strcount(s, c)) + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	indlen[0] = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		deb = s;
		indlen[1] = 0;
		while (*s && *s != c)
		{
			indlen[1]++;
			s++;
		}
		if (*(s - 1) != c)
			str[indlen[0]++] = ft_substr(deb, 0, indlen[1]);
	}
	return (juste_pour_une_ligne(str, indlen[0]));
}
