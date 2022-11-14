/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:28:59 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/21 11:49:46 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		i2;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i2 = 0;
	while (s1[i2])
	{
		str[i2] = s1[i2];
		i2++;
	}
	str[i] = '\0';
	return (str);
}
