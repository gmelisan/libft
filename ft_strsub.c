/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:54:35 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/23 20:06:51 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	i;
	char	*res;

	slen = ft_strlen(s);
	if (start > slen)
		return (NULL);
	res = ft_strnew(len);
	i = 0;
	while (i < len)
	{
		
	}
	
}

/*


"Hello,wrld"
 0123456789

start = 6
len = 7

newlen = 7 - (10 - 6)


*/
