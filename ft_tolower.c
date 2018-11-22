/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:31:55 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/22 17:32:58 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int c)
{
	t_uchar uc;

	uc = (t_uchar)c;
	if (uc >= 'A' && uc <= 'Z')
		return (uc - ('A' - 'a'));
	return (c);
}
