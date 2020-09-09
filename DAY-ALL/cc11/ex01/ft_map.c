/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:21:46 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 17:41:25 by yedery           ###   ########.fr       */
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

int	ft_absval(int nb)
{
	if (nb < 0)
		return -(nb);
	else
		return (nb);
}
#include <stdio.h>
int		main(void)
{
	int array[] = {1, -3, 4, -4, 5, 6, -1};

	int	*res = ft_map(array, 7, &ft_absval);
	int i = 0;

	while (i < 7)
	{
		printf("%d\n", res[i]);
		i++;
	}
	return (0);
}
