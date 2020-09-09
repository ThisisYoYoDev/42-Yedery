/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:24 by yedery            #+#    #+#             */
/*   Updated: 2020/08/20 17:24:27 by yedery           ###   ########.fr       */
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
		else if ((*f)(tab[y], tab[y + 1]) > 0)
			descending++;
		ascending++;
		descending++;
		y++;
	}
	if (ascending == length || descending == length)
		return (1);
	return (0);
}
