/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lol.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 14:19:49 by yedery            #+#    #+#             */
/*   Updated: 2020/08/14 14:27:04 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		write(1, str[i++], 1);
	return (i);
}

void rev_str(char *str)
{
	int i = ft_strlen(str);

	while (i >= 0)
	{	
		ft_putchar(str[i]);
		i--;
	}
}

int	main(void)
{
	rev_str("SALUT");
}
