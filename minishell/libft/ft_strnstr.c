/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:05:45 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:45:38 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
searches for a substring within the first n characters of a string. 
 limiting the search to a specified length
  helping prevent buffer overflows.
*/
#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == little[j])
		{
			j = 0;
			while (big[i + j] == little[j] && (i + j) < len)
			{
				j++;
				if (little[j] == '\0')
					return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*big = "hello world";
	const char *little = "hello world";

	printf("%s", ft_strnstr(big, little, 5));
}
*/