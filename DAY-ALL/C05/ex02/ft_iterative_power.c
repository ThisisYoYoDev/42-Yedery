/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:06:19 by yedery            #+#    #+#             */
/*   Updated: 2020/08/10 14:06:21 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int y;
	int z;

	y = power;
	z = 1;
	if (power < 0)
		return (0);
	while (y > 0)
	{
		z *= nb;
		y--;
	}
	return (z);
}
