/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:56 by yedery            #+#    #+#             */
/*   Updated: 2020/08/18 11:22:57 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int 	y;
	int 	z;
	char	*swap;

	y = 0;
	z = 0;
	while (tab[y])
	{
		z = 1;
		while (tab[z])
		{
			if (ft_strcmp(tab[z - 1], tab[y]) > 0)
			{
				swap = tab[z - 1];
				tab[z - 1] = tab[y];
				tab[y] = swap;
			}
			z++;
		}
		y++;
	}
}
