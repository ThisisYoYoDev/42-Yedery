/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_learning.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 09:21:01 by yedery            #+#    #+#             */
/*   Updated: 2020/08/13 09:28:13 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int y;
	int z;
	int nb;

	y = 0;
	z = 0;
	nb = 0;
	while (str[y] == ' ' || (str[y] >= 9) && (str[y] <= 13))
		y++;
	if (str[y] == '-')
		z = 1;
	if (str[y] == '+' || str[y] == '-')
		y++;
	while (str[y] && (str[y] >= '0') && (str[y] <= '9'))
	{
		nb = nb * 10 + (int)str[y] - 48;
		y++;
	}
	if (z == 1)
		return (-nb);
	else
		return (nb);
}

int		main(void)//
{//
	char a[] = "-5234";// -5234
	printf("%d\n",ft_atoi(a));//
}//
