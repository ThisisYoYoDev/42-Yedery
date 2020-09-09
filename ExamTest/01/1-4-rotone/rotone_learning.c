/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone_learning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:28:31 by yedery            #+#    #+#             */
/*   Updated: 2020/08/14 10:40:24 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rotone(char *str)
{
	int i;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'Y') || (*str >= 'a' && *str <= 'y'))
			ft_putchar(*str + 1);
		else if ((*str == 'Z') || (*str == 'z'))
			ft_putchar(*str - 25);
		else 
			ft_putchar(*str);
		++str;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	ft_putchar('\n');
	return 0;
}

// #include <stdio.h>

// int main(void)
// {
// 	int i;

// 	char *str = "Salut";

// 	printf("%d", i);
// }