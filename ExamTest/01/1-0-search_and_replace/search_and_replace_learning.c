/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace_learning.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 17:04:04 by yedery            #+#    #+#             */
/*   Updated: 2020/08/12 17:16:35 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int y;

	if (argc != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	y = 0;
	while (argv[1][y] != '\0')
	{
		if (argv[1][y] == argv[2][0])
			argv[1][y] = argv[3][0];
		write(1, &argv[1][y], 1);
		y++;
	}
	write(1, "\n", 1);
	return (0);	
}
