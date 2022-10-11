/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 10:57:19 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/02 12:00:13 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t			i;
	size_t			i2;
	size_t			lentotal;
	char			*str;

	i = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	lentotal = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((lentotal + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		str[i + i2] = s2[i2];
		i2++;
	}
	str[i + i2] = '\0';
	return (str);
}
