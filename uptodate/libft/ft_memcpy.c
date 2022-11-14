/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:28:13 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/15 11:34:02 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*source;
	int			i;

	dest = dst;
	source = src;
	i = 0;
	if (!(dst) && !(src))
		return (dst);
	while (n--)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
