/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:26:28 by yedery            #+#    #+#             */
/*   Updated: 2020/08/09 09:26:35 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

int		check_base_ten(char *base_ten)
{
	int y;
	int z;

	y = 0;
	z = 0;
	if (base_ten[0] == '\0' || base_ten[1] == '\0')
		return (0);
	while (base_ten[y])
	{
		z = y + 1;
		if (base_ten[y] == '+' || base_ten[y] == '-')
			return (0);
		if (base_ten[y] < 32 && base_ten[y] > 126)
			return (0);
		while (base_ten[z])
		{
			if (base_ten[y] == base_ten[z])
				return (0);
			z++;
		}
		y++;
	}
	return (1);
}

void	conv_base(long int n, char *base)
{
	long int len;

	len = ft_strlen(base);
	if (n >= len)
		conv_base(n / len, base);
	ft_putchar(base[n % len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int n;

	n = nbr;
	if (check_base_ten(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		conv_base(n, base);
	}
}
