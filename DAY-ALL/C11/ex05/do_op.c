/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:22:44 by yedery            #+#    #+#             */
/*   Updated: 2020/08/18 11:22:45 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		check_opp(char *str)
{
	if (str[0] == '+' || str[0] == '-' || str[0] == '*' || str[0] == '/'
	|| str[0] == '%')
		return (1);
	else
		return (0);
}

void	opp(int a, int b, char calc)
{
	if (calc == '+')
		ft_putnbr(ft_add(a, b));
	else if (calc == '-')
		ft_putnbr(ft_sub(a, b));
	else if (calc == '*')
		ft_putnbr(ft_multi(a, b));
	else if (calc == '/')
	{
		if (b == 0)
			ft_putstr("Stop : division by zero");
		else
			ft_putnbr(ft_div(a, b));
	}
	else if (calc == '%')
	{
		if (b == 0)
			ft_putstr("Stop : modulo by zero");
		else
			ft_putnbr(ft_mod(a, b));
	}
}

int		main(int ac, char **av)
{
	int		a;
	int		b;
	char	calc;

	if (ac != 4)
		return (0);
	if (ft_strlen(av[2]) != 1)
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (0);
	}
	if (!check_opp(av[2]))
	{
		ft_putnbr(0);
		ft_putstr("\n");
		return (0);
	}
	calc = av[2][0];
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	opp(a, b, calc);
	ft_putstr("\n");
}
