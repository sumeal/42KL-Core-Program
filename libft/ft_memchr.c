/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:58:18 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/15 14:22:56 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ret;

	ret = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ret[i] == (unsigned char)c)
			return ((void *)(ret + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

void	test_memchr(const void *s, int c, size_t n)
{
	void	*result_ft_memchr = ft_memchr(s, c, n);
	void	*result_memchr = memchr(s, c, n);
	printf("Testing with s = \"%s\", c = '%c'", (const char *)s, c);
	printf("n = %zu\n", n);

	printf("ft_memchr: %p\n", result_ft_memchr);
	printf("memchr: %p\n", result_memchr);

	if(result_ft_memchr == result_memchr)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");
	printf("\n");
}

int main()
{
	const char	*str = "hello world";

	test_memchr(str, 'o', 11);
	test_memchr(str, 'w', 11);
	test_memchr(str, 'z', 11);
	test_memchr(str, 'h', 0);
	test_memchr(str, 'h', 5);
	return (0);

}
*/
