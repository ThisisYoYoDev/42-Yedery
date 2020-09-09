/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:32:11 by yedery            #+#    #+#             */
/*   Updated: 2020/08/04 21:32:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	char y;
	char z;

	y = 0;
	z = 1;
	while (y < 99)
	{
		ft_putchar(y / 10 + '0');
		ft_putchar(y % 10 + '0');
		ft_putchar(' ');
		ft_putchar(z / 10 + '0');
		ft_putchar(z % 10 + '0');
		if (y == 98 && z == 99)
			return ;
		if (y < 99)
			write(1, ", ", 2);
		if (++z > 99)
			z = ++y + 1;
	}
}
