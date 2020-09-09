/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeconin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 10:51:21 by ldeconin          #+#    #+#             */
/*   Updated: 2020/08/08 12:43:25 by nle-biha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	printr(int x, int y, int m, int n)
{
	m = m - 1;
	n = n - 1;
	if (x == 0 && y == 0)
		ft_putchar('A');
	else if (x == 0 && y == n)
		ft_putchar('A');
	else if (x == m && y == n && m != 0)
		ft_putchar('C');
	else if (x == m && y == 0 && m != 0)
		ft_putchar('C');
	else if ((x != 0) && (x != m) && (y == 0 || y == n))
		ft_putchar('B');
	else if ((x == 0 || x == m) && (y != 0 || y != n))
		ft_putchar('B');
	else if (x != 0 && x != m && y != 0 && y != n)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			printr(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
