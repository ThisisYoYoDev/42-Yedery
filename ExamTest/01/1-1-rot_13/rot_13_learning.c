/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13_learning.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 19:30:20 by yedery            #+#    #+#             */
/*   Updated: 2020/08/12 19:44:55 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		rot_13(char c)
{
	if ((c >= 'A' && c <= 'M') || (c >= 'a' && c <= 'm'))
		c += 13;
	else if ((c >= 'N' && c <= 'Z') || (c >= 'n' && c<= 'z'))
		c -= 13;
	return (c);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		while (*argv[1])
			ft_putchar(rot_13(*argv[1]++));
	ft_putchar('\n');
	return (0);
}
