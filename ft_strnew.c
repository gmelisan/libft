/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 18:47:17 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/23 19:23:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;
	size_t	i;

	if (size == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	i = 0;
	while (i < size)
		ret[i++] = '\0';
	return (ret);
}
