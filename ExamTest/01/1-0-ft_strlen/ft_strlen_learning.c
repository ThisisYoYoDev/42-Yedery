/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_learning.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:42:57 by yedery            #+#    #+#             */
/*   Updated: 2020/08/12 16:47:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

#include <stdio.h>

int main(void)
{
	char t[] = "TA MAMAN";
	printf ("result : %d\n", ft_strlen(t));
	return (0);
}
