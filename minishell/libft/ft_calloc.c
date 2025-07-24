/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 10:01:45 by jchen2            #+#    #+#             */
/*   Updated: 2025/05/02 08:43:23 by abin-moh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	arr = malloc(nmemb * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		((unsigned char *)arr)[i] = '\0';
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*star;
	int		i;

	star = calloc(4, 5);
	i = 0;
	while (i < 20)
	{
		star[i] = 'H';
		i++;
	}
	printf("%s\n", star);
	star = ft_calloc(0, 3);
	printf("what happen: %s\n", star);
	return (0);
}
*/