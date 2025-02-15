/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:38:55 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/11 15:44:26 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (ret);
}
/*
#include <stdio.h>

int main()
{
	char a[] = "Hello World!";
	char b = 'o';
	char *result;

	result = ft_strrchr(a, b);
	printf("%s\n", result);
	return (0);
}
*/
