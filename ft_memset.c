/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:36:06 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/21 19:44:36 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	u_c;

	u_c = (t_uchar)c;
	i = 0;
	while (i < len)
	{
		*((t_uchar *)b + i) = u_c;
		i++;
	}
	return (b);
}
