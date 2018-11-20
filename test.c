/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:49 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/20 18:32:31 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "libft.h"

void	test_memset()
{
	printf("=== Testing ft_memset ===\n");
	char str1[50] = "Hello, world";
	char str2[50] = "Hello, world";

	memset(str1 + 3, '.', 8 * sizeof(char));
	ft_memset(str2 + 3, '.', 8 * sizeof(char));

	if (strcmp(str1, str2) == 0)
		printf("\tTest1 ok\n");
	else
	{
		printf("\tTest1 ERROR\n");
		printf("\t>%s != %s\n", str1, str2);
	}
	printf("\n");
}

void	test_bzero()
{
	printf("=== Testing ft_bzero  ===\n");
	char str1[50] = "Hello, world";
	char str2[50] = "Hello, world";

	bzero(str1, 0);
	ft_bzero(str2, 0);
	printf("\tTest1 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\n");
		printf("\t>%s != %s\n", str1, str2);
	}

	bzero(str1, 10);
	ft_bzero(str2, 10);
	printf("\tTest2 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\n");
		printf("\t>%s != %s\n", str1, str2);
	}

}

void	test_memcpy()
{
	printf("=== Testing ft_memcpy  ===\n");
	char str1[10] = "Hello...";
	char str2[10] = "Hello...";
	char src[10] =  "..World";

	printf("\tTest1 ");
	
	memcpy(str1, src, 5);
	ft_memcpy(str2, src, 5);
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\n");
		printf("\t    >%s\n\tft_ >%s\n", str1, str2);
	}
	
	char str1_2[10] = ".........";
	char str2_2[10] = ".........";
	char src_2[10] =  "1 2 3 4";

	printf("\tTest2 ");
	
	memcpy(str1_2, src_2, 5);
	ft_memcpy(str2_2, src_2, 5);
	if (strcmp(str1_2, str2_2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\n");
		printf("\t  >%s\n\tft>%s\n", str1_2, str2_2);
	}

	

}

void	test_memccpy()
{
	printf("=== Testing ft_memccpy  ===\n");
	char str1[20] = "..........";
	char str2[20] = "..........";
	char src[20] =  "1234.56789";

	printf("\tTest1 ");
	
	char *c1 = memccpy(str1, src, '.', 7);
	char *c2 = ft_memccpy(str2, src, '.', 7);
	if (strcmp(str1, str2) == 0 && *c1 == *c2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\n");
		printf("\t    >%s, c=%c\n", str1, *c1);
		printf("\tft_ >%s, c=%c\n", str2, *c2);
	}
}

int		main(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
}
