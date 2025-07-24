/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:05:57 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:40 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 locates the last occurrence of a character in a string.
 searches the string from beginning to end
  but returns a pointer to the last occurrence found 
*/
#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ptr = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)ptr);
}
/*
#include <stdio.h>

int main()
{
	char *x;

	x = ft_strrchr("hello", 'l');
	printf("%s\n", x);
	return (0);
}
*/