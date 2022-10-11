/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:22:09 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/18 14:42:12 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*s != '\0')
		s++;
	while (s != str - 1)
	{
		if ((char)c == *s)
			return ((char *)s);
		s--;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
