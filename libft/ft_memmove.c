/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:43:57 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/20 14:12:11 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d > s)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "Hello";

    //ft_memmove(NULL, NULL, 5);
    
    //memmove(NULL, NULL, 5);
}
*/
/*

#include <stdio.h>
#include <string.h> // for the standard memmove

void    test_memmove(void *dest1, void *dest2, const void *src, size_t n)
{
    ft_bzero(dest1, 50);
	ft_bzero(dest2, 50);
	
	ft_memmove(dest1, src, n);
    memmove(dest2, src, n);

    printf("Testing with src = \"%s\", n = %zu\n", (const char *)src, n);

    printf("ft_memmove: \"%s\"\n", (char *)dest1);
    printf("memmove: \"%s\"\n", (char *)dest2);

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
    test_memmove(dest1, dest2, src1, 13);

    // Longer string
    const char *src2 = "This is a longer string to test memmove.";
    test_memmove(dest1, dest2, src2, 36);

    // Empty string
    const char *src3 = "";
    test_memmove(dest1, dest2, src3, 0);

    // Overlapping memory - dest starts after src
    char overlap_src1[] = "1234567890";
    test_memmove(overlap_src1 + 2, overlap_src1, overlap_src1, 8);

    // Overlapping memory - dest starts before src
    char overlap_src2[] = "1234567890";
    test_memmove(overlap_src2, overlap_src2 + 2, overlap_src2, 8);

    // Zero length
    const char *src4 = "Some data";
    test_memmove(dest1, dest2, src4, 0);

    // Source is NULL (should handle gracefully)
    const char *src5 = NULL;
    test_memmove(dest1, dest2, src5, 0); // Should handle as n is 0

    return 0;
}
*/
