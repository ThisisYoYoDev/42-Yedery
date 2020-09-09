/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:54:18 by yedery            #+#    #+#             */
/*   Updated: 2020/08/26 11:54:28 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_map_error(void)
{
	write(2, "map error\n", 10);
}

void	ft_first_line(char *file, struct s_bsq *toto)
{
	int		count;
	int		fd;
	char	buffer[2];

	count = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
			break ;
		else
			count++;
	}
	close(fd);
	toto->ftl = malloc(sizeof(char*) * count + 1);
	count = -1;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1))
	{
		if (buffer[0] == '\n')
			break ;
		else
			toto->ftl[++count] = buffer[0];
	}
	close(fd);
}

int		ft_atoi(struct s_bsq *toto)
{
	char	*temp;
	int		i;
	int		res;
	int		y;
	int		n;

	i = 0;
	y = 0;
	n = 0;
	res = ft_strlen(toto->ftl) - 3;
	temp = malloc(sizeof(char) * ft_strlen(toto->ftl) + 1);
	temp = toto->ftl;
	if (temp[i] < '0' || temp[i] > '9')
	{
		ft_map_error();
		return (0);
	}
	while (temp[i] >= '0' && temp[i] <= '9' && n < res)
	{
		y = y * 10 + *temp - '0';
		temp++;
		n++;
	}
	toto->height = y;
	return (y);
}

int		check_syntax_ftl(struct s_bsq *toto)
{
	int		i;
	char	*temp;
	int		res;
	int		n;

	i = 0;
	n = 0;
	res = ft_strlen(toto->ftl) - 3;
	temp = malloc(sizeof(char) * ft_strlen(toto->ftl) + 1);
	temp = toto->ftl;
	while (i < res)
	{
		if (temp[i] < '1' || temp[i] > '9')
		{
			ft_map_error();
			return (0);
		}
		i++;
		n++;
	}
	return (1);
}

int		check_ftl(struct s_bsq *toto)
{
	toto->empty = toto->ftl[ft_strlen(toto->ftl) - 3];
	toto->obstacle = toto->ftl[ft_strlen(toto->ftl) - 2];
	toto->full = toto->ftl[ft_strlen(toto->ftl) - 1];
	if (toto->empty == toto->obstacle
		|| toto->obstacle == toto->full
		|| toto->full == toto->empty)
	{
		ft_map_error();
		return (0);
	}
	else
		return (1);
}

int		check_width(struct s_bsq *toto, char *file)
{
	int		width;
	char	buffer[2];
	int		fd;

	width = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1) && buffer[0] != '\n')
		width = 0;
	while (read(fd, buffer, 1) && buffer[0] != '\n')
		width++;
	close(fd);
	toto->width = width;
	return (1);
}

int		check_height(struct s_bsq *toto, char *file)
{
	int		height;
	char	buffer[2];
	int		fd;
	int		i;

	i = 0;
	height = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buffer, 1) && buffer[0] != '\n')
		height = 0;
	while (read(fd, buffer, 1))
	{
		i++;
		if (buffer[0] == '\n')
			height++;
	}
	close(fd);
	toto->height = height;
	return (1);
}

int		ft_no_param(int ac, struct s_bsq *toto)
{
	char	buffer[5000];
	int		nb_l;
	int		c_m;
	int		l_m;

	nb_l = 0;
	l_m = 0;
	if (ac != 1)
		return (0);
	read(1, buffer, 20);
	toto->ftl = buffer;
	while (read(1, buffer, 1))
	{
		if (buffer[0] != '\n')
		{
			toto->map[l_m][c_m] = buffer[0];
			c_m++;
		}
		else if (buffer[0] == '\n')
		{
			toto->map[l_m][c_m] = '\n';
			c_m = 0;
			l_m++;
		}
	}
	return (1);
}

int		main(int ac, char **av)
{
	struct s_bsq toto;
	ft_first_line(av[1], &toto);
	check_syntax_ftl(&toto);
	ft_atoi(&toto);
	check_ftl(&toto);
	check_width(&toto, av[1]);
	check_height(&toto, av[1]);
	ft_no_param(ac, &toto);
	return (0);
}
