/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:21:32 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 17:39:53 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int y;

	y = 0;
	while (y < length)
	{
		(*f)(tab[y]);
		y++;
	}
}

#include <stdio.h>

void ft_putnbr(int n)
{
	printf("%d,", n);
}

int main()
{
 	int test1[] = {1,2,3,4,5};
 	int test2[] = {-25,0,20,45};
 	int test3[] = {5};

	ft_foreach(test1, 5, ft_putnbr);
	printf("\n");
 	ft_foreach(test2, 4, ft_putnbr);
 	printf("\n");
 	ft_foreach(test3, 1, ft_putnbr);
 	printf("\n");
}
