#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef FT_STOCK_PAR_H

# define FT_STOCK_PAR_H

typedef struct		s_stock_str
{
	int size;
	char *str;
	char *copy;
}					t_stock_str;

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
	int			i;
	t_stock_str *tab;

		i = 0;

	if (!(tab = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		if(!(tab[i].str = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return (NULL);
		tab[i].str = av[i];
		if(!(tab[i].copy = malloc(sizeof(char) * ft_strlen(av[i]) + 1)))
			return(NULL);
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = NULL;
	return (tab);
}

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
		i++;
	}
}

int	main(int ac, char **av)
{
	struct s_stock_str *tab = ft_strs_to_tab(ac, av);
	ft_show_tab(tab);
	return (0);
}
