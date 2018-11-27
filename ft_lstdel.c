/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:13:35 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 17:48:20 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *iter;
	t_list *temp;

	iter = *alst;
	while (iter)
	{
		temp = iter->next;
		ft_lstdelone(&iter, del);
		iter = temp;
	}
}

/*

[ ] -> [ ] -> [ ] -> null

*/
