/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yedery <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:49:12 by yedery            #+#    #+#             */
/*   Updated: 2020/08/26 11:49:14 by yedery           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


struct		s_bsq
{
	int		height;
	int		width;
	int		ic;
	int		il;
	int		size;
	char	empty;
	char	obstacle;
	char	full;
	char	**map;
	char	*ftl;
};

#endif
