/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param_learning.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:31:22 by yedery            #+#    #+#             */
/*   Updated: 2020/08/12 16:35:26 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc > 1)
		while (*argv[1])
			write(1, argv[1]++, 1);
	write(1, "\n", 1);
	return (0);
}
