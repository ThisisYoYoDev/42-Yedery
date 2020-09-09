/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 16:19:58 by yedery            #+#    #+#             */
/*   Updated: 2020/08/06 16:19:59 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	convhex(int hexnum)
{
	char *hexa;

	hexa = "0123456789abcdef";
	write(1, &hexa[hexnum / 16], 1);
	write(1, &hexa[hexnum % 16], 1);
}

void	ft_putstr_non_printable(char *str) // A corriger char ascii > 127 ex test with \xff 
{
	int y;

	y = 0;
	while (str[y])
	{
		if (str[y] >= 0 && str[y] <= 31)
		{
			write(1, "\\", 1);
			convhex(str[y]);
		}
		else if (*str < 0)
		{
			ft_putchar(0);
			ft_putchar(0);
		}
		else
		{
			write(1, &str[y], 1);
		}
		y++;
	}
}
