/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:17:03 by yedery            #+#    #+#             */
/*   Updated: 2020/08/22 19:37:37 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush.h"

int		counter_lines_fd(int fd)
{
	int		counter;
	int		retn;
	char	buffer[10];

	counter = 0;
	while ((retn = read(fd, buffer, 1)))
	{
		if (buffer[0] == '\n')
			counter++;
	}
	return (counter);
}

void	ft_sort_string_tab(char **tab)
{
	int		y;
	int		z;
	char	*swap;

	y = 0;
	z = 0;
	while (tab[y])
	{
		z = y + 1;
		while (tab[z])
		{
			if (max_count(tab[y]) > max_count(tab[z]))
			{
				swap = tab[z];
				tab[z] = tab[y];
				tab[y] = swap;
			}
			z++;
		}
		y++;
	}
}

void	tab_saver(char **tab, int fd)
{
	int		counter;
	int		retn;
	int		y;
	char	buffer[10];

	y = 0;
	counter = 0;
	while ((retn = read(fd, buffer, 1)))
	{
		y++;
		if (buffer[0] == '\n')
		{
			if (!(tab[counter] = malloc(sizeof(char*) * (y + 1))))
				break ;
			y = 0;
			counter++;
		}
	}
	tab[counter] = NULL;
}

void	r_filler(char **tab, int fd)
{
	int		counter;
	int		retn;
	int		y;
	char	buffer[10];

	y = 0;
	counter = 0;
	while ((retn = read(fd, buffer, 1)))
	{
		tab[counter][y] = buffer[0];
		tab[counter][y + 1] = '\0';
		y++;
		if (buffer[0] == '\n')
		{
			y = 0;
			counter++;
		}
	}
	tab[counter] = NULL;
}

char	**dict_parser(void)
{
	int		y;
	int		fd;
	char	**tab;

	if ((fd = open(EN_DICT_NUMBER, O_RDONLY)) == -1)
		return (NULL);
	if (!(tab = malloc(sizeof(char*) * (counter_lines_fd(fd) + 1))))
		return (NULL);
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open(EN_DICT_NUMBER, O_RDONLY)) == -1)
		return (tab);
	tab_saver(tab, fd);
	if (close(fd) == -1)
		return (NULL);
	if ((fd = open(EN_DICT_NUMBER, O_RDONLY)) == -1)
		return (tab);
	r_filler(tab, fd);
	ft_sort_string_tab(tab);
	if (close(fd) == -1)
		return (NULL);
	y = -1;
	while (tab[++y])
		splitter(tab[y]);
	return (tab);
}
