/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:00:03 by yedery            #+#    #+#             */
/*   Updated: 2020/08/23 13:00:08 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		my_isspace(char *str)
{
	return (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\f' || *str == '\r');
}

char	*splitter(char *tab)
{
	int y;
	int z;

	y = 0;
	z = 0;
	while (tab[y] != ':')
		y++;
	y++;
	while (my_isspace(&tab[y]) == 1)
		y++;
	while (tab[y] != '\0')
	{
		if (!(my_isspace(&tab[y]) && my_isspace(&tab[y + 1])))
		{
			tab[z] = tab[y];
			tab[y] = ' ';
			z++;
		}
		y++;
	}
	tab[z - 1] = '\0';
	return (tab);
}
