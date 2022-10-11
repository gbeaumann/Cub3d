/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:00:32 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/18 11:37:07 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	while (n-- > 0)
	{
		str = (const char *)s++;
		if (*str == (char)c)
			return ((void *)str);
	}
	return (NULL);
}
