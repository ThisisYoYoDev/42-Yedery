/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:27:40 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 11:27:43 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int y;

	y = -1;
	while (str[++y] != '\0')
	{
		ft_putchar(str[y]);
	}
}

int		ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

int		ft_atoi(char *str)
{
	int y;
	int nbrneg;

	y = 0;
	nbrneg = 1;
	while ((str[y] == ' ') || (str[y] == '\t')
		|| (str[y] == '\n') || (str[y] == '\v')
		|| (str[y] == '\r') || (str[y] == '\f'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			nbrneg = -nbrneg;
		str++;
	}
	while (str[0] >= '0' && str[0] <= '9')
	{
		y = y * 10 + *str - '0';
		str++;
	}
	return (y * nbrneg);
}

void	ft_putnbr(int nb)
{
	unsigned int n;

	n = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
}
