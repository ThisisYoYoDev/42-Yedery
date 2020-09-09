/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:21:46 by yedery            #+#    #+#             */
/*   Updated: 2020/08/18 11:21:47 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int y;
	int *buf_tab;

	if (!(buf_tab = malloc(sizeof(int) * (length + 1))))
		return (NULL);
	y = 0;
	while (y < length)
	{
		buf_tab[y] = (*f)(tab[y]);
		y++;
	}
	return (buf_tab);
}
