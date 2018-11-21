/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:49 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/21 21:43:49 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
		printf("ok\n");
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
		printf("ok\n");
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
		printf("ok\n");
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
int		main(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	test_memmove();
	test_memchr();
	test_memcmp(); // you know...
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
}
