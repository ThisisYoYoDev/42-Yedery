/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:21:56 by yedery            #+#    #+#             */
/*   Updated: 2020/08/15 16:35:10 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef FT_STOCK_PAR_H

# define FT_STOCK_PAR_H

typedef struct		s_stock_par
{
	int		size_params;
	char	*str;
	char	*copy;
	char	**tab;
}					t_stock_par;

struct s_stock_par	*ft_param_to_tab(int ac, char **av);

char **ft_split_whitespaces(char *str);

#endif

int	ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		y;

	str = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	y = 0;
	while (src[y])
	{
		str[y] = src[y];
		y++;
	}
	str[y] = '\0';
	return (str);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str *tab;
	int			i;

	if (!(tab = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		if(!(tab[i].str = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].str = ft_strlen(av[i]);
		if(!(tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return(NULL);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

#include <unistd.h>

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

void	ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	struct s_stock_str *tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab);
	return (0);
}
