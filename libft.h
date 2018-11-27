/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:20:56 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 20:07:59 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_uchar;
typedef unsigned int	t_uint;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** Part 1
*/

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

/*
** Part 2
*/

void				*ft_memalloc(size_t size);

/*
** Allocates (with malloc(3)) and returns a "fresh" memory area.
** The memory allocated is initialized to 0.
** If the allocation fails, the function returns NULL.
**
** size: The size of the memory that needs to be allocated.
** return: The allocated memory area.
*/

void				ft_memdel(void **ap);

/*
** Takes as a parameter the address of a memory area that needs
** to be freed with free(3), then puts the pointer to NULL.
**
** ap: A pointer's address that needs its memory freed and set to NULL.
*/

char				*ft_strnew(size_t size);

/*
** Allocates (with malloc(3)) and returns a "fresh" string ending with '\0'.
** Each character of the string is initialized at '\0'.
** If the allocation fails, the function returns NULL.
**
** size: The size of the string to be allocated.
** return: The string allocated and initialized to 0.
*/

void				ft_strdel(char **as);

/*
** Takes as a parameter the address of a string that need to be freed
** with free(3), then sets its pointer to NULL.
**
** as: The string's address that needs to be freed and its pointer set to NULL.
*/

void				ft_strclr(char *s);

/*
** Sets every character of the string to the value '\0'.
**
** s: The string that needs to be cleared.
*/

void				ft_striter(char *s, void (*f)(char *));

/*
** Applies the function f to each character of the string passed as argument.
** Each character is passed by address to f to be modified if necessary.
**
** s: The string to iterate.
** f: The function to apply to each character of s.
*/

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Applies the function f to each character of the string passed as argument,
** and passing its index as first argument. Each character is passed by
** address to f to be modified if necessary.
**
** s: The string to iterate.
** f: The function to apply to each character of s and its index.
*/

char				*ft_strmap(char const *s, char (*f)(char));

/*
** Applies the function f to each character of the string given as argument
** to create a "fresh" new string (with malloc(3)) resulting from successive
** applications of f.
**
** s: The string to map.
** f: The function to apply to each character of s.
** return: The "fresh" string created from the successive applications of f.
*/

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Applies the function f to each character of the string passed as argument
** by giving its index as first argument to create a "fresh" new string
** (with malloc(3)) resulting from the successive applications of f.
**
** s: The string to map.
** f: The function to apply to each character of s and its index.
** return: The "fresh" string created from the successive applications of f.
*/

int					ft_strequ(char const *s1, char const *s2);

/*
** Lexicographical comparison between s1 and s2. If the 2 strings are identical
** the function returns 1, or 0 otherwise.
**
** s1: The first string to be compared.
** s2: The second string to be compared.
** return: 1 or 0 according to if the 2 strings are identical or not.
*/

int					ft_strnequ(char const *s1, char const *s2, size_t n);

/*
** Lexicographical comparison between s1 and s2 up to n characters or until
** a '\0' is reached. If the 2 strings are identical, the function returns 1,
** or 0 otherwise.
**
** s1: The first string to be compared.
** s2: The second string to be compared.
** n: The maximum number of characters to be compared.
** return: 1 or 0 according to if the 2 strings are identical or not.
*/

char				*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Allocates (with malloc(3)) and returns a "fresh" substring from the
** given as argument. The substring begins at index 'start' and
** is of size 'len'. If 'start' and 'len' aren't refering to a valid
** substring, the behavior is undefined. If the allocation fails,
** the function returns NULL.
**
** s: The string from which create the substring.
** start: The start index of the substring.
** len: The size of the substring.
** return: The substring.
*/

char				*ft_strjoin(char const *s1, char const *s2);

/*
** Allocates (with malloc(3)) and returns a "fresh" string ending with '\0',
** result of the concatenation of s1 and s2. If the allocation fails
** the function returns NULL.
**
** s1: The prefix string.
** s2: The suffix string.
** return: The "fresh" string result of the concatenation of the 2 strings.
*/

char				*ft_strtrim(char const *s);

/*
** Allocates (with malloc(3)) and returns a copy of the string given as
** argument without whitespaces at the beginning or at the end of the
** string. Will be considereed as whitespaces the following characters
** ' ', '\n' and '\t'. If s has no whitespaces at the beginning or
** at the end, the function returns a copy of s. If the allocation fails
** the function returns NULL.
**
** s: The string to be trimmed.
** return: The "fresh" trimmed string or a copy of s.
*/

char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** Part 3 (bonus)
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
