/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeauman <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:17:27 by gbeauman          #+#    #+#             */
/*   Updated: 2021/11/03 11:10:38 by gbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include	"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i2;

	i2 = 0;
	while (lst)
	{
		lst = lst -> next;
		i2++;
	}
	return (i2);
}