/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:23:26 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/27 09:58:25 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

static int	isset(char str, const char *set)
{
	while (*set)
	{
		if (*set == str)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	unsigned int	start;
	size_t			end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (s1[start] && isset(s1[start], set))
		start++;
	while (end > start && isset(s1[end], set))
		end--;
	return (ft_substr(s1, start, (end - start) + 1));
}
