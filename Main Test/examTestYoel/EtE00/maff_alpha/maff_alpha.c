/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_alpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 14:25:28 by yedery            #+#    #+#             */
/*   Updated: 2020/08/07 14:31:11 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(void)
{
	int a;
	int b;

	a = 'a';
	b = 'B';
	while(a <= 'y')
	{
		while (b <= 'Z')
		{
			ft_putchar(a);
			a += 2;
			ft_putchar(b);
			b += 2;
		}
		a++;
		b++;
	}
}
