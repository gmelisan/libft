/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:20:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/20 18:10:07 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef unsigned char	t_uchar;

/*
** Part 1
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
/* ft_memmove */
/* ft_memchr */
/* ft_memcmp */
/* ft_strlen */
/* ft_strdup */
/* ft_strcpy */
/* ft_strncpy */
/* ft_strcat */
/* ft_strncat */
/* ft_strlcat */
/* ft_strchr */
/* ft_strrchr */
/* ft_strstr */
/* ft_strnstr */
/* ft_strcmp */
/* ft_strncmp */
/* ft_atoi */
/* ft_isalpha */
/* ft_isdigit */
/* ft_isalnum */
/* ft_isascii */
/* ft_isprint */
/* ft_toupper */
/* ft_tolower */

#endif
