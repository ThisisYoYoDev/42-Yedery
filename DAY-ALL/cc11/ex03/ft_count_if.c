/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:12 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 17:48:40 by yedery           ###   ########.fr       */
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

#include <stdio.h>

int starts_with_z(char* str) 

{ 

    return str[0] == 'Z'; 

} 

int main(void) 

{ 

    char *tab[4] = {"Mahaut", "Latinis", "ZLauranne", "Zoulou"}; 

    printf("%d\n", ft_count_if(tab, 4, starts_with_z)); 

    return (0); 

} 
