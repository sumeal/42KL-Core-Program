/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:22:13 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/19 20:42:22 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	dst_len = 0;
	while (dst[dst_len] && dst_len < size)
		dst_len++;
	if (dst_len == size)
		return (dst_len + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len + i < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
	char a[50] = "Hello ";
	char c[50] = "Hello ";
	char b[] = "World";
	int	d;

	d = ft_strlcat(a, b, 3);
	printf("%s\n", a);
	printf("%d\n", d);
	
	d = ft_strlcat(c, b, 3);
	printf("%s\n", c);
	printf("%d\n", d);
	return (0);
}
*/
