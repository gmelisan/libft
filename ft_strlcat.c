/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 11:11:32 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/22 13:50:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len1;
	size_t len2;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (size > len1 + len2)
	{
		ft_strcat(dst, src);
		return (len1 + len2);
	}
	else
	{
		return (len1 + size);
	}
}

/*
buf[10] = "Hello,"

str = "World."

ft_strlcat(buf, str, 10) -> 12(6+6)
ft_strlcat(buf, str, 9) -> 12 (6+6)
ft_strlcat(buf, str, 8) -> 12 (6+6)
ft_strlcat(buf, str, 7) -> 12 (6+6)
ft_strlcat(buf, str, 6) -> 12 (6+6)
ft_strlcat(buf, str, 5) -> 11 (6+5)
ft_strlcat(buf, str, 4) -> 10 (6+4)
ft_strlcat(buf, str, 3) -> 9  (6+3)
ft_strlcat(buf, str, 2) -> 8  (6+2)
ft_strlcat(buf, str, 1) -> 7  (6+1)
ft_strlcat(buf, str, 0) -> 6  (6+0)
*/
