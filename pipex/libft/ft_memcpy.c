/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:36:58 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/20 14:50:00 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t					i;
	unsigned char			*d;
	unsigned const char		*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <string.h>
#include <stdio.h>

int main()
{
	char src[10] = "abcdef";
	char dest[10];
	char *a = NULL;
	char *b = NULL;

	memcpy(a, b, 5);
	ft_memcpy(dest, src, 5); // Should not modify dest
	printf("Dest: %s\n", dest); // Unchanged
}
*/
/*
#include <stdio.h>
#include <string.h> // for the standard memcpy 
void test_memcpy(void *dest1, void *dest2, const void *src, size_t n)
{ 
	ft_bzero(dest1, 50);
	ft_bzero(dest2, 50);
	
	ft_memcpy(dest1, src, n); 
	memcpy(dest2, src, n); 
	printf("Testing with src = \"%s\", n = %zu\n", (const char *)src, n); 
	printf("ft_memcpy: \"%s\"\n", (char *)dest1); 
	printf("memcpy: \"%s\"\n", (char *)dest2); 
	if (memcmp(dest1, dest2, n) == 0) 
		printf("Result: Match\n"); 
	else 
		printf("Result: Mismatch\n"); 
	printf("------------------------\n"); 
} 
int main(void) 
{ 
	char dest1[50]; 
	char dest2[50]; 
	// Regular case 
	const char *src1 = "Hello, world!"; 
	test_memcpy(dest1, dest2, src1, 60); 
	// Longer string 
	const char *src2 = "This is a longer string to test memcpy."; 
	test_memcpy(dest1, dest2, src2, 36); 
	// Empty string 
	const char *src3 = ""; 
	test_memcpy(dest1, dest2, src3, 0); 
	char overlap_src1[] = "1234567890"; 
	test_memcpy(overlap_src1 + 2, overlap_src1, overlap_src1, 5); // Zero length 
	const char *src4 = "Some data"; 
	test_memcpy(dest1, dest2, src4, 0); 
	// Source is NULL (should handle gracefully) 
	const char *src5 = NULL; 
	test_memcpy(dest1, dest2, src5, 0); // Should handle as n is 0 
	return 0; 
}
*/
