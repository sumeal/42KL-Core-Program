/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:02:54 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:36 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	compare two blocks of memory, byte by byte;
	return the difference value;
*/
#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*pt1;
	const unsigned char	*pt2;
	size_t				i;

	pt1 = (const unsigned char *) s1;
	pt2 = (const unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
			return (pt1[i] - pt2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int main()
{
	int s = 133;
	int w = 123;
	
	printf("%d\n", ft_memcmp(&s, &w, 2));
	return (0);
}
*/