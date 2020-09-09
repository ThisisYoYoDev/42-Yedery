/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:52:31 by yedery            #+#    #+#             */
/*   Updated: 2020/08/17 14:52:32 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

# define SalutLaMoulinette void

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

void	cat_error(char *str, int tp, char *name)
{
	ft_putstr(basename(name));
	ft_putstr(": ");
	ft_putstr(str);
	ft_putstr(": ");
	if (tp == 0)
		ft_putstr(strerror(errno));
	if (tp == 1)
		ft_putstr("Is a directory\n");
}

void	ft_cat(SalutLaMoulinette)
{
	int		rtn;
	char	buffer[0];

	while ((rtn = read(0, buffer, 1)))
		ft_putstr(buffer);
}

void	ft_display_file(char *str, char *name)
{
	int		display;
	int		rtn;
	char	buffer;

	if ((display = open(str, O_DIRECTORY) == -1))
	{
		if ((display = open(str, O_RDONLY) == -1))
		{
			cat_error(str, 0, name);
			return ;
		}
		buffer = '\0';
		while ((rtn = read(display, &buffer, 1)))
			ft_putstr(&buffer);
	}
	else
	{
		cat_error(str, 1, name);
		return ;
	}
	if (close(display) == -1)
		return ;
}

int		main(int ac, char **av)
{
	int y;

	y = 0;
	while (ac == 1)
	{
		ft_cat();
	}
	while (++y < ac)
	{
		ft_display_file(av[y], av[0]);
	}
	return (0);
}
