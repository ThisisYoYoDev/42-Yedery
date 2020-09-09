/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word_learning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:08:19 by yedery            #+#    #+#             */
/*   Updated: 2020/08/13 10:19:54 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_blank(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int main(int argc ,char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
			argv[1]++;
		argv[1]--;
		while (ft_blank(*argv[1]))
			argv[1]--;
		while (argv[1] && (!ft_blank(*argv[1])))
			argv[1]--;
		argv[1]++;
		while (*argv[1] && (!ft_blank(*argv[1])))
			argv[1]--;
		argv[1]++;
		while (*argv[1] && (!ft_blank(*argv[1])))
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
