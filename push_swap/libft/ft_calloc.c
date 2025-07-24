/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:35:32 by abin-moh          #+#    #+#             */
/*   Updated: 2024/11/16 18:38:15 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (!nmemb || !size)
	{
		ret = malloc(1);
		return (ret);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	ret = malloc(nmemb * size);
	if (!ret)
		return (NULL);
	ft_bzero(ret, nmemb * size);
	return (ret);
}
/*
#include <string.h>
#include <stdio.h>
#include <stdint.h>
int main()
{	
	printf("%s\n", calloc(SIZE_MAX, 2));
	//printf("next\n");
	//printf("%s\n", ft_calloc(SIZE_MAX, 2));
	return (0);

	
}


*/
/*
#include <string.h>
#include <stdio.h>

void	test_calloc(size_t nmemb, size_t size)
{
	void	*ptr_ft_calloc = ft_calloc(nmemb, size);
	void	*ptr_calloc = calloc(nmemb, size);

	if (ptr_ft_calloc == NULL || ptr_calloc == NULL)
	{
		printf("Memory allocation failed\n");
		return ;
	}

	printf("Testing with nmemb = %zu, size = %zu\n", nmemb, size);

	printf("ft_calloc: ");
	size_t	i = 0;
	while (i < nmemb * size)
	{
		printf("%02x ", ((unsigned char *)ptr_ft_calloc)[i]);
		i++;
	}
	printf("calloc: ");
	i = 0;
	while (i < nmemb * size)
	{
		printf("%02x ", ((unsigned char *)ptr_calloc)[i]);
		i++;
	}
	printf("\n");

	if (memcmp(ptr_ft_calloc, ptr_calloc, nmemb * size) == 0)
		printf("Result: Match\n");
	else
		printf("Result: Mismatch\n");
	printf("\n");
	free(ptr_ft_calloc);
	free(ptr_calloc);
}

int main()
{
	test_calloc(5, sizeof(int));
	test_calloc(10, sizeof(char));
	test_calloc(0, sizeof(int));
	test_calloc(5888888888888888888888888888888888, 0);
	test_calloc(0, 0);
	return (0);
}
*/
