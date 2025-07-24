/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:07:03 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 17:00:58 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

void	test_memcmp(const void *s1, const void *s2, size_t n)
{
	int	result_ft_memcmp = ft_memcmp(s1, s2, n);
	int	result_memcmp = memcmp(s1, s2, n);

	printf("Testing with s1 = \"%s\"", (const char *)s1);
	printf(", s2 = \"%s\", n = %zu\n", (const char *)s2, n);

	printf("ft_memcmp: %d\n", result_ft_memcmp);
	printf("memcmp: %d\n", result_memcmp);
	
	if (result_ft_memcmp == result_memcmp)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");
	printf("\n");
}

int main()
{
	const char *str1 = "abcdef";
	const char *str2 = "abcdeg";
	const char *str3 = "abcdef";

	test_memcmp(str1, str2, 6);
	test_memcmp(str1, str3, 6);
	test_memcmp(str1, str2, 5);
	test_memcmp(str2, str3, 6);
	return (0);
	
}
*/
