/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:03:29 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:44:40 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1.  copies n bytes from the memory block pointed to 
	by src to the memory block pointed to by dest.
	2. two blocks may overlap
*/
#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*de;
	const unsigned char	*sr;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	de = (unsigned char *) dest;
	sr = (const unsigned char *) src;
	if (de < sr)
		while (n--)
			*de++ = *sr++;
	else
	{
		i = n;
		while (i > 0)
		{
			de[i - 1] = sr[i - 1];
			i--;
		}
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
	char array[6] = "abcde";
	ft_memmove(array + 2, array, 4);
	printf("%s\n", array);
	return (0);
}
*/
