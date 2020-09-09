/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 09:51:37 by yedery            #+#    #+#             */
/*   Updated: 2020/08/17 09:51:39 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_display_file(char *str)
{
	int		display;
	int		rtn;
	char	buffer;

	display = open(str, O_RDONLY);
	if (display == -1)
	{
		ft_putstr("Cannot read file.\n");
		return ;
	}
	rtn = 0;
	while ((rtn = read(display, &buffer, 1)))
		write(1, &buffer, 1);
	if (close(display == -1))
		return ;
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_putstr("File name missing.\n");
	else if (ac > 2)
		ft_putstr("Too many arguments.\n");
	else
		ft_display_file(av[1]);
	return (0);
}
