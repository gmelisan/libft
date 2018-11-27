/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:49 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/27 21:20:24 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

void	test_memset()
{
	char *str1;
	char *str2;

	printf("=== Testing ft_memset ===\n");
	str1 = (char*)malloc(sizeof(char) * 50);
	str2 = (char*)malloc(sizeof(char) * 50);
	
	memset(str1, '.', 10 * sizeof(char));
	str1[10] = '\0';
	ft_memset(str2, '.', 10 * sizeof(char));
	str2[10] = '\0';
	printf("\tTest1 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' != \n\t'%s'\n", str1, str2);
	}
    memset(str1 + 10, '!', 20 * sizeof(char));
	str1[30] = '\0';
	ft_memset(str2 + 10, '!', 20 * sizeof(char));
	str2[30] = '\0';
	printf("\tTest2 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' != \n\t'%s'\n", str1, str2);
	}

	memset(str1 + 30, '?', 19 * sizeof(char));
	str1[49] = '\0';
	ft_memset(str2 + 30, '?', 19 * sizeof(char));
	str2[49] = '\0';
	printf("\tTest3 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' != \n\t'%s'\n", str1, str2);
	}
	free(str1);
	free(str2);
}

void	test_bzero()
{
	int *arr1;
	int *arr2;
	int i;
	int err_flag;

	printf("=== Testing ft_bzero  ===\n");
	arr1 = (int*)malloc(sizeof(int) * 10);
	arr2 = (int*)malloc(sizeof(int) * 10);
	bzero(arr1, sizeof(int) * 10);
	ft_bzero(arr2, sizeof(int) * 10);
	printf("\tTest1 ");
	i = 0;
	err_flag = 0;
	while (i < 10)
	{
		if (arr1[i] != 0 || arr2[i] != 0)
		{
			printf("ERROR\t\t!!!\n");
			printf("\tarr1[%d] = %d\n\tarr2[%d] = %d\n",
				   i, arr1[i], i, arr2[i]);
			err_flag = 1;
			break;
		}
		i++;
	}
	if (!err_flag)
		printf("ok\n");
	free(arr1);
	free(arr2);
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
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
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
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1_2, str2_2);
	}
}

void	test_memccpy()
{
	printf("=== Testing ft_memccpy  ===\n");
	/* printf("* note: if c = ~, then c = null pointer\n"); */
	char str1[20] = ".......a..";
	char str2[20] = ".......a..";
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
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
		printf("\tc1 = %c\n\tc2 = %c\n", *c1, *c2);
	}

	char str1_2[50];
	char str2_2[50];
	char src_2[50] = "Hello dark";

	printf("\tTest2 ");
	
	c1 = memccpy(str1_2, src_2, '.', 20);
	c2 = ft_memccpy(str2_2, src_2, '.', 20);
	if (strcmp(str1_2, str2_2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1_2, str2_2);
		printf("\tc1 = %c\n\tc2 = %c\n", c1 ? *c1 : '~', c2 ? *c2 : '~');
		
	}

	char str1_3[50];
	char str2_3[50];
	char src_3[50] = "Hello darkness, my old friend"; /* 29 chars */

	printf("\tTest3 ");
	
	c1 = memccpy(str1_3, src_3, '.', 28);
	str1_3[28] = 0;
	c2 = ft_memccpy(str2_3, src_3, '.', 28);
	str2_3[28] = 0;
	
	if (strcmp(str1_3, str2_3) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1_3, str2_3);
		printf("\tc1 = %c\n\tc2 = %c\n", c1 ? *c1 : '~', c2 ? *c2 : '~');
		
	}
}

void	test_memmove()
{
	printf("=== Testing ft_memmove  ===\n");

	char str1[] = "abcdefghijk"; /* 11 chars */
	char str2[] = "abcdefghijk";

	memmove(str1 + 2, str1, 5);
	ft_memmove(str2 + 2, str2, 5);

	printf("\tTest1 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
	}

	memmove(str1 + 6, str1 + 2, 3);
	ft_memmove(str2 + 6, str2 + 2, 3);

	printf("\tTest2 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
	}

	memmove(str1 + 3, str1 + 6, 4);
	ft_memmove(str2 + 3, str2 + 6, 4);

	printf("\tTest3 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
	}
	char *str1_2 = (char*)malloc(20);
	char *str2_2 = (char*)malloc(20);
	
	
	memmove(str1_2, str1 + 3, 7);
	str1_2[7] = 0;
	ft_memmove(str2_2, str1 + 3, 7);
	str2_2[7] = 0;

	printf("\tTest4 ");
	if (strcmp(str1_2, str2_2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1_2, str2_2);
	}
	free(str1_2);
	free(str2_2);
}

