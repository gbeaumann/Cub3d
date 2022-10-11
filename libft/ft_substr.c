/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:13:30 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/22 16:58:27 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	i2;
	unsigned int	strlen;

	i = 0;
	i2 = 0;
	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (len + start > strlen)
		len = strlen - start;
	if (start > strlen)
		len = 0;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && i2 < len)
			str[i2++] = s[i];
		i++;
	}
	str[i2] = '\0';
	return (str);
}
