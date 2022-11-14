/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:14:50 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/28 16:22:18 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			i;
	size_t			i2;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && len > i)
	{
		i2 = 0;
		while (haystack[i + i2] == needle[i2] && (i + i2) < len)
		{
			if (needle[i2 + 1] == '\0')
				return ((char *)&haystack[i]);
			i2++;
		}
		i++;
	}
	return (NULL);
}
