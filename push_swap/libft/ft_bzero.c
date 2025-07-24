/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:33:08 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/15 10:18:35 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>
#include <strings.h>

void	test_bzero(void *s1, void *s2, size_t n)
{
	ft_bzero(s1, n);
	bzero(s2, n);

	printf("Testing witn n = %zu\n", n);
	printf("ft_bzero: ");
	size_t i = 0;
	while (i < n)
	{
		printf("%02x ", ((unsigned char *)s1)[i]);
		i++;
	}
	printf("\n");
	printf("bzero: ");
	i = 0;
	while (i < n)
	{
		printf("%02x ", ((unsigned char *)s2)[i]);
		i++;
	}
	printf("\n");

	if (memcmp(s1, s2, n) == 0)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");

	printf("\n");
}
int main(void)
{
	char	s1[10] = "123456789";
	char	s2[10] = "123456789";

	test_bzero(s1, s2, 5);
	memcpy(s1, "123456789", 10);
	memcpy(s2, "123456789", 10);

	test_bzero(s1, s2, 0);
	memcpy(s1, "123456789", 10);
	memcpy(s2, "123456789", 10);

	test_bzero(s1, s2, 10);
	memcpy(s1, "123456789", 10);
	memcpy(s2, "123456789", 10);

	return (0);
}
*/