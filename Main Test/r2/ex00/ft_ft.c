/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:07:57 by yedery            #+#    #+#             */
/*   Updated: 2020/08/23 15:08:38 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int		ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

int		max_count(char *str)
{
	int	counter;
	int	y;

	counter = 0;
	y = 0;
	if ((!(str[y + 1] >= '0' && str[y + 1] <= '9')) && (str[y] == '0'))
		return (0);
	while (str[y] && str[y] != ':')
	{
		if (str[y] >= '1' && str[y] <= '9')
			counter += str[y];
		else if (str[y] == '0')
			counter += 100;
		y++;
	}
	return (counter);
}

int		check_zero(char *str)
{
	int y;

	y = 0;
	while (str[y] != '\0')
	{
		if (str[y] != '0')
			return (0);
		y++;
	}
	return (1);
}
