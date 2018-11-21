/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:39:38 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/21 19:43:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	t_uchar *src_copy;

	src_copy = (t_uchar *)malloc(n);
	ft_memcpy(src_copy, src, n);
	ft_memcpy(dst, src_copy, n);
	free(src_copy);
	return (dst);
}
