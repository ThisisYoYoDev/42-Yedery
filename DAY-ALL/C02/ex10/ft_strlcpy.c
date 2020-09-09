/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 14:05:04 by yedery            #+#    #+#             */
/*   Updated: 2020/08/06 14:05:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int				ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int y;

	y = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[y] != '\0' && y < size - 1)
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	y = 0;
	while (src[y] != '\0')
		y++;
	return (y);
}

int main()
{
  char dest[20];
  char src[] = "testtest\0";
  int size = sizeof(dest);
  ft_strlcpy(dest,src,size);
  printf("%d\n",ft_strlcpy(dest,src,size));
  printf("%s\n",dest);
}

