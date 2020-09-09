/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:23:42 by yedery            #+#    #+#             */
/*   Updated: 2020/08/18 11:23:43 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	char	*swap;
	int		y;
	int		z;

	y = 0;
	while (tab[y])
	{
		z = 0;
		while (tab[z])
		{
			if (cmp(tab[y], tab[z]) < 0)
			{
				swap = tab[y];
				tab[y] = tab[z];
				tab[z] = swap;
			}
			z++;
		}
		y++;
	}
}
