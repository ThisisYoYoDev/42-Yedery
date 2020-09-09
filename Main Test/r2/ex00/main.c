/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:10:16 by yedery            #+#    #+#             */
/*   Updated: 2020/08/23 15:10:52 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*read_entry(void)
{
	char	*buffer;
	int		retn;

	if (!(buffer = malloc(sizeof(char*) * 100)))
		return (NULL);
	retn = read(0, buffer, 100);
	return (buffer);
}

void	ft_free(char **tab)
{
	int		y;

	y = 0;
	while (tab[y] != '\0')
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

int		is_ag(char *str)
{
	int		counter;
	int		y;

	counter = 0;
	y = 0;
	while (str[y] != '\0')
	{
		if (!(str[y] >= '0' && str[y] <= '9'))
			return (0);
		y++;
	}
	y = 0;
	while (str[y] == '0')
		y++;
	while (str[y] != '\0')
	{
		y++;
		counter++;
	}
	if (counter > 39)
		return (0);
	return (1);
}

int		main(int ac, char **av)
{
	char	*ag;
	char	**tab;

	if (ac != 2 || *av[1] == 0)
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ac == 2)
		ag = av[1];
	if (ac == 1)
	{
		ag = read_entry();
		if (ft_strlen(ag) > 1)
			ag[ft_strlen(ag) - 1] = '\0';
	}
	if (!is_ag(ag))
	{
		ft_putstr("Error\n");
		return (0);
	}
	tab = dict_parser();
	printer(ag, tab);
	ft_free(tab);
	return (0);
}
