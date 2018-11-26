/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmelisan <gmelisan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:58:49 by gmelisan          #+#    #+#             */
/*   Updated: 2018/11/26 03:36:38 by gmelisan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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

/* void	test_strlcat(void) */
/* { */
/* 	int n1; */
/* 	int n2; */
/* 	char src[] = ", world!!!!"; /\* 11 chars *\/ */
/* 	printf("=== Testing ft_strlcat ===\n"); */

/* 	char str1[20] = "Hello"; 	/\* 5 chars *\/ */
/* 	char str2[20] = "Hello"; */

/* 	n1 = strlcat(str1, src, 0); */
/* 	n2 = ft_strlcat(str2, src, 0); */

/* 	printf("\tTest1 "); */
/* 	if (strcmp(str1, str2) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1, str2); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_2[20] = "Hello"; 	/\* 5 chars *\/ */
/* 	char str2_2[20] = "Hello"; */

/* 	n1 = strlcat(str1_2, src, 1); */
/* 	n2 = ft_strlcat(str2_2, src, 1); */

/* 	printf("\tTest2 "); */
/* 	if (strcmp(str1_2, str2_2) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_2, str2_2); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_3[20] = "Hello"; */
/* 	char str2_3[20] = "Hello"; */

/* 	n1 = strlcat(str1_3, src, 2); */
/* 	n2 = ft_strlcat(str2_3, src, 2); */

/* 	printf("\tTest3 "); */
/* 	if (strcmp(str1_3, str2_3) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_3, str2_3); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_4[20] = "Hello"; */
/* 	char str2_4[20] = "Hello"; */

/* 	n1 = strlcat(str1_4, src, 5); */
/* 	n2 = ft_strlcat(str2_4, src, 5); */

/* 	printf("\tTest4 "); */
/* 	if (strcmp(str1_4, str2_4) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_4, str2_4); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_5[20] = "Hello"; */
/* 	char str2_5[20] = "Hello"; */

/* 	n1 = strlcat(str1_5, src, 6); */
/* 	n2 = ft_strlcat(str2_5, src, 6); */

/* 	printf("\tTest5 "); */
/* 	if (strcmp(str1_5, str2_5) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_5, str2_5); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_6[20] = "Hello"; */
/* 	char str2_6[20] = "Hello"; */

/* 	n1 = strlcat(str1_6, src, 7); */
/* 	n2 = ft_strlcat(str2_6, src, 7); */

/* 	printf("\tTest6 "); */
/* 	if (strcmp(str1_6, str2_6) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_6, str2_6); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_7[20] = "Hello"; */
/* 	char str2_7[20] = "Hello"; */

/* 	n1 = strlcat(str1_7, src, 10); */
/* 	n2 = ft_strlcat(str2_7, src, 10); */

/* 	printf("\tTest7 "); */
/* 	if (strcmp(str1_7, str2_7) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_7, str2_7); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_8[20] = "Hello"; */
/* 	char str2_8[20] = "Hello"; */

/* 	n1 = strlcat(str1_8, src, 10); */
/* 	n2 = ft_strlcat(str2_8, src, 10); */

/* 	printf("\tTest8 "); */
/* 	if (strcmp(str1_8, str2_8) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_8, str2_8); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* 	char str1_9[20] = "Hello"; */
/* 	char str2_9[20] = "Hello"; */

/* 	/\* n1 = strlcat(str1_9, src, 20); *\/ */
/* 	/\* n2 = ft_strlcat(str2_9, src, 20); *\/ */

/* 	printf("\tTest9 "); */
/* 	if (strcmp(str1_9, str2_9) == 0 && n1 == n2) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\tstr1 = '%s'\n\tstr2 = '%s'\n", str1_9, str2_9); */
/* 		printf("\tn1 = %d, n2 = %d\n", n1, n2); */
/* 	} */
/* } */

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

/* void	test_strnstr(void) */
/* { */
/* 	char str[] = ".String contains substring in String"; */
/* 	char sub2[] = "String"; */
/* 	char *res1; */
/* 	char *res2; */

/* 	printf("=== Testing ft_strnstr ===\n"); */
/* 	res1 = strnstr(str, sub2, 10); */
/* 	res2 = ft_strnstr(str, sub2, 10); */
	
/* 	printf("\tTest1 "); */
/* 	if (strcmp(res1, res2) == 0) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\t'%s' !=\n\t'%s'\n", res1, res2); */
/* 	} */

/* 	res1 = strnstr(str, sub2, 3); */
/* 	res2 = ft_strnstr(str, sub2, 3); */
	
/* 	printf("\tTest2 "); */
/* 	if (res1 == NULL && res2 == NULL) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\t'%s' !=\n\t'%s'\n", res1, res2); */
/* 	} */
/* 	res1 = strnstr(str, sub2, 100); */
/* 	res2 = ft_strnstr(str, sub2, 100); */
	
/* 	printf("\tTest3 "); */
/* 	if (strcmp(res1, res2) == 0) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\t'%s' !=\n\t'%s'\n", res1, res2); */
/* 	} */

/* 	res1 = strnstr(str, sub2, 0); */
/* 	res2 = ft_strnstr(str, sub2, 0); */
	
/* 	printf("\tTest4 "); */
/* 	if (res1 == NULL && res2 == NULL) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\t'%s' !=\n\t'%s'\n", res1, res2); */
/* 	} */
/* 	res1 = strnstr(str, "", 10); */
/* 	res2 = ft_strnstr(str, "", 10); */
	
/* 	printf("\tTest5 "); */
/* 	if (strcmp(res1, res2) == 0) */
/* 	{ */
/* 		printf("ok\n"); */
/* 	} */
/* 	else */
/* 	{ */
/* 		printf("ERROR\t\t!!!\n"); */
/* 		printf("\t'%s' !=\n\t'%s'\n", res1, res2); */
/* 	} */
/* } */
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

void	test_strsplit(void)
{
	char **a;
	int i;
	
	printf("=== Testing ft_strsplit ===\n");
	char *str = "1..1..";
	printf("\nstr: \"%s\"\n\n", str);
	/* int i = 0; */
	/* while (i < ft_strlen(str)) */
	/* { */
	/* 	printf("%p\t%c\n", &str[i], str[i]); */
	/* 	i++; */
	/* } */

	a = ft_strsplit(str, '1');
	
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

	int n = -2;
	while (n < 3)
		printf("%s\n", ft_itoa(n++));
	
}

void	test_putnbr(void)
{
	printf("=== Testing ft_putnbr ===\n");

	ft_putnbr(-2147483648);
	ft_putchar('\n');
}



int		main(void)
{
	test_memset();
	test_bzero();
	test_memcpy();
	test_memccpy();
	/* test_memmove(); */
	test_memchr();
	test_memcmp();
	test_strlen();
	test_strdup();
	test_strcpy();
	test_strncpy();
	test_strcat();
	test_strncat();
	/* test_strlcat(); */
	test_strchr();
	test_strrchr();
	test_strstr();
	/* test_strnstr(); */
	test_strcmp();
	test_strncmp();
	test_atoi();
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	/* test_toupper(); */
	/* test_tolower();	 */

	test_memmove();

	test_strsplit();
	test_itoa();
	test_putnbr();
}
