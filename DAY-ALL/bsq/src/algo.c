/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 17:26:30 by yedery            #+#    #+#             */
/*   Updated: 2020/08/24 17:26:33 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	struct_square(char **map, int low_value, int height, int width, struct s_bsq *toto)
{
	int c;
	int l;
	int flag;
	int	id_c;
	int	id_l;

	id_l = 0;
	id_c = 0;
	flag = 0;
	while (low_value > 0 && flag != 1)
	{
		while (id_l <= height - low_value && flag != 1)
		{
			while (id_c <= width - low_value && flag != 1)
			{
				c = id_c;
				l = id_l;
				while (l < id_l + low_value && flag != 1)
				{
					while (c < id_c + low_value && flag != 1)
					{
						if (map[l][c] == 'x')
							flag = 1;
						c++;
					}
					c = 0;
					l++;
				}
				if (flag == 1)
				{
					id_c++;
					flag = 0;
				}
			}
			if (flag == 1)
			{
				id_c = 0;
				id_l++;
				flag = 0;
			}
		}
		if (flag == 1)
		{
			id_l = 0;
			id_c = 0;
			low_value--;
			flag = 0;
		}
	}
	toto->size = low_value;
	toto->ic = id_c;
	toto->il = id_l;
}
