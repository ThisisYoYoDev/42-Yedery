/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:54:34 by yedery            #+#    #+#             */
/*   Updated: 2020/08/10 21:54:35 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

char	*ft_catnjoin(int size, char **charsep, char *sep, char *tab)
{
	int x;
	int y;
	int z;

	y = -1;
	z = 0;
	while (++y < size)
	{
		x = -1;
		while (charsep[y][++x])
		{
			tab[z++] = charsep[y][x];
		}
		if (y < size - 1)
		{
			x = -1;
			while (sep[++x])
			{
				tab[z++] = sep[x];
			}
		}
	}
	tab[z] = '\0';
	return (tab);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		memo;
	int		y;

	memo = 0;
	y = 0;
	while (y < size)
	{
		memo += ft_strlen(strs[y]) + ft_strlen(sep) + 1;
		y++;
	}
	if (!(tab = malloc(sizeof(char) * memo)))
		return (NULL);
	if (size == 0)
		return (tab);
	tab = ft_catnjoin(size, strs, sep, tab);
	return (tab);
}

int main()
{
	char* strs[] = {"Salut", "ca va","toto"};
	int size = 4;
	char *sep = " : ";
	printf("%s",ft_strjoin(size, strs, sep));
}
