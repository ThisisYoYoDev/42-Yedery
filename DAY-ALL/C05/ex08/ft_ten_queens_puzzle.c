/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 18:39:15 by yedery            #+#    #+#             */
/*   Updated: 2020/08/26 18:39:18 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_tab(int *tab)
{
	int		y;
	char	tmp;

	y = -1;
	while (++y < 10)
	{
		tmp = tab[y] + 48;
		ft_putchar(tmp);
	}
	ft_putchar('\n');
}

int		backtrack_checking(int *tab, int column, int line)
{
	int y;

	y = -1;
	while (column - ++y >= 0)
	{
		if (tab[column - y] == line + y
			|| tab[column - y] == line - y
			|| tab[column - y] == line)
			return (1);
	}
	return (0);
}

int		operator(int *tab, int column, int line, int *result)
{
	if (column == 10)
	{
		print_tab(tab);
		*result += 1;
		return (1);
	}
	while (line <= 9)
	{
		if (backtrack_checking(tab, column, line) != 1)
		{
			tab[column] = line;
			operator(tab, column + 1, 0, result);
			tab[column] = 42;
		}
		line++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(int y)
{
	int result;
	int tab[100];

	result = 0;
	y = -1;
	while (++y < 10)
		tab[y] = 42;
	operator(tab, 0, 0, &result);
	return (result);
}
