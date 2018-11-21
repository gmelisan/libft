/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:20:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/21 21:46:11 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_uchar;

/*
** Part 1
*/

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *b, int c, size_t len);
int		ft_memcmp(const void *b1, const void *b2, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s, const char *append);
char	*ft_strncat(char *s, const char *append, size_t count);
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