void	test_memchr(void)
{
	printf("=== Testing ft_memchr ===\n");
	char str[] = "Hello darkness, my old friend"; /* 29 chars, ',' at 14 */
	char *a = memchr(str, ',', 20);
	char *b = ft_memchr(str, ',', 20);
	printf("\tTest1 ");
	if (strcmp(a, b) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", a, b);
	}
	a = memchr(str, ',', 10);
	b = memchr(str, ',', 10);
	printf("\tTest2 ");
	if (a == NULL && b == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tExpected null pointer\n");
	}
	a = memchr(str, 0, 40);
	b = memchr(str, 0, 40);
	printf("\tTest3 ");
	if (strcmp(a, b) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", a, b);
	}

}

void	test_memcmp(void)
{
	printf("=== Testing ft_memcmp ===\n");
	
	int n1;
	int n2;

	char str1[] = "abc1";
	char str2[] = "abc2";

	n1 = memcmp(str1, str2, sizeof(str1));
	n2 = ft_memcmp(str1, str2, sizeof(str1));

	printf("\tTest1 ");
	if (n1 < 0 && n2 < 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%d' !=\n\t'%d'\n", n1, n2);
	}

	char str1_2[] = "abc2";
	char str2_2[] = "abc1";

	n1 = memcmp(str1_2, str2_2, sizeof(str1_2));
	n2 = ft_memcmp(str1_2, str2_2, sizeof(str1_2));
	
	printf("\tTest2 ");
	if (n1 > 0 && n2 > 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%d' !=\n\t'%d'\n", n1, n2);
	}
	char str1_3[] = "abcdef";
	char str2_3[] = "abcdef";

	n1 = memcmp(str1_3, str2_3, sizeof(str1_3));
	n2 = ft_memcmp(str1_3, str2_3, sizeof(str1_3));
	
	printf("\tTest2 ");
	if (n1 == 0 && n2 == 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%d' !=\n\t'%d'\n", n1, n2);
	}
}

void	test_strlen(void)
{
	int n1;
	int n2;

	printf("=== Testing ft_strlen ===\n");
	
	char str[] = "Hello darkness";
	n1 = strlen(str);
	n2 = ft_strlen(str);
	
	printf("\tTest1 ");
	if (n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%d' !=\n\t'%d'\n", n1, n2);
	}
	char str2[] = "\0";
	n1 = strlen(str2);
	n2 = ft_strlen(str2);
	
	printf("\tTest2 ");
	if (n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%d' !=\n\t'%d'\n", n1, n2);
	}
}

void	test_strdup(void)
{
	char *dup1;
	char *dup2;

	printf("=== Testing ft_strdup ===\n");

	char str[] = "Don't trust rumors!";
	dup1 = strdup(str);
	dup2 = ft_strdup(str);
	printf("\tTest1 ");
	if (memcmp(dup1, dup2, sizeof(str)) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", dup1, dup2);
	}
	free(dup1);
	free(dup2);
}

void	test_strcpy(void)
{
	char *cpy1;
	char *cpy2;

	printf("=== Testing ft_strcpy ===\n");
	char str[] = "Hello my friend!";

	cpy1 = (char *)malloc(50);
	cpy2 = (char *)malloc(50);

	strcpy(cpy1, str);
	ft_strcpy(cpy2, str);
	printf("\tTest1 ");
	if (strcmp(cpy1, cpy2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}

	char str2[] = "\0";
	
	strcpy(cpy1, str2);
	ft_strcpy(cpy2, str2);
	printf("\tTest2 ");
	if (strcmp(cpy1, cpy2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}
	free(cpy1);
	free(cpy2);	
}


void	test_strncpy(void)
{
	char *cpy1;
	char *cpy2;

	printf("=== Testing ft_strncpy ===\n");
	char str[] = "hello";

	cpy1 = (char *)malloc(50);
	cpy2 = (char *)malloc(50);

	strncpy(cpy1, str, 3);
	ft_strncpy(cpy2, str, 3);
	
	printf("\tTest1 ");
	if (memcmp(cpy1, cpy2, 3) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}

	strncpy(cpy1, str, 5);
	ft_strncpy(cpy2, str, 5);
	
	printf("\tTest2 ");
	if (memcmp(cpy1, cpy2, 5) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}
	strncpy(cpy1, str, 6);
	ft_strncpy(cpy2, str, 6);
	
	printf("\tTest3 ");
	if (memcmp(cpy1, cpy2, 6) == 0 && cpy2[5] == '\0')
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}

	strncpy(cpy1, str, 10);
	ft_strncpy(cpy2, str, 10);
	
	printf("\tTest4 ");
	if (memcmp(cpy1, cpy2, 10) == 0 && cpy2[9] == '\0')
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", cpy1, cpy2);
	}

	free(cpy1);
	free(cpy2);
}

