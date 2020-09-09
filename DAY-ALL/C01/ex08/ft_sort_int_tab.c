/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:47:49 by yedery            #+#    #+#             */
/*   Updated: 2020/08/05 16:47:54 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int y;
	int z;

	z = 0;
	while (z < size)
	{
		y = 0;
		while (y < size)
		{
			if (tab[y] >= tab[z])
			{
				ft_swap(&tab[y], &tab[z]);
			}
			y++;
		}
		z++;
	}
}
