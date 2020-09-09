/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:53:56 by yedery            #+#    #+#             */
/*   Updated: 2020/08/10 21:53:59 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int		*tab;
	int		y;

	y = 0;
	if (min >= max)
		return (NULL);
	if (!(tab = malloc(sizeof(int) * (max - min))))
		return (NULL);
	while (min < max)
	{
		tab[y] = min;
		y++;
		min++;
	}
	return (tab);
}

int   main(void)
{
int	*res;
int i;

res = ft_range(5, 10);

for (i = 0; i < 5; i++)
  printf("%d,", res[i]);
printf("\n");

res = ft_range(-20, -15);
for (i = 0; i < 5; i++)
  printf("%d,", res[i]);
printf("\n");

res = ft_range(-2147483648, -2147483646);
for (i = 0; i < 1; i++)
	printf("%d,", res[i]);
printf("\n");

res = ft_range(10, 5);
printf("%x\n", (unsigned int)res);
}












#include <stdlib.h>

int			*ft_range(int start, int end)
{
	int			*range;
	int			i;

	if (start > end)
		range = (int*)malloc(sizeof(int) * (start - end));
	else
		range = (int*)malloc(sizeof(int) * (end - start + 1));
	i = 0;
	while (start != end)
	{
		range[i++] = start;
		start += (start > end) ? -1 : 1;
	}
	range[i] = start;
	return (range);
}


