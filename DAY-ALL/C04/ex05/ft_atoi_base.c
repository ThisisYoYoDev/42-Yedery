/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 09:26:53 by yedery            #+#    #+#             */
/*   Updated: 2020/08/09 09:26:55 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int y;

	y = 0;
	while (str[y])
		y++;
	return (y);
}

int	if_base(char c, char *base)
{
	int y;

	y = 0;
	while (base[y] != '\0' && base[y] != c)
		y++;
	return (y);
}

int	is_in_base(char c, char *base)
{
	int y;

	y = 0;
	while (base[y])
	{
		if (base[y] == c)
			return (1);
		y++;
	}
	return (0);
}

int	check_base_atoi(char *base_atoi)
{
	int y;
	int z;

	y = 0;
	if (base_atoi[0] == '\0' || base_atoi[1] == '\0')
		return (0);
	while (base_atoi[y])
	{
		z = y + 1;
		if (base_atoi[y] == '+' || base_atoi[y] == '-' || base_atoi[y] == ' '
			|| base_atoi[y] == '\n' || base_atoi[y] == '\r'
			|| base_atoi[y] == '\t' || base_atoi[y] == '\v'
			|| base_atoi[y] == '\f')
			return (0);
		if (base_atoi[y] < 32 && base_atoi[y] > 126)
			return (0);
		while (base_atoi[z])
		{
			if (base_atoi[y] == base_atoi[z])
				return (0);
			z++;
		}
		y++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int y;
	int nbrneg;

	y = 0;
	nbrneg = 1;
	if (!check_base_atoi(base))
		return (0);
	while ((str[y] == ' ') || (str[y] == '\t')
		|| (str[y] == '\n') || (str[y] == '\v')
		|| (str[y] == '\r') || (str[y] == '\f'))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			nbrneg = -nbrneg;
		str++;
	}
	while (is_in_base(*str, base))
	{
		y = y * ft_strlen(base) + if_base(*str, base);
		str++;
	}
	return (y * nbrneg);
}