void	test_strcat(void)
{
	char *res1;
	char *res2;

	printf("=== Testing ft_strcat ===\n");
	char str1[] = "hello ";
	char str2[] = "darkness, ";
	char str3[] = "my old";
	char str4[] = "friend.";
	
	res1 = (char *)malloc(50);
	res2 = (char *)malloc(50);
	*res1 = 0;
	*res2 = 0;

	strcat(res1, str1);
	ft_strcat(res2, str1);
	printf("\tTest1 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
	strcat(res1, str2);
	ft_strcat(res2, str2);
	printf("\tTest2 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
	strcat(res1, str3);
	ft_strcat(res2, str3);
	printf("\tTest3 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
	strcat(res1, str4);
	ft_strcat(res2, str4);
	printf("\tTest4 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
}


void	test_strncat(void)
{
	char *res1;
	char *res2;

	printf("=== Testing ft_strncat ===\n");
	char str1[] = "hello,";
	char str2[] = "world.";
	
	res1 = (char *)malloc(50);
	res2 = (char *)malloc(50);
	bzero(res1, 50);
	bzero(res2, 50);

	strcat(res1, str1);
	strcat(res2, str1);

	strncat(res1, str2, 3);
	ft_strncat(res2, str2, 3);
	
	printf("\tTest1 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}

	bzero(res1, 50);
	bzero(res2, 50);

	strcat(res1, str1);
	strcat(res2, str1);

	strncat(res1, str2, 40);
	ft_strncat(res2, str2, 40);
	
	printf("\tTest2 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
}

void	test_strlcat(void)
{
	int n1;
	int n2;
	char src[] = ", world!!!!"; /* 11 chars */
	printf("=== Testing ft_strlcat ===\n");

	char str1[20] = "Hello"; 	/* 5 chars */
	char str2[20] = "Hello";

	n1 = strlcat(str1, src, 0);
	n2 = ft_strlcat(str2, src, 0);

	printf("\tTest1 ");
	if (strcmp(str1, str2) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1, str2);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_2[20] = "Hello"; 	/* 5 chars */
	char str2_2[20] = "Hello";

	n1 = strlcat(str1_2, src, 1);
	n2 = ft_strlcat(str2_2, src, 1);

	printf("\tTest2 ");
	if (strcmp(str1_2, str2_2) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_2, str2_2);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_3[20] = "Hello";
	char str2_3[20] = "Hello";

	n1 = strlcat(str1_3, src, 2);
	n2 = ft_strlcat(str2_3, src, 2);

	printf("\tTest3 ");
	if (strcmp(str1_3, str2_3) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_3, str2_3);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_4[20] = "Hello";
	char str2_4[20] = "Hello";

	n1 = strlcat(str1_4, src, 5);
	n2 = ft_strlcat(str2_4, src, 5);

	printf("\tTest4 ");
	if (strcmp(str1_4, str2_4) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_4, str2_4);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_5[20] = "Hello";
	char str2_5[20] = "Hello";

	n1 = strlcat(str1_5, src, 6);
	n2 = ft_strlcat(str2_5, src, 6);

	printf("\tTest5 ");
	if (strcmp(str1_5, str2_5) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_5, str2_5);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_6[20] = "Hello";
	char str2_6[20] = "Hello";

	n1 = strlcat(str1_6, src, 7);
	n2 = ft_strlcat(str2_6, src, 7);

	printf("\tTest6 ");
	if (strcmp(str1_6, str2_6) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_6, str2_6);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_7[20] = "Hello";
	char str2_7[20] = "Hello";

	n1 = strlcat(str1_7, src, 10);
	n2 = ft_strlcat(str2_7, src, 10);

	printf("\tTest7 ");
	if (strcmp(str1_7, str2_7) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_7, str2_7);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_8[20] = "Hello";
	char str2_8[20] = "Hello";

	n1 = strlcat(str1_8, src, 10);
	n2 = ft_strlcat(str2_8, src, 10);

	printf("\tTest8 ");
	if (strcmp(str1_8, str2_8) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_8, str2_8);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
	char str1_9[20] = "Hello";
	char str2_9[20] = "Hello";

	n1 = strlcat(str1_9, src, 20);
	n2 = ft_strlcat(str2_9, src, 20);

	printf("\tTest9 ");
	if (strcmp(str1_9, str2_9) == 0 && n1 == n2)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_9, str2_9);
		printf("\tn1 = %d, n2 = %d\n", n1, n2);
	}
}

void	test_strchr(void)
{

	printf("=== Testing ft_strchr ===\n");

	char str1[] = "abcdefghijklmnop";
	char str2[] = "abcdefghijklmnop";
	char *a;
	char *b;

	a = strchr(str1, 'k');
	b = ft_strchr(str2, 'k');
	
	printf("\tTest1 ");
	if (strcmp(a, b) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", a, b);
	}
	printf("\tTest2 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
	}
	a = strchr(str1, 'z');
	b = ft_strchr(str2, 'z');
	
	printf("\tTest1 ");
	if (a == NULL && b == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t Expected null pointer\n");
	}
	a = strchr(str1, '\0');
	b = ft_strchr(str2, '\0');
	
	printf("\tTest1 ");
	if (*a == 0 && *b == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tValues of 'a' and/or 'b' not 0\n");
	}
	
}

void	test_strrchr(void)
{

	printf("=== Testing ft_strrchr ===\n");

	char str1[] = "abababababcdef";
	char str2[] = "abababababcdef";
	char *a;
	char *b;

	a = strrchr(str1, 'a');
	b = ft_strrchr(str2, 'a');
	
	printf("\tTest1 ");
	if (strcmp(a, b) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", a, b);
	}
	printf("\tTest2 ");
	if (strcmp(str1, str2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", str1, str2);
	}
	a = strchr(str1, 'z');
	b = ft_strchr(str2, 'z');
	
	printf("\tTest3 ");
	if (a == NULL && b == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t Expected null pointer\n");
	}
	a = strchr(str1, '\0');
	b = ft_strchr(str2, '\0');
	
	printf("\tTest4 ");
	if (*a == 0 && *b == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tValues of 'a' and/or 'b' not 0\n");
	}
	
}

void	test_strstr(void)
{
	char str[] = "String contains substring in string";
	char sub[] = "substring";
	char sub2[] = "no substring";
	char *res1;
	char *res2;

	printf("=== Testing ft_strstr ===\n");
	res1 = strstr(str, sub);
	res2 = ft_strstr(str, sub);
	
	printf("\tTest1 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}

	res1 = strstr(str, sub2);
	res2 = ft_strstr(str, sub2);
	
	printf("\tTest2 ");
	if (res1 == NULL && res2 == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Expected null pointer");
	}
	res1 = strstr(str, "");
	res2 = ft_strstr(str, "");
	
	printf("\tTest3 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}

}

void	test_strnstr(void)
{
	char str[] = ".String contains substring in String";
	char sub2[] = "String";
	char *res1;
	char *res2;

	printf("=== Testing ft_strnstr ===\n");
	res1 = strnstr(str, sub2, 10);
	res2 = ft_strnstr(str, sub2, 10);
	
	printf("\tTest1 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}

	res1 = strnstr(str, sub2, 3);
	res2 = ft_strnstr(str, sub2, 3);
	
	printf("\tTest2 ");
	if (res1 == NULL && res2 == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
	res1 = strnstr(str, sub2, 100);
	res2 = ft_strnstr(str, sub2, 100);
	
	printf("\tTest3 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}

	res1 = strnstr(str, sub2, 0);
	res2 = ft_strnstr(str, sub2, 0);
	
	printf("\tTest4 ");
	if (res1 == NULL && res2 == NULL)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
	res1 = strnstr(str, "", 10);
	res2 = ft_strnstr(str, "", 10);
	
	printf("\tTest5 ");
	if (strcmp(res1, res2) == 0)
	{
		printf("ok\n");
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\t'%s' !=\n\t'%s'\n", res1, res2);
	}
}

void	test_strcmp(void)
{
	char str1[10];
	char str2[10];
	int n1;
	int n2;
	char str1_2[] = "ab";
	char str2_2[] = "abc";
	char str1_3[] = "despera\0teon";
	char str2_3[] = "despera\0tion";

	printf("=== Testing ft_strcmp ===\n");
	
	str1[0] = 200;
	str1[1] = 0;

	str2[0] = 10;
	str2[1] = 0;

	n1 = strcmp(str1, str2);
	n2 = ft_strcmp(str1, str2);

	printf("\tTest1 ");
	if (n1 > 0 && n2 > 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be greater than 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strcmp(str1_2, str2_2);
	n2 = ft_strcmp(str1_2, str2_2);

	printf("\tTest2 ");
	if (n1 < 0 && n2 < 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be less than 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strcmp(str1_3, str2_3);
	n2 = ft_strcmp(str1_3, str2_3);

	printf("\tTest2 ");
	if (n1 == 0 && n2 == 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be equal to 0:\tn1=%d, n2=%d\n", n1, n2);
	}
}

void	test_strncmp(void)
{
	char str1[10];
	char str2[10];
	int n1;
	int n2;
	char str1_2[] = "ab";
	char str2_2[] = "abc";
	char str1_3[] = "despera1\0teon";
	char str2_3[] = "despera\0tion";

	printf("=== Testing ft_strncmp ===\n");
	
	str1[0] = 200;
	str1[1] = 0;

	str2[0] = 10;
	str2[1] = 0;

	n1 = strncmp(str1, str2, 1);
	n2 = ft_strncmp(str1, str2, 1);

	printf("\tTest1 ");
	if (n1 > 0 && n2 > 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be greater than 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strncmp(str1_2, str2_2, 4);
	n2 = ft_strncmp(str1_2, str2_2, 4);

	printf("\tTest2 ");
	if (n1 < 0 && n2 < 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be less than 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strncmp(str1_2, str2_2, 2);
	n2 = ft_strncmp(str1_2, str2_2, 2);

	printf("\tTest3 ");
	if (n1 == 0 && n2 == 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should equal to 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strncmp(str1_3, str2_3, 8);
	n2 = ft_strncmp(str1_3, str2_3, 8);

	printf("\tTest4 ");
	if (n1 > 0 && n2 > 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be greater than 0:\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = strncmp(str1_3, str2_3, 0);
	n2 = ft_strncmp(str1_3, str2_3, 0);

	printf("\tTest5 ");
	if (n1 == 0 && n2 == 0)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("Should be equal to 0:\tn1=%d, n2=%d\n", n1, n2);
	}
}
void	test_atoi(void)
{
	int a;
	int b;
	printf("=== Testing ft_atoi ===\n");
	char strings[9][20] =
	{
		{""},
		{"djcsa"},
		{"d23jcsa"},
		{"  23djcsa"},
		{"+1452djcsa"},
		{"-99999"},
		{"\t999.099"},
		{"\v-222222222222222222222222222222222551!"},
		{" \t  \n\r\v\f   +2 2 "}
	};
	int i = 0;
	while (i < 9)
	{
		printf("\tTest%d ", i + 1);
		a = atoi(strings[i]);
		b = ft_atoi(strings[i]);
		if (a == b)
		{
			printf ("ok\n");
		}
		else
		{
			printf("\tERROR\t\t!!!\n");
			printf("\t%d != %d\n", a, b);
		}
		i++;
	}
}
void	test_isalpha(void)
{
	int n1;
	int n2;
	printf("=== Testing ft_isalpha ===\n");

	n1 = isalpha('a');
	n2 = ft_isalpha('a');
	printf("\tTest1 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isalpha(-150);
	n2 = ft_isalpha(-150);
	printf("\tTest2 ");
	if (!n1 && !n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isalpha(9999);
	n2 = ft_isalpha(9999);
	printf("\tTest3 ");
	if (!n1 && !n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isalpha(113);
	n2 = ft_isalpha(113);
	printf("\tTest4 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
}
void	test_isdigit(void)
{
	printf("=== Testing ft_isdigit ===\n");
	int n1;
	int n2;

	n1 = isdigit('0');
	n2 = ft_isdigit('0');
	printf("\tTest1 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isdigit(-100);
	n2 = ft_isdigit(-100);
	printf("\tTest2 ");
	if (!n1 && !n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isdigit(9999);
	n2 = ft_isdigit(9999);
	printf("\tTest3 ");
	if (!n1 && !n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isdigit(53);
	n2 = ft_isdigit(53);
	printf("\tTest4 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
}
void	test_isalnum(void)
{
	int n1;
	int n2;
	
	printf("=== Testing ft_isalnum ===\n");
	n1 = isalnum('a');
	n2 = ft_isalnum('a');
	printf("\tTest1 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isalnum('1');
	n2 = ft_isalnum('1');
	printf("\tTest2 ");
	if (n1 && n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
	n1 = isalnum(-1);
	n2 = ft_isalnum(-1);
	printf("\tTest3 ");
	if (!n1 && !n2)
	{
		printf("ok (n1=%d, n2=%d)\n", n1, n2);
	}
	else
	{
		printf("ERROR\t\t!!!\n");
		printf("\tn1=%d, n2=%d\n", n1, n2);
	}
}

int		istrue(int a)
{
	return (a ? 1 : 0);
}

void	test_isascii(void)
{
	printf("=== Testing ft_ascii ===\n");

	int i = -100;
	int error_flag = 0;
	printf("\tTest from -100 to 500...\n");
	while (i < 501)
	{
		if (istrue(isascii(i)) != istrue(ft_isascii(i)))
		{
			printf("\tERROR\t\t!!!\n");
			printf("\tisascii(%d) = %d\n", i, isascii(i));
			printf("\tft_isascii(%d) = %d\n", i, ft_isascii(i));
			error_flag = 1;
		}
		i++;
	}
	if (!error_flag)
		printf("\tok\n");
}
void	test_isprint(void)
{
	printf("=== Testing ft_isprint ===\n");
	int i = -100;
	int error_flag = 0;
	printf("\tTest from -100 to 500...\n");
	while (i < 501)
	{
		if (istrue(isprint(i)) != istrue(ft_isprint(i)))
		{
			printf("\tERROR\t\t!!!\n");
			printf("\tisprint(%d) = %d\n", i, isprint(i));
			printf("\tft_isprint(%d) = %d\n", i, ft_isprint(i));
			error_flag = 1;
		}
		i++;
	}
	if (!error_flag)
		printf("\tok\n");
}
void	test_toupper(void)
{
	printf("=== Testing ft_toupper ===\n");
	int i = -100;
	int error_flag = 0;
	printf("\tTest from -100 to 500...\n");
	while (i < 501)
	{
		if (toupper(i) != ft_toupper(i))
		{
			printf("\tERROR\t\t!!!\n");
			printf("\ttoupper(%d) = %d\n", i, toupper(i));
			printf("\tft_toupper(%d) = %d\n", i, ft_toupper(i));
			error_flag = 1;
		}
		i++;
	}
	if (!error_flag)
		printf("\tok\n");
}
void	test_tolower(void)
{
	printf("=== Testing ft_tolower ===\n");
	int i = -100;
	int error_flag = 0;
	printf("\tTest from -100 to 500...\n");
	while (i < 501)
	{
		if (tolower(i) != ft_tolower(i))
		{
			printf("\tERROR\t\t!!!\n");
			printf("\ttolower(%d) = %d\n", i, tolower(i));
			printf("\tft_tolower(%d) = %d\n", i, ft_tolower(i));
			error_flag = 1;
		}
		i++;
	}
	if (!error_flag)
		printf("\tok\n");
}

void	test_memalloc(void)
{
	printf("=== Testing ft_memalloc ===\n");

	printf("\tft_memalloc(sizeof(int) * 3):\n");
	int *a = (int *)ft_memalloc(sizeof(int) * 3);
	int i = 0;
	while (i < 3)
	{
		printf("\t%p:\t%d\n", &a[i], a[i]);
		i++;
	}
	free(a);
}

void	test_memdel(void)
{
	printf("=== Testing ft_memdel ===\n");
	int *a = (int *)malloc(sizeof(int) * 3);
	printf("\tBefore memdel:\n");
	printf("\ta = %p\n", a);
	ft_memdel((void **)&a);
	printf("\tAfter memdel:\n");
	printf("\ta = %p\n", a);
}


void	test_strnew(void)
{
	printf("=== Testing ft_strnew ===\n");
	char *str = ft_strnew(5);
	printf("\tft_strnew(5):\n");
	int i = 0;
	while (i < 5)
	{
		printf("\t%p:\t%d\n", &str[i], str[i]);
		i++;
	}
}


void	test_strdel(void)
{
	printf("=== Testing ft_strdel ===\n");
	char *str = (char *)malloc(sizeof(char) * 6);
	int i = 0;
	while (i < 5)
	{
		str[i] = i + '0';
		i++;
	}
	str[5] = '\0';
	printf("\tBefore strdel:\n");
	printf("\tstr='%s'\n", str);
	ft_strdel(&str);
	printf("\tAfter strdel:\n");
	printf("\tstr=%s\n", str);
}


void	test_strclr(void)
{
	printf("=== Testing ft_strclr ===\n");
	char *str = (char *)malloc(sizeof(char) * 6);
	int i = 0;
	while (i < 5)
	{
		str[i] = i + '0';
		i++;
	}
	str[5] = '\0';
	printf("\tBefore strclr:\n");
	i = 0;
	while (i < 6)
	{
		printf("\t%p:\t%d\n", &str[i], str[i]);
		i++;
	}
	ft_strclr(str);
	printf("\tAfter strclr:\n");
	i = 0;
	while (i < 6)
	{
		printf("\t%p:\t%d\n", &str[i], str[i]);
		i++;
	}
}

void	f(char *c)
{
	*c += 1;
}

void	test_striter(void)
{
	printf("=== Testing ft_striter ===\n");

	char str[] = "abc123";

	printf("str = '%s'\n", str);
	printf("Function 'f' shifts char forward by 1.\n");
	printf("striter(str, f)\n");
	ft_striter(str, f);
	printf("str = '%s'\n", str);
	ft_putchar('\n');
	
}

void	fi(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c += 1;
}

void	test_striteri(void)
{
	printf("=== Testing ft_striteri ===\n");

	char str[] = "abc123";

	printf("str = '%s'\n", str);
	printf("Function 'fi' shifts char forward by 1 if index is even.\n");
	printf("striteri(str, fi)\n");
	ft_striteri(str, fi);
	printf("str = '%s'\n", str);
	ft_putchar('\n');
	
}

char	f4map(char c)
{
	return (c + 2); 
}

void	test_strmap(void)
{
	printf("=== Testing ft_strmap ===\n");

	char str[] = "abc123";

	printf("str = '%s'\n", str);
	printf("f4map returns given charater incremented by 2\n");
	printf("new = strmap(str, f4map)\n");
	char *new = ft_strmap(str, f4map);
	printf("new = '%s'\n", new);
	ft_putchar('\n');
}

char	fi4map(unsigned int i, char c)
{
	if (i % 2 != 0)
		return (c + 2);
	return (c);
}

void	test_strmapi(void)
{
	printf("=== Testing ft_strmapi ===\n");

	char str[] = "abc123";

	printf("str = '%s'\n", str);
	printf("fi4map returns given charater incremented by 2 if index is odd\n");
	printf("new = strmapi(str, fi4map)\n");
	char *new = ft_strmapi(str, fi4map);
	printf("new = '%s'\n", new);
	ft_putchar('\n');
}


void	test_strequ(void)
{
	printf("=== Testing ft_strequ ===\n");
	char str1[] = "abc";
	char str2[] = "abc";

	printf("\tTest1 ");
	if (ft_strequ(str1, str2) == 1)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_2[] = "abc";
	char str2_2[] = "abcd";

	printf("\tTest2 ");
	if (ft_strequ(str1_2, str2_2) == 0)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_3[] = "abcd";
	char str2_3[] = "abc";

	printf("\tTest3 ");
	if (ft_strequ(str1_3, str2_3) == 0)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_4[] = "";
	char str2_4[] = "";

	printf("\tTest4 ");
	if (ft_strequ(str1_4, str2_4) == 1)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");
}


void	test_strnequ(void)
{
	printf("=== Testing ft_strnequ ===\n");
	char str1[] = "abcdef";
	char str2[] = "abcddddddddddd";

	printf("\tTest1 ");
	if (ft_strnequ(str1, str2, 3) == 1)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_2[] = "abcd\0a2523gkdj";
	char str2_2[] = "abcd\0feslgjwog";

	printf("\tTest2 ");
	if (ft_strnequ(str1_2, str2_2, 10) == 1)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_3[] = "abcd";
	char str2_3[] = "abc";

	printf("\tTest3 ");
	if (ft_strnequ(str1_3, str2_3, 4) == 0)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");

	char str1_4[] = "abc";
	char str2_4[] = "abc";

	printf("\tTest4 ");
	if (ft_strnequ(str1_4, str2_4, 0) == 1)
		printf("\tok\n");
	else
		printf("\tERROR\t\t!!!\n");
}


void	test_strsub(void)
{
	printf("=== Testing ft_strsub ===\n");
	char str[] = "Hello, world!";
	printf("str = '%s'\n", str);
	printf("new = ft_strsub(str, 2, 6)\n");
	char *new = ft_strsub(str, 2, 6);
	printf("new = '%s'\n", new);
	free(new);
	printf("\n");
}


void	test_strjoin(void)
{
	printf("=== Testing ft_strjoin ===\n");
	char s1[] = "hello";
	char s2[] = ", ";
	char s3[] = "world";
	printf("s1 = '%s', s2 = '%s', s3 = '%s'\n", s1, s2, s3);
	printf("a = ft_strjoin(s1, s2)\n");
	char *a = ft_strjoin(s1, s2);
	printf("a = '%s'\n", a);
	printf("b = ft_strjoin(a, s3)\n");
	char *b = ft_strjoin(a, s3);
	printf("b = '%s'\n", b);
	printf("\n");
	free(a);
	free(b);
}


void	test_strtrim(void)
{
	printf("=== Testing ft_strtrim ===\n");
	char str[] = " \t   string  \n  ";
	printf("str = '%s'\n", str);
	printf("new = ft_strtrim(str)\n");
	char *new = ft_strtrim(str);
	printf("new = '%s'\n", new);
	printf("\n");
}

void	test_strsplit(void)
{
	char **a;
	int i;
	
	printf("=== Testing ft_strsplit === (pls check for free(3))\n");
	char *str = "..af.1..b dd..";
	printf("str: '%s'\n", str);

	printf("ft_strsplit(str, '.')\n");
	a = ft_strsplit(str, '.');
	
	printf("\nnew array:\n\n");
	i = 0;
	while (a[i] != 0)
	{
		printf("%p\t%s\n", a[i], a[i]);
		i++;
	}
	char *str2 = "agjl bd jl  lasj";
	printf("\n\n\nstr2: '%s'\n", str2);

	printf("ft_strsplit(str2, ' ')\n");
	free(a);
	a = ft_strsplit(str2, ' ');
	
	printf("\nnew array:\n\n");
	i = 0;
	while (a[i] != 0)
	{
		printf("%p\t%s\n", a[i], a[i]);
		i++;
	}
	char *str3 = "???";
	printf("\n\n\nstr3: '%s'\n", str3);

	printf("ft_strsplit(str3, '?')\n");
	free(a);
	a = ft_strsplit(str3, '?');
	
	printf("\nnew array:\n\n");
	i = 0;
	while (a[i] != 0)
	{
		printf("%p\t%s\n", a[i], a[i]);
		i++;
	}
}


void	test_itoa(void)
{
	printf("=== Testing ft_itoa ===\n");

	
	int n = -10;
	while (n < 11)
		printf("%s\n", ft_itoa(n++));
	printf("test INT_MIN (should be -2147483648): %s\n", ft_itoa(INT_MIN));
	printf("test INT_MAX (should be 2147483647): %s\n", ft_itoa(INT_MAX));
	printf("\n");
}

void	test_putchar(void)
{
	printf("=== Testing ft_putchar ===\n");
	printf("ft_putchar('c'):\n");
	ft_putchar('c');
	printf("\n\n");
}


void	test_putstr(void)
{
	printf("=== Testing ft_putstr ===\n");
	printf("ft_putstr(\"string\\n\\n\\n\"):\n");
	ft_putstr("string\n\n\n");
}


void	test_putendl(void)
{
	printf("=== Testing ft_putendl ===\n");
	printf("ft_putendl(\"string\"):\n");
	ft_putendl("string");
}


void	test_putnbr(void)
{
	printf("=== Testing ft_putnbr === (pls check for malloc)\n");
	printf("ft_putnbr(40):\n");
	ft_putnbr(40);
	ft_putchar('\n');
	printf("ft_putnbr(INT_MIN):\n");
	ft_putnbr(INT_MIN);
	ft_putchar('\n');
	printf("ft_putnbr(INT_MAX):\n");
	ft_putnbr(INT_MAX);
	ft_putchar('\n');
	printf("ft_putnbr(0):\n");
	ft_putnbr(0);
	ft_putstr("\n");
}

void	test_fd(void)
{
	int fd = open("test_fd.txt", O_RDWR | O_CREAT | O_TRUNC,
				  S_IRUSR | S_IRGRP | S_IROTH | S_IWUSR | S_IWGRP | S_IWOTH);

	printf("=== Testing fd functions ===\n");
	printf("filename = \"test_fd.txt\", fd = %d\n", fd);
	printf("...\n");
	ft_putstr_fd("=== self-testing ft_putstr_fd ===\n", fd);
	ft_putstr_fd("=== Testing ft_putchar_fd ===\n", fd);
	ft_putchar_fd('c', fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("=== Testing ft_putendl_fd ===\n", fd);
	ft_putendl_fd("string", fd);
	ft_putstr_fd("=== Testing ft_putnbr_fd ===\n", fd);
	ft_putstr_fd("ft_putnbr_fd() from -20 to 20:\n", fd);
	int i = -20;
	while (i < 21)
	{
		ft_putnbr_fd(i, fd);
		ft_putchar_fd('\n', fd);
		i++;
	}
	ft_putstr_fd("ft_putnbr_fd(INT_MIN, fd):\n", fd);
	ft_putnbr_fd(INT_MIN, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("ft_putnbr_fd(INT_MAX, fd):\n", fd);
	ft_putnbr_fd(INT_MAX, fd);
	ft_putchar_fd('\n', fd);

	close(fd);
	printf("fd tests done.\n");
	
	printf("Please invoke 'cat test_fd.txt' to check fd tests\n\n");
}

void	lstshow(t_list *elem)
{
	printf("link: %s\n", (char *)elem->content);
}

t_list	*lstchange(t_list *elem)
{
	*((char *)elem->content) = '?';
	return (elem);
}

void	dellink(void *content, size_t size)
{
	if (size)
		free(content);
}

void	test_lst(void)
{
	t_list *lst;
	t_list *map;
	
	printf("=== Testing list funtions === \n");
	printf("Creating list of strings 'this', 'is', 'the' , 'test'.\n");
	printf("Using ft_lstnew() and ft_lstadd()\n");
	lst = ft_lstnew("test!", 6);
	ft_lstadd(&lst, ft_lstnew("the", 4));
	ft_lstadd(&lst, ft_lstnew("is", 3));
	ft_lstadd(&lst, ft_lstnew("this", 5));
	printf("Let's show the list using ft_lstiter():\n");
	printf("--Start--\n");
	ft_lstiter(lst, lstshow);
	printf("--END--\n");
	printf("Using ft_lstmap() to create new list\n");
	printf("Function applied will change first char to '?'\n");
	map = ft_lstmap(lst, lstchange);
	printf("Let's show new list using ft_lstiter():\n");
	printf("--Start--\n");
	ft_lstiter(map, lstshow);
	printf("--END--\n");
	printf("Delete last element using ft_lstdelone():\n");
	ft_lstdelone(&map->next->next->next, dellink);
	printf("Checking list using ft_lstiter():\n");
	printf("--Start--\n");
	ft_lstiter(map, lstshow);
	printf("--END--\n");
	printf("Delete from 2nd to end using ft_lstdel():\n");
	ft_lstdelone(&map->next, dellink);
	printf("Checking list using ft_lstiter():\n");
	printf("--Start--\n");
	ft_lstiter(map, lstshow);
	printf("--END--\n");
	
	printf("\n");
}


int		main(void)
{
	printf("====== PART 1 ======\n");
	
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strstr();
	test_strnstr();
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_toupper();
	test_tolower();
	
	printf("====== PART 2 ======\n");
	
	test_memalloc();
	test_memdel();
	test_strnew();
	test_strdel();
	test_strclr();
	test_striter();
	test_striteri();
	test_strmap();
	test_strmapi();
	test_strequ();
	test_strnequ();
	test_strsub();
	test_strjoin();
	test_strtrim();
	test_strsplit();
	test_itoa();
	test_putchar();
	test_putstr();
	test_putendl();
	test_putnbr();
	test_fd();

	printf("====== PART 3 ======\n");

	test_lst();
	
	printf ("done.\n");
}
