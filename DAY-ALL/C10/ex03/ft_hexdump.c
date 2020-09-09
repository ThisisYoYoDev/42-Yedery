/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 21:07:54 by yedery            #+#    #+#             */
/*   Updated: 2020/08/19 21:08:01 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int y;

	y = -1;
	while (str[++y] != '\0')
	{
		ft_putchar(str[y]);
	}
}

int		file_size(char *file)
{
	int		file_cpy;
	int		size;
	char	buffer;

	size = 0;
	buffer = 0;
	file_cpy = open(file, O_RDONLY);
	if (file_cpy < 0)
	{
		ft_putstr("hexdump : ");
		while (*file)
		{
			ft_putstr(file++);
		}
		ft_putstr(": No such file or directory\n");
	}
	else
		while (read(file_cpy, &buffer, 1) > 0)
			++size;
		close(file_cpy);
		return (size);
}

void	print_offset(int num, int y)
{
	char *base; // static or const base

	base = "0123456789abcdef";
	if (num / 16 > 0)
	{
		print_offset(num, y);
	}
	else if (y < 8)
	{
		while (++y <= 8)
		{
			ft_putstr("0");
		}
	}
	ft_putstr(base + num % 16);
}

int		copy_input(char *file, int size)
{
	int 	file_cpy;
	int 	y;
	char	buffer;
	char	*str;

	buffer = 0;
	y = 0;
	str = malloc(size + 1);
	file_cpy = open(file, O_RDONLY);
	while (read(file_cpy, &buffer, 1) > 0)
	{
		str[y++] = buffer;
	}
	str[y] = '\0';
	close(file_cpy);
	return (str);
}

void	print_hex(char c, int y, int size)
{
	char base[16] = "0123456789abcdef"; // const or static

	if (y < size)
	{
		ft_putstr(base + c / 16);
		ft_putstr(base + c % 16);
		ft_putstr(" ");
	}
	else
	{
		ft_putstr("   ");
	}
	if ((y + 1) % 8 == 0)
		ft_putstr(" ");
}

void	print_ascii(char c)
{
	if (c >= 32 && c<= 126)
		ft_putstr(&c);
	else
		ft_putstr(".");
}

void	ft_hexdump(char *str, int size)
{
	int y;
	int z;

	z = 0;
	while (str[z])
	{
		print_offset(z, 1);
		ft_putstr("  ");
		y = z - 1;
		while (++y < 16 + z)
		{
			print_hex(*(str + y), y, size);
		}
		y = z - 1;
		ft_putstr("|");
		while (++y < 16 + z && str[y])
		{
			print_ascii(*(str +y));
		}
		ft_putstr("|\n");
		z = z + 16;
	}
	print_offset(z, 1);
	ft_putstr("\n");
	free(str);
}

int		main(int ac, char **av)
{
	int 	y;
	int 	size;
	char	*str;

	while (++y < ac)
	{
		if (!(*av[y] == '-'  && *(av[y] + 1) == 'C'))
		{
			size = file_size(av[y]);
			str = copy_input(av[y], size);
			ft_hexdump(str, size);
		}
	}
	return (0);
}















