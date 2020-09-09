/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:55:12 by yedery            #+#    #+#             */
/*   Updated: 2020/08/10 21:55:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_c(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		count;
	int		word;

	count = 0;
	word = 0;
	while (*str)
	{
		if (is_c(*str, charset))
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

int		w_size(char *str, char *charset, int pos)
{
	int		y;

	y = 0;
	while (str[pos])
	{
		if (!is_c(str[pos], charset))
			y++;
		pos++;
	}
	return (y);
}

void	split_it(char **tab, char *str, char *charset)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while (str[++i])
	{
		if (!is_c(str[i], charset))
		{
			if (k == 0)
				if (!(tab[j] = malloc(sizeof(char) *
				(w_size(str, charset, i) + 1))))
					return ;
			tab[j][k] = str[i];
			tab[j][k + 1] = '\0';
			k++;
		}
		if ((is_c(str[i], charset) && !is_c(str[i + 1], charset) && k > 0)
		&& (k = 0) == 0)
			j++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;

	if (!(tab = malloc(sizeof(char*) * (count_words(str, charset) + 1))))
		return (NULL);
	split_it(tab, str, charset);
	tab[count_words(str, charset)] = NULL;
	return (tab);
}
