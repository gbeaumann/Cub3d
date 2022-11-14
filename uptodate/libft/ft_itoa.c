/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:06:27 by gbeauman          #+#    #+#             */
/*   Updated: 2021/10/28 11:12:11 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

static int	count(unsigned int n)
{
	if (n > 9)
		return (count(n / 10) + 1);
	return (1);
}

static void	putnbr(char *str, unsigned int n)
{
	*str = n % 10 + 48;
	if (n > 9)
		putnbr(--str, n / 10);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		i = count(nb);
		i++;
	}
	else
	{
		nb = n;
		i = count(nb);
	}
	str = malloc(i * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[i] = '\0';
	putnbr(&str[i - 1], nb);
	if (n < 0)
		str[0] = '-';
	return (str);
}
