/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:53:42 by yedery            #+#    #+#             */
/*   Updated: 2020/08/23 00:42:43 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		digits(char *str, int y)
{
	while (str[y] != '\0')
	{
		if (str[y] >= '1' && str[y] <= '9')
			return (1);
		y++;
	}
	return (0);
}

int		print_unit(char *str, char **tab, int len, int y)
{
	if (len == 1 && y == 0)
	{
		ft_putstr(tab[str[y] - 48]);
		return (1);
	}

	if (len > 3 && str[y - 1] != '1')
	{
		printf("str[y + 1] %c\n", str[y]);
		// printf("\ny = %d\n str[y - 1] = %d\n", str[y - 1], len);
		ft_putstr(tab[str[y] - 48]);
		ft_putchar(' ');
		// printf("len = %d\n", len);
		ft_putstr(tab[28 + (len / 3)]);
		// printf("\ny [y + 1] = %d\n", y);
		if (digits(str, y + 1)) // atoi simplifier && y = 1
			return (0);
		return (1);
	}
	else if (str[y - 1] != '1') // y = y + 1 a chaque fois que le nb est augementer de 1
	{
		// printf("\n else if[y + 1] = %d\n", y);
		ft_putstr(tab[str[y] - 48]);
	}
	if (digits(str, y + 1) && str[y - 1] != '1')
		return (0);
	return (1);
}

int		print_decade(char *str, char **tab, int len, int y)
{
	// printf("\nstr[y + 1] = %c\n", str[y + 1]);
	if (str[y + 1] != '0' && str[y] == '1')
	{

		ft_putstr(tab[(str[y + 1] - 48 + 9)]);
		if (len > 3)
		{
			ft_putchar(' ');
			ft_putstr(tab[28 + (len / 3)]);
			// printf("\ntab30= %s\n, ", tab[30]);
			// printf("\btab28 = %s\n len = %d\n", tab[28], len);
			// printf("\nstr[y + 1] = %c\n tab[28 + (len / 3)] = %s\n", str[y + 1], tab[28 + (len / 3)]);
			if (digits(str, y + 2))
				ft_putchar(' ');
		}
		return (1);
	}
	else // str[y] = uniter de ma dizaine
	{
		// printf("str[y] = %c\n", str[y]);
		ft_putstr(tab[(str[y] - 48) + 18]);
	}
	if ((str[y + 1] == '0') && (len > 3))
	{
		ft_putchar(' ');
		ft_putstr(tab[28 + (len / 3)]);
	}
	if (digits(str, y + 1))
		return (0);
	return (1);
}

int		print_hundred(char *str, char **tab, int len, int y)
{
	ft_putstr(tab[str[y] - 48]);
	ft_putchar(' ');
	// printf("tab[28] = %s\n", tab[28]);
	ft_putstr(tab[28]);
	if ((len > 3) && (str[y + 1] == '0' && str[y + 2] == '0'))
	{
		ft_putchar(' ');
		printf("len = %d\n", len);
		ft_putstr(tab[27 + (len / 3)]); // tab[27] = 90
		return (0);
	}
	if (digits(str, y + 1))
		return (0);
	return (1);
}

void	printer(char *str, char **tab)
{
	int res;
	int len;
	int y;

	len = ft_strlen(str);
	y = 0;
	if (check_zero(str))
		ft_putstr(tab[str[y] - 48]);
	while (len > 0)
	{
		if (str[y] - 48 != 0)
		{
			if (len % 3 == 0)
				res = print_hundred(str, tab, len, y);
			else if (len % 3 == 2)
				res = print_decade(str, tab, len, y);
			else
				res = print_unit(str, tab, len, y);
			if (res != 1 && len > 1 && digits(str, y + 1))
				write(1, " ", 1);
		}
		y++;
		len--;
	}
	write(1, "\n", 1);
}
