/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 14:39:48 by yedery            #+#    #+#             */
/*   Updated: 2020/08/08 14:39:51 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int y;
	int z;

	y = 0;
	if (!*to_find)
		return (str);
	while (str[y] != '\0')
	{
		z = 0;
		while (str[y + z] == to_find[z])
		{
			z++;
			if (to_find[z] == '\0')
				return (&str[y]);
		}
		y++;
	}
	return (0);
}
