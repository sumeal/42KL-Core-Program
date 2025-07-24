/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:25:22 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/15 15:34:49 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ret;

	ret = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ret[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
#include <string.h> // for the standard memset

void    test_memset(void *b1, void *b2, int c, size_t len)
{
    printf("Testing with char = '%c', len = %zu\n", (char)c, len);
    
    printf("Before ft_memset:\n");
    printf("b1: \"%s\"\n", (char *)b1);
    
    printf("Before memset:\n");
    printf("b2: \"%s\"\n", (char *)b2);

    ft_memset(b1, c, len);
    memset(b2, c, len);

    printf("After ft_memset:\n");
    printf("b1: \"%s\"\n", (char *)b1);
    
    printf("After memset:\n");
    printf("b2: \"%s\"\n", (char *)b2);

    if (memcmp(b1, b2, len) == 0)
        printf("Result: Match\n");
    else
        printf("Result: Mismatch\n");

    printf("------------------------\n");
}

int main(void)
{
    char b1[50];
    char b2[50];

    // Regular case
    strcpy(b1, "Hello, world!");
    strcpy(b2, "Hello, world!");
    test_memset(b1, b2, 'A', 5);

    // Entire string
    strcpy(b1, "Hello, world!");
    strcpy(b2, "Hello, world!");
    test_memset(b1, b2, 'B', 13);

    // Setting zero length
    strcpy(b1, "Hello, world!");
    strcpy(b2, "Hello, world!");
    test_memset(b1, b2, 'C', 0);

    // Setting the whole buffer
    strcpy(b1, "Hello, world!");
    strcpy(b2, "Hello, world!");
    test_memset(b1, b2, 'D', 50);

    // Source is NULL (should handle gracefully)
    char *src = NULL;
    test_memset(src, src, 'E', 0); // Should handle as len is 0

    return 0;
}
*/
