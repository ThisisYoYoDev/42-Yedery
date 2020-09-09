/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:09:44 by yedery            #+#    #+#             */
/*   Updated: 2020/08/10 17:50:34 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int y;

	y = 2;
	if (nb <= 1)
		return (0);
	while (y <= nb / y)
	{
		if (nb % y == 0)
			return (0);
		y++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int y;

	y = nb;
	while (y >= nb)
	{
		if (ft_is_prime(y))
			return (y);
		y++;
	}
	return (nb);
}
