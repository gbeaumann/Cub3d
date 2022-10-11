/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:28:13 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/14 17:04:58 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	const char	*fins;
	char		*find;

	dest = dst;
	source = src;
	if (!(dst) && !(src))
		return (dst);
	if (dest < source)
	{
		while (len--)
			*dest++ = *source++;
	}
	else
	{
		fins = source + (len - 1);
		find = dest + (len - 1);
		while (len--)
			*find-- = *fins--;
	}
	return (dst);
}
