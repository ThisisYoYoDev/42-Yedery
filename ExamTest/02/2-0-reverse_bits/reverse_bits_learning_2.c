/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits_learning_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 10:30:48 by yedery            #+#    #+#             */
/*   Updated: 2020/08/13 10:37:16 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	return (((octet >> 0) & 1) << 7) | \
		   (((octet >> 1) & 1) << 6) | \
		   (((octet >> 2) & 1) << 5) | \
		   (((octet >> 3) & 1) << 4) | \
		   (((octet >> 4) & 1) << 3) | \
		   (((octet >> 5) & 1) << 2) | \
		   (((octet >> 6) & 1) << 1) | \
		   (((octet >> 7) & 1) << 0); 
}

int main(void)
{
	char c[] = "00100110";
	printf ("result : %u\n", reverse_bits(c));
	return (0);
}
