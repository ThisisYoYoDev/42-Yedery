/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 15:06:56 by yedery            #+#    #+#             */
/*   Updated: 2020/08/23 15:07:26 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define DICT "numbers.dict"
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char	**dict_parser(void);
char	*splitter(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		max_count(char *str);
void	printer(char *str, char **tab);
int		check_zero(char *str);

#endif
