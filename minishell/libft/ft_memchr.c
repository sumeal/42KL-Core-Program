/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:02:34 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:32 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1.searchs for the first occurrence of a sepcific charracter
	in a specified memory area, the argument c is the char;
	2.the return value is a pointer pointed to the first occurence
	of the byte c in the memory block s; not c return NULL; 
*/
#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = (const unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char) c)
			return ((void *)(ptr + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int main(void)
{
	void *result;

	result = ft_memchr("hello", 'o', 5);
	printf("%c\n", result);
}
*/