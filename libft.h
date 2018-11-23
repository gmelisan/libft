/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:20:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/23 19:54:30 by gmelisan         ###   ########.fr       */
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
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strncat(char *s1, const char *s2, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isspace(int c);

/*
** Part 2
*/

void	*ft_memalloc(size_t size);

/*
** Allocates (with malloc(3)) and returns a "fresh" memory area. 
** The memory allocated is initialized to 0. 
** If the allocation fails, the function returns NULL.
**
** size: The size of the memory that needs to be allocated.
** return: The allocated memory area.
*/

void	ft_memdel(void **ap);

/*
** Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
**
** ap: A pointer's address that needs its memory freed and set to NULL.
*/

char	*ft_strnew(size_t size);

/*
** Allocates (with malloc(3)) and returns a "fresh" string ending with '\0'. 
** Each character of the string is initialized at '\0'. 
** If the allocation fails, the function returns NULL.
**
** size: The size of the string to be allocated.
** return: The string allocated and initialized to 0.
*/

void	ft_strdel(char **as);
void	ft_strclr(char *s);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
/* ft_strjoin(); */
/* ft_strtrim(); */
/* ft_strsplit(); */
/* ft_itoa(); */
/* ft_putchar(); */
/* ft_putstr(); */
/* ft_putendl(); */
/* ft_putnbr(); */
/* ft_putchar_fd(); */
/* ft_putstr_fd(); */
/* ft_putendl_fd(); */
/* ft_putnbr_fd(); */


#endif
