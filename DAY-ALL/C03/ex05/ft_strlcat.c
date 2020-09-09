/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 20:25:16 by yedery            #+#    #+#             */
/*   Updated: 2020/08/08 20:25:18 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int y;
	unsigned int z;

	y = -1;
	while (++y < size && *dest)
	{
		dest++;
	}
	if (y == size)
		return (y + ft_strlen(src));
	z = -1;
	while (src[++z])
	{
		if (z < size - y - 1)
			*dest++ = src[z];
	}
	*dest = '\0';
	return (y + z);
}

int main()
{
	char des[10] = "";
	char a[4] = "coco";

	printf("%d\n", ft_strlcat(des,a,10));
	printf("%s\n",des);	
}
