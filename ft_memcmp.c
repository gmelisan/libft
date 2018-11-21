/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:35:55 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/21 19:43:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t i;
	t_uchar cb1;
	t_uchar cb2;

	i = 0;
	while (i < len)
	{
		cb1 = *((t_uchar *)b1 + i);
		cb2 = *((t_uchar *)b2 + i);
		if (cb1 != cb2)
			return (cb1 - cb2);
		i++;
	}
	return (0);
}
