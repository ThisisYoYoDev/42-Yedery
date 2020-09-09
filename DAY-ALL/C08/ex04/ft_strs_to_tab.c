/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:21:36 by yedery            #+#    #+#             */
/*   Updated: 2020/08/12 13:21:39 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

char					*ft_strdup(char *src)
{
	char	*str;
	int		y;

	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	y = 0;
	while (src[y])
	{
		str[y] = src[y];
		y++;
	}
	str[y] = '\0';
	return (str);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int			i;

	if (!(tab = malloc(sizeof(t_stock_str) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		if (!(tab[i].str = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].str = av[i];
		if (!(tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}
