/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BALLs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:11:44 by yedery            #+#    #+#             */
/*   Updated: 2020/08/14 14:17:28 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		write(1, str[i++], 1);
	return (i);
}

int	main(int argc, char **argv)
{
	int len;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		while(len--)
			write(1, &argv[1][len], 1);
	}
	write(1, "\n", 1);
	return (0);
}
