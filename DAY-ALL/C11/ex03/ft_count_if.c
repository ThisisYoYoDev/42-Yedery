/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:12 by yedery            #+#    #+#             */
/*   Updated: 2020/08/18 11:22:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int buf_tab;
	int count;
	int y;

	y = 0;
	count = 0;
	while (y < length)
	{
		buf_tab = (*f)(tab[y]);
		if (buf_tab)
			count++;
		y++;
	}
	return (count);
}
