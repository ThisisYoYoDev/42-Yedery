/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:35:07 by yedery            #+#    #+#             */
/*   Updated: 2020/08/07 08:50:04 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int y;
	int uppercase_s;

	y = 0;
	uppercase_s = 1;
	while (str[y])
	{
		if ((str[y] >= 'a' && str[y] <= 'z')
				|| (str[y] >= 'A' && str[y] <= 'Z')
				|| (str[y] >= '0' && str[y] <= '9'))
		{
			if (uppercase_s && (str[y] >= 'a' && str[y] <= 'z'))
				str[y] -= 32;
			else if (!uppercase_s && (str[y] >= 'A' && str[y] <= 'Z'))
				str[y] += 32;
			uppercase_s = 0;
		}
		else
			uppercase_s = 1;
		y++;
	}
	return (str);
}
