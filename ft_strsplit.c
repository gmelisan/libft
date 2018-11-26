/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 23:15:49 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/26 00:25:54 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_size(char const *s, char c)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i] != '\0')
			i++;
		size++;
	}
	return (size);
}

/* static int	get_len(char const *s, char c, int start) */
/* { */
/* 	int len; */
/* 	int i; */

/* 	i = 0; */
/* 	len = 0; */
/* 	while (s[i] == c) */
/* 		i++; */
/* 	while (s[i] != c && s[i] != '\0') */
/* 	{ */
/* 		len++; */
/* 		i++; */
/* 	} */
/* 	return (len); */
/* } */

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		from;
	int		len;

	res = (char **)malloc(sizeof(*res) * (count_size(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_size(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		from = i;
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			len++;
		}
		res[j] = ft_strsub(s, from, len);
		if (!res[j])
			return (NULL);
		j++;
	}
	res[j] = 0;
	return (res);
}
