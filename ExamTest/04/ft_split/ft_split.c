/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwuensche <fwuensche@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 08:09:54 by fwuensche         #+#    #+#             */
/*   Updated: 2019/03/05 08:26:58 by fwuensche        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		count_words(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		// move to the beggining of a new word
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			count++;
			// move to the next whitespace
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	return (count);
}

char	*malloc_word(char *str)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));

	// same as count_words, except we save word to array instead of counting
	int i = 0;
	while (*str)
	{
		// move to the beggining of a new word
		while (*str && ft_isspace(*str))
			str++;
		if (*str && !ft_isspace(*str))
		{
			// save word to array
			arr[i] = malloc_word(str);
			i++;
			// move to the next whitespace
			while (*str && !ft_isspace(*str))
				str++;
		}
	}
	arr[i] = NULL;
	return (arr);
}

#include <stdio.h>

int		main(int ac, char **av)
{
	char **arr;

	char *phrase = "   Hello,   test\t toyo!  ";
	arr = ft_split(phrase);
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
}
// version courte



#include <stdlib.h>

int	ft_isspace(char c)
{
	return ((c == ' ' || (c >= 9 && c <= 13)) ? 1 : 0);
}

static int	r_size(char *s)
{
	unsigned int len;

	len = 0;
	while (*s)
	{
		if (ft_isspace(*s))
			++s;
		else
		{
			++len;
			while (*s && !ft_isspace(*s))
				++s;
		}
	}
	return (len);
}

char 		**ft_split(char *s)
{
	int		i = 0;
	int		j = 0;
	int		k;
	char	**r;
	int		w_len = 0;

	if (!(r = (char **)malloc(sizeof(char*) * (r_size(s) + 1))))
		return (0);
	while (s[i] && j < r_size(s))
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		while (s[i] && !ft_isspace(s[i]))
		{
			w_len++;
			i++;
		}
		if (!(r[j] = (char *)malloc(sizeof(char) * (w_len + 1))))
			return (0);
		k = 0;
		while (w_len)
			r[j][k++] = s[i - w_len--];
		r[j++][k] = '\0';
	}
	return (r);
}