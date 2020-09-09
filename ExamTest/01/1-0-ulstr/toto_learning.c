/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toto_learning.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 10:54:14 by yedery            #+#    #+#             */
/*   Updated: 2020/08/14 11:00:46 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int i;
	char letter;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			letter = argv[1][i];
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				letter += 32;
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				letter -= 32;
			write(1, &letter, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
