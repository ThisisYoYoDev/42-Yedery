/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:24 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 17:50:39 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int y;
	int ascending;
	int descending;

	y = 0;
	ascending = 1;
	descending = 1;
	if (length == 0 || length == 1)
		return (1);
	while (y < length - 1)
	{
		if ((*f)(tab[y], tab[y + 1]) < 0)
			ascending++;
		else if ((*f)(tab[y], tab[y + 1] > 0))
			descending++;
		ascending++;
		descending++;
		y++;
	}
	if (ascending == length || descending == length)
		return (1);
	return (0);
}

#include <stdio.h>

int		ft_comp(int i, int j)
{
	return (i-j);
}

int		main(void)
{
	int		sorted_tab[4] = {14, 27, 42, 53};
	int		nonsorted_tab[4] = {30, 30, 10, 5};
	int		sorted = ft_is_sort(sorted_tab, 4, &ft_comp);
	int		nonsorted = ft_is_sort(nonsorted_tab, 4, &ft_comp);
	printf("%i, %i", sorted, nonsorted);
	return 0;
}
