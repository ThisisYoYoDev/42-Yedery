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
	int		y;
	char	*tmp;

	y = 0;
	while (tab[y + 1])
	{
		if (cmp(tab[y], tab[y + 1]) > 0)
		{
			tmp = tab[y + 1];
			tab[y + 1] = tab[y];
			tab[y] = tmp;
			y = 0;
		}
		else
			++y;
	}
}
